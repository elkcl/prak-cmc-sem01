from random import randint

n = randint(1, 10)
l = list(range(1, n + 1))
m = randint(1, 10)
print(n, m)
for _ in range(m):
    b = randint(0, n - 2)
    c = randint(b + 1, n - 1)
    print(l[b], l[c])
    l = l[b:c+1] + l[:b] + l[c+1:]