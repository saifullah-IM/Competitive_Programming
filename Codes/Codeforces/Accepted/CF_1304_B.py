def main():
    n, _ = map(int, input().split())
    string_list = []
    for _ in range(n):
        new_string = input()
        string_list.append(new_string)

    taken = [False for _ in range(n)]
    ans_list = []
    middle = ""
    index_one = 0
    for index_one in range(n):
        if taken[index_one]:
            continue
        string_one = string_list[index_one]
        for index_two in range(index_one + 1, n):
            string_two = string_list[index_two]
            if string_one == string_two[::-1]:
                taken[index_two] = True
                ans_list.insert(0, string_one)
                ans_list.append(string_two)
                break
        else:
            if string_one == string_one[::-1]:
                middle = string_one

    length = len(ans_list)
    if length == 0:
        ans = middle
    else:
        ans = ""
        for index in range(length):
            ans += ans_list[index]
            if index + 1 == length // 2:
                ans += middle

    print(len(ans))
    print(ans)


if __name__ == "__main__":
    main()
