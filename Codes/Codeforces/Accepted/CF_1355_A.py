import sys

input = sys.stdin.readline


def findDigits(x):
    a = 0
    b = 10
    while x > 0:
        c = x % 10
        a = max(a, c)
        b = min(b, c)
        x = x // 10
    return (a, b)


def main():
    test = int(input())
    for _ in range(test):
        a, k = map(int, input().split())
        ans = [a]
        idx = 0
        while True:
            x, y = findDigits(ans[idx])
            ans.append(ans[idx] + x * y)
            idx += 1
            if y == 0:
                break
        length = len(ans)
        if k > length:
            print(ans[length - 1])
        else:
            print(ans[k - 1])


if __name__ == "__main__":
    main()