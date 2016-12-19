# -*- coding: utf-8 -*-
# Find the largest palindrome made from the product of two 3-digit numbers.  The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.  https://projecteuler.net/problem=4

def largest_palidrome_of_two_number_of_m_and_n_digits(lhs, rhs):
    # bounded by smallest(lhs) * smallest(rhs) and largest(lhs) * largest(rhs)
    llower_bound, lupper_bound = (10**(lhs-1) + 1), (10**lhs - 1)
    rlower_bound, rupper_bound = (10**(rhs-1) + 1), (10**rhs - 1)
    # for left in range(lupper_bound, 
    raise NotImplementedError

def largest_palidrome_of_two_number_of_n_digits(ndigits):
    def first_largest_products_larger_than_threshold(ndigits):
        upper_bound = 10 ** ndigits - 1
        # lower_bound = 10 ** (ndigits-1)
        lower_bound = upper_bound - 10 ** (ndigits-1)
        odd_bit = True
        for x in range(upper_bound, lower_bound, -1):
            for y in range(upper_bound, x, -1):
                yield x*y
        return
    def is_palidrome(x):
        digits = str(x)
        return digits == digits[::-1]
    return max(x for x in first_largest_products_larger_than_threshold(ndigits) if is_palidrome(x))


print(max(x*y for x in xrange(100,1000)
    for y in xrange(100,x)
    if str(x*y) == str(x*y)[::-1]))

n = 3
print(largest_palidrome_of_two_number_of_n_digits(n))
