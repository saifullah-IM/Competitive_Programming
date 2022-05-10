import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n, k = map(int, input().split())
        ara = input()
        total = 0
        for i in range(n):
            total += int(ara[i] == '1')
        ans = total
        for i in range(k):
            dif = 0
            for j in range(i, n, k):
                if ara[j] == '1':
                    dif += 1
                else:
                    dif -= 1
                dif = max(dif, 0)
                ans = min(ans, total - dif)
        print(ans)


if __name__ == "__main__":
    main()
