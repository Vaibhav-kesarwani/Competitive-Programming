def solve():
    n = int(input())
    b = input()
    cnt = [0] * 26
    for c in b:
        cnt[ord(c) - ord('a')] = 1
    tmp = ''
    for i in range(26):
        if cnt[i] > 0:
            tmp += chr(ord('a') + i)
    a = ''
    for c in b:
        a += tmp[-1 - tmp.find(c)]
    print(a)
    
 
for _ in range(int(input())):
    solve()