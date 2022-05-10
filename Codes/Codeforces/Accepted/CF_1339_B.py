import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        ara.sort()
        ans = []
        left = 0
        right = n - 1
        while left < right:
            ans.append(ara[left])
            ans.append(ara[right])
            left += 1
            right -= 1
        if left == right:
            ans.append(ara[left])
        ans.reverse()
        ans = ' '.join(map(str, ans))
        print(ans)


if __name__ == "__main__":
    main()
