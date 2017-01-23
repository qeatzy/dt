// What is the 10 001st prime number?  https://projecteuler.net/problem=7
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <valarray>
#include "utility.h"

// class Prime;


int main() {
    Prime p;
    cout << "Nth prime is " << p.nth_prime(10001) << '\n';
}
