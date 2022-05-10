s, n = map(int, input().split())
dragon = []

for _ in range(n):
    x, y = map(int, input().split())
    dragon.append((x, y))

dragon.sort()

ans = True
for x, y in dragon:
    if (s > x):
        s += y
    else:
        ans = False
        break

if ans:
    print('YES')
else:
    print('NO')
