// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.  https://projecteuler.net/problem=6
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <valarray>
#include "utility.h"

int diff_of_sum_of_square_vs_square_of_sum(int ulimit) {
    int sum_first = 0, square_first = 0;
    for(; ulimit > 0; --ulimit) {
        sum_first += ulimit;
        square_first += ulimit * ulimit;
    }
    return (sum_first * sum_first) - square_first;
}

int main() {
    int ulimit = 100;
    cout << diff_of_sum_of_square_vs_square_of_sum(ulimit);
}
