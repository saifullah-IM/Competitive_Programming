from sys import stdin
input = stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        ara.sort()
        ans = -1
        for position in range(1, n):
            var = ara[0] ^ ara[position]
            current = []
            for index in range(n):
                current.append(var ^ ara[index])
            current.sort()
            for index in range(n):
                if ara[index] != current[index]:
                     break
            else:
                ans = var
                break
        print(ans)

if __name__ == "__main__":
    main()