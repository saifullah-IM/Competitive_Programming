from sys import stdin
input = stdin.readline
 
 
def main():
    test = int(input())
    for _ in range(test):
        n, k = map(int, input().split())
        k = k - 1
        half = n // 2
        ans = (k + (n % 2) * (k // half)) % n + 1
        print(ans)


if __name__ == "__main__":
    main()