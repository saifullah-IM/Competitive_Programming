import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n, k = map(int, input().split())
        ara = [int(x) for x in input().split()]
        ara.append(-1)

        isK = False
        for num in ara:
            if num == k:
                isK = True
                break

        if n == 1:
            interval = True
        else:
            interval = False

        for idx in range(0, n - 1):
            if ara[idx] >= k:
                if ara[idx + 1] >= k or ara[idx + 2] >= k:
                    interval = True
                    break

        if isK and interval:
            print('yes')
        else:
            print('no')


if __name__ == "__main__":
    main()
