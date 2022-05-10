from sys import stdin

input = stdin.readline

MX = int(2e5 + 5)
MOD = int(1e9 + 7)


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        if n == 1:
            ans = 'a'
        else:
            m = n // 2
            ans = 'a' * m
            ans += 'b'
            ans += 'a' * (m - 1)
            if n % 2 == 1:
                ans += 'c'
        print(ans)


if __name__ == "__main__":
    main()