// right hand side
// 左值指的是能出现在运算符左侧的表达式；
// 右值则表示不能出现在运算符左侧的表达式。
// C++11中引入了右值引用移动语法
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

namespace rhs {

// remove_reference
template<typename _Tp>
struct remove_reference
{
    typedef _Tp type;
};

template<typename _Tp>
struct remove_reference<_Tp&>
{
    typedef _Tp type;
};

template<typename _Tp>
struct remove_reference<_Tp&&>
{
    typedef _Tp type;
};

template<typename _Tp>
constexpr typename remove_reference<_Tp>::type&& move(_Tp&& __t)
{
    return static_cast<typename remove_reference<_Tp>::type&&>(__t);
}

} // namespace rhs

static const int kMinSize = 10;
static const int kMaxSize = 20;

class RightHandSide
{
  public:
    RightHandSide(int n)
            :v_(NULL), n_(n)
    {
        v_ = (int *)malloc(sizeof(*v_) * n_);
        for (auto i = 0; i < n_; i++)
        {
            v_[i] = random() % 1024;
        }

        printf("%s(): %p\n", __func__, this);
    }

    virtual ~RightHandSide()
    {
        if (v_)
            free(v_);

        printf("%s(): %p\n", __func__, this);
    }

    RightHandSide(const RightHandSide &rhs)
    {
        size_t sz = sizeof(*rhs.v_) * rhs.n_;
        n_ = rhs.n_;
        v_ = (int *)malloc(sz);
        memcpy(v_, rhs.v_, sz);

        printf("%s(const RightHandSide &rhs): %p rhs: %p\n",
               __func__, this, &rhs);
    }

    RightHandSide &operator=(const RightHandSide &rhs)
    {
        size_t sz = sizeof(*rhs.v_) * rhs.n_;
        n_ = rhs.n_;
        v_ = (int *)malloc(sz);
        memcpy(v_, rhs.v_, sz);

        printf("%s(const RightHandSide &rhs): %p rhs: %p\n",
               __func__, this, &rhs);
    }

#if 1
    RightHandSide(RightHandSide &&rhs)
            :v_(rhs.v_), n_(rhs.n_)
    {
        rhs.v_ = NULL;
        rhs.n_ = 0;

        printf("%s(RightHandSide &&rhs): %p rhs: %p\n",
               __func__, this, &rhs);
    }

    RightHandSide &operator=(RightHandSide &&rhs)
    {
        v_ = rhs.v_;
        n_ = rhs.n_;
        rhs.v_ = NULL;
        rhs.n_ = 0;

        printf("%s(RightHandSide &&rhs): %p rhs: %p\n",
               __func__, this, &rhs);
    }
#endif

  private:
    int *v_;
    int n_;
};

int getn()
{
    return random() % (kMaxSize - kMinSize) + kMinSize;
}

RightHandSide foo(RightHandSide rhs)
{
    printf("enter %s\n", __func__);
    // RightHandSide test(rhs::move(rhs));
    RightHandSide test(rhs);
    printf("leaving %s ...\n", __func__);
    return test;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    RightHandSide rhs(getn());

    // 传参时会构造临时对象，
    // 而构造临时对象是不会调用移动语义版本的构造函数的，
    // 因为rhs不是右值，临时对象不能夺取其值
    RightHandSide rhs1 = foo(rhs);

    // 被优化为调用构造函数
    RightHandSide rhs2 = RightHandSide(getn());

    // 调用移动构造函数，rhs1的值被夺取
    RightHandSide rhs3 = (RightHandSide &&)rhs1;

    // 调用移动构造函数，rhs3的值被夺取
    RightHandSide rhs4(rhs::move(rhs3));

    // 调用移动语义的赋值运算符，临时对象的值被夺取
    rhs2 = RightHandSide(getn());
    printf("rhs:%p rhs1:%p rhs2:%p\n\trhs3:%p rhs4:%p\n",
           &rhs, &rhs1, &rhs2, &rhs3, &rhs4);
    return 0;
}
