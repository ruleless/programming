# -*- coding: utf-8 -*-

import os


# expression support by python
def expression():
    # numeric operators
    a = 10
    b = 3
    print("numeric expression:")
    print("%d + %d = %d" % (a, b, a + b))
    print("%d - %d = %d" % (a, b, a - b))
    print("%d * %d = %d" % (a, b, a * b))
    print("%d / %d = %lf" % (a, b, a / b))
    print("%lf / %d = %lf" % (a*1.0, b, a*1.0 / b))
    print("%lf // %d = %lf" % (a*1.0, b, a*1.0 // b))
    print("%d %% %d = %d" % (a, b, a % b))
    print("%d ** %d = %d" % (a, b, a ** b))

    # bit operators
    a = 0x0001
    b = 0x0010
    print("bit operators")
    print("0x%04x & 0x%04x = 0x%04x" % (a, b, a & b))
    print("0x%04x | 0x%04x = 0x%04x" % (a, b, a | b))
    print("0x%04x ^ 0x%04x = 0x%04x" % (a, b, a ^ b))
    print("~0 = %d" % (~0))
    print("1>>1 = %d" % (1 >> 1))
    print("1<<1 = %d" % (1 << 1))
    
    # relational operators
    print("relational operators:")
    print("%d > %d = %s" % (a, b, a > b))
    print("%d < %d = %s" % (a, b, a < b))
    print("%d == %d = %s" % (a, b, a == b))
    print("%d != %d = %s" % (a, b, a != b))
    print("%d >= %d = %s" % (a, b, a >= b))
    print("%d <= %d = %s" % (a, b, a <= b))

    # logic operators
    a = True
    b = False
    print("logic operators:")
    print("%s and %s = %s" % (a, b, a and b))
    print("%s or %s = %s" % (a, b, a or b))
    print("not %s = %s" % (a, not a))

    # assignment operators
    print("assignment expression: =, +=, -=, *=, /=, //=, %=, **=")

    # member operators
    a = 1
    b = [1, 2, 3]
    print("member operators")
    print("%d in %s = %s" % (a, b, a in b))
    print("%d not in %s = %s" % (a, b, a not in b))

    # 'is a' operators
    a = [1, 2, 3]
    b = [1, 2, 3]
    print("'is a' operators")
    print("%s is %s = %s" % (a, b, a is b))
    print("%s is not %s = %s" % (a, b, a is not b))


# generator and iterator
def gen_iter():
    a = [x for x in range(10)]  # it's an iterable object
    print(a)

    a = (x for x in range(10))  # it's an iterator object
    b = []
    print(a)
    for x in a:
        b.append(x)
    print(b)


# redefine range as an generator which is more effecient
def xrange(n, s=0, step=1):
    i = s
    while (i < n):
        yield i
        i += step


# control flow
def control_flow():
    a = 1
    b = 2
    if (a > b):
        print("%d > %d" % (a, b))
    elif (a < b):
        print("%d < %d" % (a, b))
    else:
        print("%d == %d" % (a, b))

    print("'while loop'")
    n = 3
    while (n > 0):
        print(n)
        n -= 1
    print("'for loop'")
    for n in range(3):
        print(n)

    print(xrange(3))
    for n in xrange(3, -1, 1):
        print(n)


# list directory
def _dirtree_cb(arg, top, names):
    for filename in names:
        print(os.path.join(top, filename))

    
def dirtree(pathname):
    if (os.path.exists(pathname)):
        os.path.walk(pathname, _dirtree_cb, None)


# object oriented programing
class MyDirOp(object):

    def __init__(self):
        pass

    def dirtree(self, pathname, prefix="+"):
        if (not os.path.exists(pathname)):
            return

        print("%s%s" % (prefix, pathname))
        if (os.path.isdir(pathname)):
            for filename in os.listdir(pathname):
                self.dirtree(os.path.join(pathname, filename),
                             "%s--+" % prefix)


def main():
    print("")
    expression()
    
    print("")
    gen_iter()
    
    print("")
    control_flow()

    print("")
    dirtree(".")

    MyDirOp().dirtree(".")    


if (__name__ == "__main__"):
    main()
