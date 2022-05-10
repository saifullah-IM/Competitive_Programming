from sys import stdin

input = stdin.readline


def main():
    test = 1
    for _ in range(test):
        n = int(input())
        ara = [int(x) for x in input().split()]
        ans = 0
        for mx in range(min(ara), max(ara) + 1):
            sum = 0
            for x in ara:
                sum += x
                if x > mx or sum < 0:
                    sum = 0
                    continue
                ans = max(ans, sum - mx)
        print(ans)


if __name__ == "__main__":
    main()