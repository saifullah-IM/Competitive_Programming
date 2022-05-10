from sys import stdin

input = stdin.readline

MX = int(2e5 + 5)
MOD = int(1e9 + 7)


def sanity_check(s_str, order, t_str):
    constructed_str = ''
    last_str = s_str
    for ch in order:
        constructed_str += last_str
        new_str = ''
        for ch_nxt in last_str:
            if ch_nxt != ch:
                new_str += ch_nxt
        last_str = new_str

    return constructed_str == t_str


def main():
    test = int(input())
    for _ in range(test):
        t_str = str(input())[:-1]
        n = len(t_str)

        order = ''
        isin = [False for _ in range(26)]
        indices = [[] for _ in range(26)]

        for i in range(n - 1, -1, -1):
            ch = ord(t_str[i]) - ord('a')
            if not isin[ch]:
                isin[ch] = True
                order += t_str[i]
            indices[ch].append(i)

        ch_cnt = len(order)
        possible = True
        ans_len = -1
        for i in range(ch_cnt):
            ch_i = ord(order[i]) - ord('a')
            if len(indices[ch_i]) % (ch_cnt - i) != 0:
                possible = False
                break

            l = MOD
            r = 0
            length = 0
            for j in range(i + 1):
                ch_j = ord(order[j]) - ord('a')
                slice_len = len(indices[ch_j]) // (ch_cnt - j)
                length += slice_len

                start = (i - j) * slice_len
                end = start + slice_len
                for idx in indices[ch_j][start:end]:
                    l = min(l, idx)
                    r = max(r, idx)

            if r - l + 1 == length:
                ans_len = length
            else:
                possible = False
                break

        if not possible:
            print(-1)
        else:
            order = order[::-1]
            s_str = t_str[:ans_len]
            if sanity_check(s_str, order, t_str):
                print(s_str, end=' ')
                print(order)
            else:
                print(-1)


if __name__ == "__main__":
    main()