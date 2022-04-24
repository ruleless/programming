#!/bin/perl

use strict;
use warnings;

use Getopt::Long;

# tunables
my $help;

sub usage {
    die <<USAGE_END;
USAGE: $0 [options]
    -h, --help  display this help text and exit
USAGE_END
}

GetOptions (
    'help|h' => \$help,
) or usage();
$help && usage();
