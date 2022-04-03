#!/bin/perl

sub fib {
    my ($n) = @_;

    if ($n <= 2) {
        return 1;
    }

    return fib($n - 1) + fib($n - 2);
}

foreach (1..10) {
    print "fib($_) = ", fib($_), "\n";
}
