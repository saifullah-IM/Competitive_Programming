from sys import stdin
from math import ceil

input = stdin.readline

MX = int(2e5 + 5)
MOD = int(1e9 + 7)


def main():
    test = int(input())
    for _ in range(test):
        n, a, b = map(int, input().split())
        ara = input()
        if b >= 0:
            ans = n * (a + b)
        else:
            cnt = 1
            last = ara[0]
            for ch in ara:
                if ch != last:
                    cnt += 1
                    last = ch
            move = 1 + ceil((cnt - 2) / 2)
            ans = n * a + move * b
        print(ans)


if __name__ == "__main__":
    main()