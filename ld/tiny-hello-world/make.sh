#!/bin/bash


build()
{
    gcc -c -fno-builtin hello_world.c || exit 1
    ld -static -e entry hello_world.o -o a.out
}


clean()
{
    rm -f *.out *.o
}


case "$1" in
    clean)
        clean
    ;;

    *)
        build
    ;;
esac
