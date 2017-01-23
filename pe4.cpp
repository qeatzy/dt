#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

typedef std::vector<int> iVec;

using std::cout;

int largest_palidrome_of_two_number_of_n_digits(int ndigits) {
    auto is_palidrome = [](int x) { auto str = std::to_string(x); return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin()); };
    int upper_bound = pow(10, ndigits) - 1;
    int lower_bound = pow(10, ndigits-1);
    iVec candidates;
    for (int lhs = upper_bound; lhs>lower_bound; --lhs) {
        for (int rhs = upper_bound; rhs>lhs; --rhs) {
            auto prod = lhs * rhs;
            if(is_palidrome(prod))
                candidates.push_back(prod);
        }
    }
    return *std::max_element(candidates.begin(), candidates.end());
}


int main() {
    int ndigits = 3;
    cout << largest_palidrome_of_two_number_of_n_digits(ndigits);
}
