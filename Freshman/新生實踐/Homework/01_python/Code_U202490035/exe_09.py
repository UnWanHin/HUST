def is_perfect_number(n):

    sum_of_divisors = 0
    for i in range(1, n):
        if n % i == 0:
            sum_of_divisors += i
    return sum_of_divisors == n

perfect_numbers = []
for num in range(2, 10001):
    if is_perfect_number(num):
        perfect_numbers.append(num)

print("2 到 10000 之间的完数有：", perfect_numbers)