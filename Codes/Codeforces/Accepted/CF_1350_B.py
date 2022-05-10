import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        arr = [int(x) for x in input().split()]

        ans = 1
        dp = [1 for i in range(0, n + 1)]
        for idx in range(n, 0, -1):
            temp = 0
            for nxt in range(idx + idx, n + 1, idx):
                if arr[idx - 1] < arr[nxt - 1]:
                    temp = max(temp, dp[nxt])
            dp[idx] = 1 + temp
            ans = max(ans, dp[idx])

        print(ans)


if __name__ == "__main__":
    main()
