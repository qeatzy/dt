from operator import mul, add
from math import sqrt

def is_prime(val):
    # val is prime iff (val%x != 0) for x in range(2,sqrt(val)).
    if val<2:
        return False
    for i in range(2, 1 + int(sqrt(val))):
        if val % i == 0:
            return False
    return True

