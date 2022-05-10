from sys import stdin
input = stdin.readline
 
 
def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        ara.sort()
        ans = 0
        for num in ara:
            if num == ara[0]:
                ans = ans + 1
            else:
                break
        ans = n - ans
        print(ans)
 
if __name__ == "__main__":
    main()