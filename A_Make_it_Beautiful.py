t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if a[0] == a[n - 1]:
        print('NO')
    else:
        print('YES')
        print(a[n - 1], end = ' ')
        print(*(a[0:n-1]))