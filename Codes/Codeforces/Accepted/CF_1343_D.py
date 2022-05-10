import sys

input = sys.stdin.readline


def main():
    test = int(input())
    for _ in range(test):
        n, k = map(int, input().split())
        arr = [int(x) for x in input().split()]
        zeromove = [0 for i in range(2 * k + 2)]
        onemove = [0 for i in range(2 * k + 2)]

        for idx in range(0, n // 2):
            zeromove[arr[idx] + arr[n - idx - 1]] += 1
            left = min(arr[idx], arr[n - idx - 1]) + 1
            right = max(arr[idx], arr[n - idx - 1]) + k
            onemove[left] += 1
            onemove[right + 1] -= 1

        ans = n
        for pairsum in range(2, 2 * k + 1):
            onemove[pairsum] += onemove[pairsum - 1]
            zero = zeromove[pairsum]
            one = onemove[pairsum] - zero
            two = n // 2 - one - zero
            ans = min(ans, one + 2 * two)
            assert (one >= 0)
            assert (two >= 0)
            #print(f"pairsum {pairsum} zero {zero} one {one} two{two}")

        print(ans)


if __name__ == "__main__":
    main()
