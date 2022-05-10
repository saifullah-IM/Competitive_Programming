import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        a, b, c, d = map(int, input().split())
        if a <= b:
            print(b)
        elif c <= d:
            print(-1)
        else:
            sleep = a - b
            x = c - d
            y = sleep // x
            if sleep % x > 0:
                y += 1
            ans = b + y * c
            print(ans)


if __name__ == "__main__":
    main()