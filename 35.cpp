#include "utility.h"
// Circular primes
// https://projecteuler.net/problem=35
// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
// How many circular primes are there below one million?

class small_prime { // Sieve of Eratosthenes
    public:
        small_prime(size_t ulimit) : m_ulimit{ulimit} {
            init_table(ulimit);
        }
        bool is_prime(size_t n) { return m_table[n]; }
    private:
        size_t m_ulimit;
        std::vector<bool> m_table;
        void init_table(size_t ulimit) {
            m_table = std::vector<bool>(m_ulimit + 1, true);
            m_table[0] = m_table[1] = false;
            for (size_t i = 2, bound = sqrt(m_ulimit); i <= bound; ++i) {
                for (auto j = i*i, step = i; j < m_table.size(); j += step) {
                    m_table[j] = false;
                }
            }
        }
};

std::vector<int> all_rotations_except_self_possible_prime(int x) {
    assert(x > 0);
    // std::vector<int> res {x};
    std::vector<int> res;
    std::vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    for (auto x: digits) {
        if (x % 2 == 0 || x == 5) {
            return res;
        }
    }
    for (size_t i = 1; i < digits.size(); ++i) {
        std::rotate(digits.rbegin(), digits.rbegin() + 1, digits.rend());
        int tmp = 0;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            tmp = tmp * 10 + *it;
        }
        res.push_back(tmp);
    }
    return res;
}

int main() {
    // for (auto i: {197, 1379, 13579, 1234567}) {
    //     print(all_rotations_except_self_possible_prime(i));
    // }
    auto start = std::chrono::high_resolution_clock::now();
    small_prime prime(1e6);
    std::vector<int> res{2,3,5,7};
    for (int i = 11; i < 1e6; i += 2) {
        if (prime.is_prime(i)) {
            auto vec = all_rotations_except_self_possible_prime(i);
            if (!vec.empty()) {
                bool circular_prime = true;
                for (auto x: vec) {
                    if (!prime.is_prime(x)) {
                        circular_prime = false;
                    }
                }
                if (circular_prime) {
                    res.push_back(i);
                }
            }
        }
    }
    print(res);
    cout << "res.size() = " << res.size() << endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << diff.count() << " s\n";
}
