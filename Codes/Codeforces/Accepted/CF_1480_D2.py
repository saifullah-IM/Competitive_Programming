from sys import stdin
input = stdin.readline
 

def main():
    n = int(input())
    ara = [int(x) for x in input().split()]

    positions = [[] for i in range(n + 1)]
    for idx in range(n):
        positions[ara[idx]].append(idx)

    next_ara = [n] * (n + 1)
    for idx in range(n + 1):
        size = len(positions[idx])
        for jdx in range(size):
            if jdx < size - 1:
                next_ara[positions[idx][jdx]] = positions[idx][jdx + 1]
            else:
                next_ara[positions[idx][jdx]] = n
    
    ara.append(n + n)
    ones = [n]
    zeros = [n]
    ans = 0
    for idx in range(n):
        if ara[idx] == ara[ones[-1]] and ara[idx] == ara[zeros[-1]]:
            ones.append(idx)
        elif ara[idx] == ara[ones[-1]]:
            ones.append(idx)
        elif ara[idx] == ara[zeros[-1]]:
            zeros.append(idx)
        else:
            if next_ara[ones[-1]] > next_ara[zeros[-1]]:
                ones.append(idx)
                ans += 1
            else:
                zeros.append(idx)
                ans += 1
    print(ans)

 
if __name__ == "__main__":
    main()