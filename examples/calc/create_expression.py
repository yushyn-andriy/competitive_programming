import random




for i in range(1000):
    a = random.randint(1, 1000)
    op = random.choice('+*/-')
    b = random.randint(1, 1000)
    print(a, op, b, end=' ')
    print('+', end=' ')
print(1)
