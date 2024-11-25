for _ in range(int(input())):
    n = int(input())
    a = input()
    d = {0 : 1}
    res, s = 0, 0
    
    for i in range(n):
        s += int(a[i])
        x = s - i - 1
        if x not in d:
            d[x] = 0
        d[x] += 1
        res += d[x] - 1
        
    print(res)