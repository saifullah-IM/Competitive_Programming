def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        num = input()
        ans1 = '1'
        ans2 = '1'
        for index in range(1, n):
            if num[index] == '1':
                ans1 += '1' + '0' * (n - index - 1)
                ans2 += '0' + num[index + 1:]
                break
            elif num[index] == '2':
                ans1 += '1'
                ans2 += '1'
            else:
                ans1 += '0'
                ans2 += '0'
        print(ans1)
        print(ans2)


if __name__ == "__main__":
    main()
