#ifndef __MYTYPE_H__
#define __MYTYPE_H__

template <typename T>
struct Type2ID
{
    static const int ID = -1;
};

template <>
struct Type2ID<char>
{
    static const int ID = 1;
};

template <>
struct Type2ID<unsigned char>
{
    static const int ID = 2;
};

template <>
struct Type2ID<bool>
{
    static const int ID = 3;
};

template <>
struct Type2ID<short>
{
    static const int ID = 4;
};

template <>
struct Type2ID<unsigned short>
{
    static const int ID = 5;
};

template <>
struct Type2ID<int>
{
    static const int ID = 6;
};

template <>
struct Type2ID<unsigned int>
{
    static const int ID = 7;
};

template <>
struct Type2ID<long long>
{
    static const int ID = 8;
};

template <>
struct Type2ID<unsigned long long>
{
    static const int ID = 9;
};

#endif // __MYTYPE_H__
