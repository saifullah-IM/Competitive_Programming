from math import ceil


def main():
    test = int(input())
    for _ in range(test):
        n, m = map(int, input().split())
        ans = ceil((m * n) / 2)
        print(ans)


if __name__ == "__main__":
    main()
