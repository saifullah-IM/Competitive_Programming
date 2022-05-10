import math
import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        if n % 2 == 0:
            ans = 1 / math.tan(math.pi / (2 * n))
        else:
            ans = math.cos(math.pi / (4 * n)) / math.sin(math.pi / (2 * n))
        print("{:.10f}".format(ans))


if __name__ == "__main__":
    main()