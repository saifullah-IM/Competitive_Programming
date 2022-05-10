import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        ara.sort()
        ans = 0
        length = 0
        for num in ara:
            if num <= length + 1:
                ans += 1
                length = 0
            else:
                length += 1
        print(ans)


if __name__ == "__main__":
    main()