n = int(input())
def hanoi(n, a, b, c):
    if n == 1:
        print(a, c)
    else:
        hanoi(n - 1, a, c, b)
        print(a, c)
        hanoi(n - 1, b, a, c)
s = 1
for i in range(n - 1):
    s = s * 2 + 1
print(s)
hanoi(n, 1, 2, 3)
