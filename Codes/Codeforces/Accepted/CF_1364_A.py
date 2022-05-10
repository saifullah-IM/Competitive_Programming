def main():
    test = int(input())
    for _ in range(test):
        n, x = map(int, input().split())
        ara = [int(num) for num in input().split()]
        if sum(ara) % x != 0:
            print(n)
        else:
            left = n
            mod = 0
            for index in range(n):
                mod = (mod + ara[index]) % x
                if mod != 0:
                    left = index + 1
                    break

            right = n
            mod = 0
            for index in range(n - 1, -1, -1):
                mod = (mod + ara[index]) % x
                if mod != 0:
                    right = n - index
                    break

            ans = n - min(left, right)
            if ans == 0:
                ans = -1
            print(ans)


if __name__ == "__main__":
    main()
