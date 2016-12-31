#include "utility.h"
// Lexicographic permutations
// https://projecteuler.net/problem=24
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
// Answer: 2783915460

// std::vector<int> k_th_permutation(int n, int k) {   // return index, starting from zero. 1 <= k <= n!.
//     std::vector<int> factorials {1};
//     std::vector<int> indices = range(0,n);
//     int h = 1;
//     for (; h < n && k > factorials.back(); ++h) {
//         factorials.push_back(factorials.back() * h);
//     }
//     int *p = &indices[n-h], *pend = &indices[indices.size()];
//     while (k > 1) {
//         if (k == factorials[h]) {
//             std::reverse(p, pend);
//             break;
//         } else if (k <= factorials[h-1]) {
//         } else {
//             int offset = k / factorials[h-1];
//             int rem = k % factorials[h-1];
//             if (rem == 0) {
//                 --offset;
//                 k = factorials[h-1];
//             } else {
//                 k = rem;
//             }
//             std::rotate(p, p + offset,  p + offset + 1);
//         }
//         --h;
//         ++p;
//     }
//     print(indices, ' ', "indices");
//     return indices;
// }

std::vector<int> k_th_permutation(int n, int k) {   // return index, starting from zero. 1 <= k <= n!.
    std::vector<int> factorials {1};
    std::vector<int> indices = range(0,n);
    int h = 1;
    for (; h < n && k > factorials.back(); ++h) {
        factorials.push_back(factorials.back() * h);
    }
    int *p = &indices[n-h], *pend = &indices[indices.size()];
    --k;    // make k zero based, easier to handle edge cases.
    while (k > 0) {
        if (k == factorials[h] - 1) {
            std::reverse(p, pend);
            break;
        } else if (k < factorials[h-1]) {
        } else {
            int offset = k / factorials[h-1];
            k %= factorials[h-1];
            std::rotate(p, p + offset,  p + offset + 1);
        }
        --h;
        ++p;
    }
    print(indices, ' ', "indices");
    return indices;
}

int fact(int n) { // do overflow!!
    int res = 1;
    for (; n > 1; --n) {
        res *= n;
    }
    return res;
}

int main() {
    std::vector<int> indices = k_th_permutation(10,1e6);
    print(indices, 0);
    // print(indices);
}
