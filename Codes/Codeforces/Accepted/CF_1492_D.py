from sys import stdin
input = stdin.readline
 
 
def main():
    a, b, k = map(int, input().split())
    if b == 1 or a == 0:
        if k != 0:
            print('No')
            return
        else:
            x = ['1'] * b + ['0'] * a
            y = x.copy()
    else:
        if k > a + b - 2:
            print('No')
            return
        elif k <= a:
            x =  ['1'] * (b - 1) + ['0'] * (a - k)
            y = x.copy()
            x = x + ['1'] + ['0'] * k
            y = y + ['0'] * k + ['1']
        else:
            x = ['1'] * b + ['0'] * a
            y = x.copy()
            y[-k - 1] = '0'
            y[-1] = '1'
    x = ''.join(x)
    y = ''.join(y)
    print('Yes')
    print(x)
    print(y)

 
if __name__ == "__main__":
    main()