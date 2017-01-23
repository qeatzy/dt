#include "utility.h"
// 142913828922

class Prime;
int main() {
    int threshold = 2000000;
    auto p = Prime {threshold};
    auto primes = p.getall();
    // cout << primes[primes.size() - 1];
    // for(auto i: range(10)) cout << primes[i] << ' '; cout << '\n';
    cout << std::accumulate(primes.begin(), primes.end(), 0LL);
}
