import sys
from collections import defaultdict

def main():
    t = int(input())
    for _ in range(t):
        s = input().strip()
        mp = defaultdict(int)
        for char in s:
            mp[char] += 1
        maxi = max(mp.values())
        if maxi == len(s):
            print("NO")
            continue
        ss_list = list(s)
        for i in range(len(ss_list)):
            if ss_list[i] != ss_list[0]:
                ss_list[i], ss_list[0] = ss_list[0], ss_list[i]
                break
        print("YES")
        print("".join(ss_list))

if __name__ == "__main__":
    main()