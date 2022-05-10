import math
import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n, k = map(int, input().split())
        root = math.floor(math.sqrt(n)) + 1
        ans = n
        for div in range(2, root):
            if n % div == 0:
                ans += div
                break
        if ans == n:
            ans += n
        ans += 2 * (k - 1)
        print(ans)


if __name__ == "__main__":
    main()
