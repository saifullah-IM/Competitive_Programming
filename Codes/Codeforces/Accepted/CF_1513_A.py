from sys import stdin
input = stdin.readline
 
 
def main():
    test = int(input())
    for _ in range(test):
        n, k = map(int, input().split())
        if k > (n - 1) // 2:
            print('-1')
        else:
            ara = [0] * n
            take = n
            for i in range(k):
                ara[2 * i + 1] = take
                take -= 1
            for i in range(n):
                if ara[i] == 0:
                    ara[i] = take
                    take -= 1
            ans = ' '.join(map(str, ara))
            print(ans)
            
            
if __name__ == "__main__":
    main()