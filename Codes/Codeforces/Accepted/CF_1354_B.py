import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        string = input()
        length = len(string) - 1
        one = 3 * length
        two = one
        three = one
        ans = one
        for idx in range(0, length):
            char = string[idx]
            if char == '1':
                one = idx
            elif char == '2':
                two = idx
            else:
                three = idx
            l = min(one, min(two, three))
            r = max(one, max(two, three))
            ans = min(ans, r - l + 1)
            idx += 1
        if ans > length:
            ans = 0
        print(ans)


if __name__ == "__main__":
    main()