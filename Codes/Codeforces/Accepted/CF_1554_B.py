from sys import stdin

input = stdin.readline

MX = int(2e5 + 5)
MOD = int(1e9 + 7)


def main():
    test = int(input())
    for _ in range(test):
        n, k = map(int, input().split())
        ara = [int(x) for x in input().split()]
        idx = max(0, n - 2 * k)
        ans = -n * n
        for i in range(idx, n):
            for j in range(i + 1, n):
                temp = (i + 1) * (j + 1) - k * (ara[i] | ara[j])
                #print((i, j, temp))
                ans = max(ans, temp)
        print(ans)


if __name__ == "__main__":
    main()