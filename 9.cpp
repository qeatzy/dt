#include "utility.h"

int product_of_one_of_triplet_of_which_sum_of_square_equal_to(int threshold) {
    iVec res(3);
    // TODO, better filtering, functional rewrite(optional) -- write yet another
    // function/program to generate/express the logic of optimization.
    int a, b, c, alimit, blimit;
    alimit = threshold;
    for (a=1; a < alimit; ++a) {
        blimit = threshold - a;
        for (b=1; b < blimit; ++b) {
            c = threshold - a - b;
            if (a*a + b*b == c*c) {
                printf("sum of square is %d\n", a*a + b*b + c*c);
                cout << a << ' ' << b << ' ' << c << '\n';
                return a*b*c;
            }
        }
    }
    return -1;
}
// 200 375 425
// 31875000

int main() {
    int threshold = 1000;
    cout << product_of_one_of_triplet_of_which_sum_of_square_equal_to(threshold);
}
