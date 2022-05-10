import heapq

test = int(input())
for _ in range(0, test):
    n = int(input())
    ara = [0 for i in range(0, n)]
    subara = [(n * -1, 1)]
    heapq.heapify(subara)
    for itr in range(1, n + 1):
        k, l = heapq.heappop(subara)
        k = k * -1
        r = l + k - 1
        if k % 2 == 1:
            i = (l + r) // 2
        else:
            i = (l + r - 1) // 2
        ara[i - 1] = itr
        if i > l:
            heapq.heappush(subara, ((i - l) * -1, l))
        if i < r:
            heapq.heappush(subara, ((r - i) * -1, i + 1))
    ans = ' '.join(map(str, ara))
    print(ans)
