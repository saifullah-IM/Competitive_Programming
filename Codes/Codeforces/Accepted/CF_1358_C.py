import sys
input = sys.stdin.readline

def main():
    test = int(input())
    for _ in range(test):
        x1, y1, x2, y2 = map(int, input().split())
        ans = (x2 - x1) * (y2 - y1) + 1
        print(ans)


if __name__ == "__main__":
    main()