from functools import reduce
from sys import stdin
input = stdin.readline
 
 
def main():
    MOD = int(1e9 + 7)
    test = int(input())
    for _ in range(test):
        n = int(input())
        ara = [int(x) for x in input().split()]
        all_and = reduce((lambda x, y : x & y), ara)
        count = 0
        for num in ara:
            if num == all_and:
                count += 1
        ans = (count * (count - 1)) % MOD
        for i in range(n - 2):
            ans = (ans * (i + 1)) % MOD
        print(ans)


if __name__ == "__main__":
    main()