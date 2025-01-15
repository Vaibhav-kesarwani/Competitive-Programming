for _ in range(int(input())):
    n = int(input())
    ans = 2 * 10 ** 9
    for i in range(n):
        d, s = map(int, input().split())
        ans = min(ans, d + (s - 1) // 2)
    print(ans)