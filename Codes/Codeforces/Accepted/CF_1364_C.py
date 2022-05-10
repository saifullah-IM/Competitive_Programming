# avoiding using queue
def main():
    test = 1
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        mark = [True for _ in range(n + 1)]
        for num in ara:
            mark[num] = False

        take_from = []
        for index in range(n + 1):
            if mark[index]:
                take_from.append(index)

        ans = []
        ans.append(take_from[0])
        take_at = 1
        take_size = len(take_from)
        for index in range(1, n):
            if ara[index] != ara[index - 1]:
                ans.append(ara[index - 1])
            elif take_at < take_size:
                ans.append(take_from[take_at])
                take_at += 1
            else:
                ans.append(n + 1)

        ans = ' '.join(map(str, ans))
        print(ans)


if __name__ == "__main__":
    main()
