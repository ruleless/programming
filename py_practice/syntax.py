# -*- coding: utf-8 -*-


# 运算符/表达式
def expression():
    # 算数运算符
    a = 10
    b = 3
    print("算数表达式：")
    print("%d + %d = %d" % (a, b, a + b))
    print("%d - %d = %d" % (a, b, a - b))
    print("%d * %d = %d" % (a, b, a * b))
    print("%d / %d = %lf" % (a, b, a / b))
    print("%lf / %d = %lf" % (a*1.0, b, a*1.0 / b))
    print("%lf // %d = %lf" % (a*1.0, b, a*1.0 // b))
    print("%d %% %d = %d" % (a, b, a % b))
    print("%d ** %d = %d" % (a, b, a ** b))

    # 赋值运算符
    print("赋值表达式支持：=, +=, -=, *=, /=, //=, %=, **=")
    
    # 关系运算符
    print("关系表达式：")
    print("%d > %d = %s" % (a, b, a > b))
    print("%d < %d = %s" % (a, b, a < b))
    print("%d == %d = %s" % (a, b, a == b))
    print("%d != %d = %s" % (a, b, a != b))
    print("%d >= %d = %s" % (a, b, a >= b))
    print("%d <= %d = %s" % (a, b, a <= b))

    # 逻辑运算符
    a = True
    b = False
    print("逻辑表达式：")
    print("%s and %s = %s" % (a, b, a and b))
    print("%s or %s = %s" % (a, b, a or b))
    print("not %s = %s" % (a, not a))

    # 位运算符
    a = 0x0001
    b = 0x0010
    print("位运算符：")
    print("0x%04x & 0x%04x = 0x%04x" % (a, b, a & b))
    print("0x%04x | 0x%04x = 0x%04x" % (a, b, a | b))
    print("0x%04x ^ 0x%04x = 0x%04x" % (a, b, a ^ b))
    print("~0 = %d" % (~0))
    print("1>>1 = %d" % (1 >> 1))
    print("1<<1 = %d" % (1 << 1))

    # 成员运算符
    a = 1
    b = [1, 2, 3]
    print("%d in %s = %s" % (a, b, a in b))
    print("%d not in %s = %s" % (a, b, a not in b))

    # 身份运算符
    a = [1, 2, 3]
    b = [1, 2, 3]
    print("%s is %s = %s" % (a, b, a is b))
    print("%s is not %s = %s" % (a, b, a is not b))


def main():
    expression()


if (__name__ == "__main__"):
    main()
