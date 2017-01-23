def product_of_one_of_triplet_of_which_sum_of_square_equal_to(threshold):
    for a in range(1, threshold):
        for b in range(1, threshold - a):
            c = threshold - a - b;
            if a*a + b*b == c*c:
                print a, b, c
                return a*b*c

threshold = 1000

print([a*b*(threshold - a - b) for a in range(1,threshold)
    for b in range(1,threshold - a)
    if a*a + b*b == (threshold - a - b) * (threshold - a - b)])

print(product_of_one_of_triplet_of_which_sum_of_square_equal_to(threshold))
