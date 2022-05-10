def main():
    test = int(input())
    for _ in range(test):
        _ = int(input())
        ara = [int(num) for num in input().split()]
        ara.sort()
        ans = 1
        group_size = 0
        for num in ara:
            group_size += 1
            if ans + group_size > num:
                ans += group_size
                group_size = 0
        print(ans)


if __name__ == "__main__":
    main()
