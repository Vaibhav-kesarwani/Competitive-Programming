t = int(input())
for _ in range(t):
    n, f, a, b = map(int, input().split())
    m = [0] + [int(x) for x in input().split()]
    for i in range(1, n + 1):
        f -= min(a * (m[i] - m[i - 1]), b)
    print('YES' if f > 0 else 'NO')