# sum even Fibonacci numbers up to 4 millions. https://projecteuler.net/problem=2
def fibonacci_numer():
    a, b = 1, 2
    while True:
        yield a
        a, b = b, a+b

def sum_of_even_fibonacci_number_up_to(ulimit):
    sum = 0
    fib = fibonacci_numer()
    while True:
        x = next(fib)
        if x > ulimit:
            break
        if (x%2) == 0:
            sum += x
    return sum

threshold = 4000000
print(sum_of_even_fibonacci_number_up_to(threshold))
