#!/bin/perl

use strict;
use warnings;

use List::Util qw(min max);

sub calc_leven_dist_by_dp {
    my ($s1_ref, $s2_ref, $i, $j, $dp_ref) = @_;

    if ($i == 0) {
        return $j;
    }
    if ($j == 0) {
        return $i;
    }

    if (defined($dp_ref->[$i][$j])) {
        return $dp_ref->[$i][$j];
    }

    my $d1 = calc_leven_dist_by_dp($s1_ref, $s2_ref, $i - 1, $j, $dp_ref);
    my $d2 = calc_leven_dist_by_dp($s1_ref, $s2_ref, $i, $j - 1, $dp_ref);
    my $d3 = calc_leven_dist_by_dp($s1_ref, $s2_ref, $i - 1, $j - 1, $dp_ref);
    my $chr_i = substr $$s1_ref, $i - 1, 1;
    my $chr_j = substr $$s2_ref, $j - 1, 1;

    $dp_ref->[$i][$j] = min($d1 + 1, $d2 + 1, $d3 + !($chr_i eq $chr_j));
    return $dp_ref->[$i][$j];
}

sub leven_dist {
    my ($s1, $s2) = @_;
    die unless defined($s1) and defined($s2);

    my @dp;
    return calc_leven_dist_by_dp \$s1, \$s2, length $s1, length $s2, \@dp;
}

sub similarity_of_str {
    my ($s1, $s2) = @_;
    die unless defined($s1) and defined($s2);

    my $max_len = max(length $s1, length $s2);
    if ($max_len == 0) {
        return 0;
    }

    my $dist = leven_dist($s1, $s2);
    return 1 - $dist / $max_len;
}

print similarity_of_str('a', 'a'), "\n";
print similarity_of_str('i am ok', 'i am not ok'), "\n";
print leven_dist(@ARGV), "\n";
