#include <iostream>


const class NullPtr
{
  public:
    // 强制类型转换
    template<class T>
    inline operator T*() const
    {
        std::cout<<__func__<<std::endl;
        return 0;
    }

    // 类成员函数指针类型转换
    template<class C, class T>
    inline operator T C::*() const
    {
        std::cout<<__func__<<std::endl;
        return 0;
    }

  private:
    void operator&() const;
} null_ptr = {};


int main(int argc, char *argv[])
{
    std::cout<<"test for nullptr ..."<<std::endl;
    int *p = null_ptr;
    std::cout<<"start to compaire ..."<<std::endl;
    if (!p) {
        std::cout<<"p is null"<<std::endl;
    }
    return 0;
}
