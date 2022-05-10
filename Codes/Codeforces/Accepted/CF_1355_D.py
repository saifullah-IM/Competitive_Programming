import sys

input = sys.stdin.readline


def main():
    n, s = map(int, input().split())
    if n * 2 > s:
        print("NO")
    else:
        ara = [1 for i in range(n - 1)]
        ara.append(s - n + 1)
        ans = ' '.join(map(str, ara))
        print("YES")
        print(ans)
        print(n)


if __name__ == "__main__":
    main()