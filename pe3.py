# largest prime factor of 600851475143 . https://projecteuler.net/problem=3
from math import sqrt

def is_prime(val):
    # val is prime iff (val%x != 0) for x in range(2,sqrt(val)).
    if val<2:
        return False
    for i in range(2, 1 + int(sqrt(val))):
        if val % i == 0:
            return False
    return True

def smallest_prime_factor(val):
    for i in range(2, int(sqrt(val))):
        if val % i == 0:
            return i
    return val

def smallest_factor_and_larger_than(val, pre_start=1):
    # return value could be non-prime!!
    for i in range(1+pre_start, int(sqrt(val))):
        if val % i == 0:
            return i
    return val

def largest_prime_factor(val):
    # condition of returned value: 1. prime 2. factor of val
    factors = []
    factor = 1
    while True:
        factor = smallest_factor_and_larger_than(val, factor)
        factors.append(factor)
        if factor == val:
            break
        val /= factor
    res = max(filter(is_prime, factors))
    return res

val = 600851475143
print(largest_prime_factor(val))
