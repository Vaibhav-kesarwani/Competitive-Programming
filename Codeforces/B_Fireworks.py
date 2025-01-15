t = int(input())
for qi in range(t):
    a, b, m = [int(x) for x in  input().split()]
    ans = m // a + m // b + 2
    print(ans)