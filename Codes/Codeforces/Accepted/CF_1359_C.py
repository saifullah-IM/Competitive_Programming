from math import floor
from sys import stdin
input = stdin.readline


def compare_answer(hot, cold, target, moves, ans):
    min_temperature = (ans // 2) * (hot + cold) + (ans % 2) * hot
    min_error = abs(min_temperature - ans * target) * moves
    temperature = (moves // 2) * (hot + cold) + (moves % 2) * hot
    error =  abs(temperature - moves * target) * ans
    if error < min_error:
        ans = moves
    #print(f'moves  {moves}  error  {error}   ans  {ans}   min_error  {min_error}' )
    return ans


def main():
    test = int(input())
    for _ in range(test):
        hot, cold, target = map(int, input().split())
        avg = (hot + cold) / 2
        if target >= hot:
            ans = 1
        elif avg >= target:
            ans = 2
        else:
            moves = floor((hot - avg) / (target - avg))
            if moves % 2 == 0:
                moves -= 1
            ans = 2
            ans = compare_answer(hot, cold, target, moves, ans)
            ans = compare_answer(hot, cold, target, moves + 2, ans)
        print(ans)
        

if __name__ == "__main__":
    main()
