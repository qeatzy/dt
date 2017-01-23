from utility import is_prime

n = 2000000
print(sum(x for x in range(n) if is_prime(x)))
