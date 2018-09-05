// right hand side
// 左值指的是能出现在运算符左侧的表达式；
// 右值则表示不能出现在运算符左侧的表达式。
// C++11中引入了右值引用移动语法
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

#if 0
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
    RightHandSide test(getn());
    printf("leaving %s ...\n", __func__);
    return test;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    RightHandSide rhs(getn());
    RightHandSide rhs1 = foo(rhs);
    RightHandSide rhs2 = RightHandSide(getn());
    rhs2 = RightHandSide(getn());
    printf("rhs:%p rhs1:%p rhs2:%p\n", &rhs, &rhs1, &rhs2);
    return 0;
}
