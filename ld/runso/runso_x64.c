#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


#define PUSH_ARG_REGS                           \
    do {                                        \
        __asm__("push %r9\n\t"                  \
                "push %r8\n\t"                  \
                "push %rcx\n\t"                 \
                "push %rdx\n\t"                 \
                "push %rsi\n\t"                 \
                "push %rdi"                     \
                );                              \
    } while (0);

#define POP_ARG_REGS                            \
    do {                                        \
        __asm__("pop %rdi\n\t"                  \
                "pop %rsi\n\t"                  \
                "pop %rdx\n\t"                  \
                "pop %rcx\n\t"                  \
                "pop %r8\n\t"                   \
                "pop %r9"                       \
                );                              \
    } while (0);


#define SETUP_STACK                                             \
    do {                                                        \
        __asm__ __volatile__("mov %rsp, %rbx");                 \
                                                                \
        int i = 4;                                              \
        while (i < argc) {                                      \
            switch (argv[i][0]) {                               \
            case 'i':                                           \
                __asm__ __volatile__("mov %0, (%%rbx)\n\t"      \
                                     "add $8, %%rbx"            \
                                     :                          \
                                     : "a"(atoi(&argv[i][1]))   \
                                     );                         \
                break;                                          \
                                                                \
            case 'd':                                           \
                atof(&argv[i][1]);                              \
                __asm__ __volatile__("sub $8, %rsp\n\t"         \
                                     "fstpl (%rsp)"             \
                                     );                         \
                esp += 8;                                       \
                break;                                          \
                                                                \
            case 's':                                           \
                __asm__ __volatile__("push %0"                  \
                                     :                          \
                                     : "r"(&argv[i][1]));       \
                esp += 8;                                       \
                break;                                          \
                                                                \
            default:                                            \
                fprintf(stderr, "Invalid argument type: %s\n",  \
                        argv[i]);                               \
                goto err;                                       \
            }                                                   \
                                                                \
            ++i;                                                \
        }                                                       \
    } while (0);


#define RESTORE_STACK                           \
    do {                                        \
        __asm__ __volatile__("add %0, %%rsp"    \
                             :                  \
                             : "r"(esp)         \
                             );                 \
    } while (0)


int main(int argc, char *argv[])
{
    int rv = 0;

    if (argc < 4) {
        fprintf(stderr,
                "Invalid argument!\n"
                "runso so_path function_name return_type(int/double/void/string) arguments_type...\n");
        exit(1);
    }

    void *handle = dlopen(argv[1], RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "Can't find '%s'\n", argv[1]);
        rv = 1;
        goto err;
    }

    void *func = dlsym(handle, argv[2]);
    if (!func) {
        fprintf(stderr, "Can't find sysmbol '%s' in '%s'\n", argv[2], argv[1]);
        rv = 1;
        goto err;
    }

    const char *return_type = argv[3];
    switch (return_type[0]) {
    case 'i': // int
        {
            int (*func_decl)() = func;
            long esp = 0;

            PUSH_ARG_REGS;
            SETUP_STACK;
            POP_ARG_REGS;

            int ret = func_decl();
            RESTORE_STACK;

            fprintf(stdout, "return %d\n", ret);
        }
        break;

    case 'd': // double
        {
            double (*func_decl)() = func;
            long esp = 0;

            SETUP_STACK;
            double ret = func_decl();
            RESTORE_STACK;

            fprintf(stdout, "return %lf\n", ret);
        }
        break;

    case 's': // string
        {
            char * (*func_decl)() = func;
            long esp = 0;

            SETUP_STACK;
            char *ret = func_decl();
            RESTORE_STACK;

            fprintf(stdout, "return %s\n", ret);
        }
        break;

    case 'v': // void
        {
            void (*func_decl)() = func;
            long esp = 0;

            SETUP_STACK;
            func_decl();
            RESTORE_STACK;

            fprintf(stdout, "return void\n");
        }
        break;

    default:
        fprintf(stderr, "Invalid return type: %s\n", return_type);
        break;
    }

err:
    if (handle) {
        dlclose(handle);
    }

    exit(rv);
}
