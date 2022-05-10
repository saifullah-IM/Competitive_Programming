from math import fabs


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        if n == 2:
            ans = ara
        else:
            ans = []
            ans.append(ara[0])
            left = 0
            mid = 1
            right = 2
            while right < n:
                if fabs(ara[left] - ara[mid]) + fabs(
                        ara[mid] - ara[right]) > fabs(ara[left] - ara[right]):
                    ans.append(ara[mid])
                    left = mid
                mid = right
                right += 1
            ans.append(ara[mid])

        print(len(ans))
        ans = ' '.join(map(str, ans))
        print(ans)


if __name__ == "__main__":
    main()
