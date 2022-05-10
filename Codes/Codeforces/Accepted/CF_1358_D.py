import sys

input = sys.stdin.readline


def sum_upto_n(n):
    return (n * (n + 1)) // 2


def main():
    test = 1
    for _ in range(test):
        n, x = map(int, input().split())
        ara = [int(num) for num in input().split()]
        ara = ara * 2

        days = x
        hugs = 0
        ans = 0
        right = 2 * n - 1
        left = 2 * n - 1
        while right >= n:
            while ara[left] < days:
                hugs += sum_upto_n(ara[left])
                days -= ara[left]
                left -= 1

            ans = max(
                ans,
                hugs + sum_upto_n(ara[left]) - sum_upto_n(ara[left] - days))

            if left != right:
                days += ara[right]
                hugs -= sum_upto_n(ara[right])
                right -= 1
            else:
                left -= 1
                right -= 1

        print(ans)


if __name__ == "__main__":
    main()
