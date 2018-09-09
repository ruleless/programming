#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

template <typename Predicate, typename T>
static inline void func(Predicate pred, T head) {
    pred(head);
}

template <typename Predicate, typename T, typename... TAIL>
static inline void func(Predicate pred, T head, TAIL... tail) {
    pred(head);
    func(pred, tail...);
}

int main(int argc, char *argv[])
{
    func([](const char *s) {
            std::cout<<s<<" ";
        },
        "a",
        "b",
        "c",
        "d");
    std::cout<<std::endl;
    return 0;
}
