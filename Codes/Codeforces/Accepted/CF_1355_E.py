def solve_for_height(n, add_cost, remove_cost, move_cost, current_height,
                     heights, cum_heights):
    lo = 1
    hi = n
    while (lo <= hi):
        mid = (lo + hi) // 2
        if heights[mid] <= current_height:
            lo = mid + 1
        else:
            hi = mid - 1

    add = (lo - 1) * current_height - cum_heights[lo - 1]
    remove = cum_heights[n] - cum_heights[lo -
                                          1] - (n - lo + 1) * current_height

    if (add > remove):
        ans = (add - remove) * add_cost + remove * move_cost
    else:
        ans = (remove - add) * remove_cost + add * move_cost

    return ans


def main():
    n, add_cost, remove_cost, move_cost = map(int, input().split())
    move_cost = min(add_cost + remove_cost, move_cost)
    heights = [int(h) for h in input().split()]
    heights.sort()
    heights.insert(0, 0)
    cum_heights = [0]
    for index in range(1, n + 1):
        cum_heights.append(cum_heights[index - 1] + heights[index])

    lo = 0
    hi = heights[n]
    ans = cum_heights[n] * remove_cost
    while (lo <= hi):
        mid1 = (lo + lo + hi) // 3
        mid2 = (lo + hi + hi) // 3
        cost1 = solve_for_height(n, add_cost, remove_cost, move_cost, mid1,
                                 heights, cum_heights)
        cost2 = solve_for_height(n, add_cost, remove_cost, move_cost, mid2,
                                 heights, cum_heights)

        ans = min(ans, min(cost1, cost2))
        if (cost1 < cost2):
            hi = mid2 - 1
        else:
            lo = mid1 + 1

    print(ans)


if __name__ == "__main__":
    main()
