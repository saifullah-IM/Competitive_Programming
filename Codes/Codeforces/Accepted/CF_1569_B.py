from sys import stdin

input = stdin.readline

MX = int(2e5 + 5)
MOD = int(1e9 + 7)


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        expectations = list(input())
        twos = []
        for i in range(n):
            if expectations[i] == '2':
                twos.append(i)
        m = len(twos)
        if m == 2 or m == 1:
            print("NO")
        else:
            print("YES")
            ans = [[' ' for i in range(n)] for j in range(n)]
            for i in range(n):
                ans[i][i] = 'X'
            if m > 2:
                for i in range(m):
                    ans[twos[i]][twos[i - 1]] = '+'
                    ans[twos[i - 1]][twos[i]] = '-'
            for i in range(n):
                for j in range(n):
                    if ans[i][j] == ' ':
                        ans[i][j] = '='
                print(''.join(ans[i]))


if __name__ == "__main__":
    main()