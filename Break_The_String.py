def z_function(s):
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
    return z

t = int(input())
for case in range(t):
    s = input().strip()
    n = len(s)
    
    if n & 1:  # Check if string length is odd
        print(0)
        continue
    
    z_prefix = z_function(s)
    start_P = []
    
    for i in range(n):
        length = i
        if length <= z_prefix[i]:
            start_P.append(i)
        
    z_suffix = z_function(s[::-1])
    start_R = []
    
    for i in range(n):
        length = i
        if length <= z_suffix[i]:
            start_R.append(n - i - 1)
    
    start_R_set = set(start_R)
    ans = 0
    
    for i in start_P:
        end = 2 * i
        size = (n - 1) - end + 1
        size = size // 2
        coord = (n - 1) - size
        if coord in start_R_set:
            ans += 1
            
    print(ans)
