test = int(input())
for _ in range(0, test):
    n, k = map(int, input().split())
    a = [int(num) for num in input().split()]
    b = [int(num) for num in input().split()]
    a.sort()
    b.sort()
    for idx in range(0, min(n, k)):
        if a[idx] < b[n - idx - 1]:
            a[idx], b[n - idx - 1] = b[n - idx - 1], a[idx]
        else:
            break
    print(sum(a))