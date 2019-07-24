#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

template <int X>
struct Fibonacci
{
    static const int N = Fibonacci<X - 2>::N + Fibonacci<X - 1>::N;
};

template <>
struct Fibonacci<0>
{
    static const int N = 0;
};

template <>
struct Fibonacci<1>
{
    static const int N = 1;
};

#endif // __FIBONACCI_H__
