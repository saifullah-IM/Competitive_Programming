from sys import stdin
from math import ceil

input = stdin.readline


MX = int(2e5 + 5)
MOD = int(1e9 + 7)


def main():
    test = int(input())
    for _ in range(test):
        n, m, k = map(int, input().split())
        x = min(m, n // k)
        y = ceil((m - x) / (k - 1))
        print(x - y)


if __name__ == "__main__":
    main()
