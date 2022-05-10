def main():
    a, b, c, d = map(int, input().split())
    ans = 0
    for x in range(a, b + 1):
        k = max(c + 1 - x, b)
        p = min(d - c + 1, x)
        q = min(d - c + 1, x + k - c)
        ans += (p * (p + 1)) // 2 - (q * (q - 1)) // 2 + (c - k - p + q) * p
    print(ans)


if __name__ == "__main__":
    main()