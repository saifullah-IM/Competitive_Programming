import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        if n % 4 != 0:
            print("NO")
            continue
        ara = [0] * n
        for i in range(n // 2):
            ara[i] = (i + 1) * 2
            ara[i + n // 2] = ara[i] - 1
        ara[n - 1] += n // 2
        print("YES")
        ans = ' '.join(map(str, ara))
        print(ans)


if __name__ == "__main__":
    main()
