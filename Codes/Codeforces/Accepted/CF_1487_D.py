import math
from sys import stdin
input = stdin.readline
 
 
def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        k = math.floor(math.sqrt(2*n - 1))
        ans = (k - 1) // 2
        print(ans)

 
if __name__ == "__main__":
    main()