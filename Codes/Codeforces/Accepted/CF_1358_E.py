from sys import stdin
input = stdin.readline


def main():
    test = 1
    for _ in range(test):
        n = int(input())
        ara = [int(num) for num in input().split()]
        x = int(input())
        n1 = len(ara)
        n2 = n - n1
        ara_sum = sum(ara) + n2 * x
        if ara_sum > 0:
            print(n)
        elif x >= 0:
            print(-1)
        else:
            ara = ara + [x] * n2
            prefix_sum = [0]
            for num in ara:
                prefix_sum.append(num + prefix_sum[-1])
            current_max = n * x
            for i in range(n1):
                current_max = max(current_max, prefix_sum[i] + x * (n - i))
                if current_max < prefix_sum[n] + x * (n - i):
                    print(n - i)
                    return
            print(-1)


if __name__ == "__main__":
    main()
