#include "utility.h"
// Number spiral diagonals
// https://projecteuler.net/problem=28
// Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
// It can be verified that the sum of the numbers on the diagonals is 101.
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

int sum_diagonal_of_spiral_square(int width) {
    assert(width > 0 && width % 2 ==1);
    int res = 1;
    for (; width > 1; width -= 2) {
        res += 4 * width*width - 6 * (width-1);
    }
    return res;
}

int main() {
    int width = 1001;
    long long result = sum_diagonal_of_spiral_square(width);
    cout << result;
}
