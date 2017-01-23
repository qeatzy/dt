// sum even Fibonacci numbers up to 4 millions. https://projecteuler.net/problem=2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>

typedef std::vector<int> iVec;

using std::cout;

iVec range(int start, int stop, int step) {
    /* generate a sequence.
     * step must **NOT** be zero.
     * TODO: refactor to generic to allow double parameters. Or restrict range to int, use
     * linspace for double instead?
     */
    // static_assert(step != 0, "step must **NOT** be zero.");
    auto cmp = (step>0) ? [](int left, int right) { return left < right; }
                        : [](int left, int right) { return left > right; };
    iVec res;
    while(cmp(start, stop)) {
        res.push_back(start);
        start += step;
    }
    return res;
}

iVec range(int start) {
    return range(0, start, 1);
}

iVec range(int start, int stop) {
    return range(start, stop, 1);
}

int sum_of_fibonacci_number_up_to(int threshold) {
    /* be aware of overflow concerns!
     */
    int res = 0;
    int b1 = 1, b2 = 2;
    // auto fib = [=]() { int tmp = b1; b2 += b1; b1 = b2 - b1; return tmp; };
    // auto fib = [=b1, =b2]() { int tmp = b1; b2 += b1; b1 = b2 - b1; return tmp; };
    auto fib = [&b1, &b2]() { int tmp = b1; b2 += b1; b1 = b2 - b1; return tmp; };
    // for(auto i: {1,2,3,4,5}) {

    int tmp;
    while((tmp = fib()) <= threshold) {
        if (tmp%2 == 0) {
            res += tmp;
        }
    }

    return res;
}

int main() {
    int threshold = 4000000;
    int res = sum_of_fibonacci_number_up_to(threshold);
    cout << res;
}
