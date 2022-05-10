import sys

input = sys.stdin.readline


def sieve(m):
    isPrime = [True for _ in range(m)]
    primeDivisors = [[] for _ in range(m)]

    for num in range(2, m, 2):
        primeDivisors[num].append(2)

    for num in range(3, m, 2):
        if not isPrime[num]:
            continue
        for multiple in range(num, m, num):
            isPrime[multiple] = False
            primeDivisors[multiple].append(num)

    return primeDivisors


def main():
    mx = int(2e5 + 5)
    primeDivisors = sieve(mx)
    n = int(input())
    ara = [int(num) for num in input().split()]

    if n == 1:
        print(ara[0])
        return

    ans = 1
    for prime in set(primeDivisors[ara[0]] + primeDivisors[ara[1]]):
        firstMin = int(1e10)
        secondMin = int(1e10)

        for num in ara:
            exp = 0

            while num % prime == 0:
                exp += 1
                num /= prime

            if exp < firstMin:
                secondMin = firstMin
                firstMin = exp
            elif exp < secondMin:
                secondMin = exp

            if secondMin == 0:
                break

        for _ in range(secondMin):
            ans *= prime

    print(ans)


if __name__ == "__main__":
    main()
