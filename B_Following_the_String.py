def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    cnt = [0] * 26
    s = ''
    for i in range(n):
        for j in range(26):
            if cnt[j] == a[i]:
                cnt[j] += 1
                s += chr(97 + j)
                break
    print(s)
 
 
for _ in range(int(input())):
    solve()