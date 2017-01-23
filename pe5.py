# smallest positive number that is evenly divisible by all of the numbers from 1 to 20?  https://projecteuler.net/problem=5
from operator import mul
from math import sqrt

def is_prime(val):
    # val is prime iff (val%x != 0) for x in range(2,sqrt(val)).
    if val<2:
        return False
    for i in range(2, 1 + int(sqrt(val))):
        if val % i == 0:
            return False
    return True

def raise_to_lagest_power_upto_20(x):
    res = x
    while res*x <= 20:
        res *= x
    return res

res = reduce(mul, map(raise_to_lagest_power_upto_20, filter(is_prime, range(2,21))))
print(res)
