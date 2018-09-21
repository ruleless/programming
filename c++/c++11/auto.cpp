#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>

void test_auto() {
    std::vector<int> v;

    srand(time(NULL));

    int n = random() % 5 + 5;
    for (auto i = 0; i < n; i++) {
        v.push_back(random() % 100);
    }

    auto i = v.begin();
    for (; i != v.end(); i++) {
        printf("%d ", *i);
    }
    puts("");
}

int main(int argc, char *argv[]) {
    test_auto();
    exit(0);
}
