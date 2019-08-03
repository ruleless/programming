const char *HELLO_WORLD = "hello world\n";


void print()
{
    __asm__ __volatile__("movl $4, %%eax\n\t"
                         "movl $1, %%ebx\n\t"
                         "movl %0, %%ecx\n\t"
                         "movl $12, %%edx\n\t"
                         "int $0x80"
                         :
                         : "m"(HELLO_WORLD)
                         : "%eax", "%ebx", "%ecx", "%edx");
}


void exit()
{
    __asm__ __volatile__("movl $1, %%eax\n\t"
                         "movl $42, %%ebx\n\t"
                         "int $0x80"
                         ::
                         : "%eax", "%ebx");
}


void entry()
{
    print();
    exit();
}
