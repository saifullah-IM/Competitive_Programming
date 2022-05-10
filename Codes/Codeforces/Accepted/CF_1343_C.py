import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        if ara[0] < 0:
            sign = -1
        else:
            sign = 1
        ans = 0
        current = ara[0]
        for num in ara:
            if num * sign > 0:
                current = max(current, num)
            else:
                sign *= -1
                ans += current
                current = num
        ans += current
        print(ans)


if __name__ == "__main__":
    main()