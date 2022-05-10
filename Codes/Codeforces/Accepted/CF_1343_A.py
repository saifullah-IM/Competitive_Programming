import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        k = 4
        while True:
            if n % (k - 1) == 0:
                print(n // (k - 1))
                break
            k *= 2


if __name__ == "__main__":
    main()
