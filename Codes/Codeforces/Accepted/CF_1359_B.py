from sys import stdin

input = stdin.readline


MX = int(2e5 + 5)
MOD = int(1e9 + 7)


def main():
    test = int(input())
    for _ in range(test):
        n, m, x, y = map(int, input().split())
        ans = 0
        for _ in range(n):
            row = input()
            last = "*"
            for ch in row:
                if ch == ".":
                    if last == ".":
                        ans -= x
                        ans += min(2 * x, y)
                        last = "*"
                    else:
                        ans += x
                        last = "."
                else:
                    last = "*"
        print(ans)


if __name__ == "__main__":
    main()
