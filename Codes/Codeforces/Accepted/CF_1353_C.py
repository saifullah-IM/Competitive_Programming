test = int(input())
for _ in range(0, test):
    n = int(input())
    k = (n - 1) // 2
    ans = 8 * ((k * (k + 1) * (2 * k + 1)) // 6)
    print(ans)