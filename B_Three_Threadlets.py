for _ in range(int(input())):
    a, b, c = sorted(map(int, input().split()))
    if a == b and b == c:
        print('YES')
    elif b % a == 0 and c % a == 0 and (b // a - 1) + (c // a - 1) <= 3:
        print('YES')
    else:
        print('NO')