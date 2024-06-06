t = int(input())
for tt in range(t):
    p = [int(i) for i in input().split(" ")]
    d = -1
    for p01 in range(0, min(p[0], p[1]) + 1):
        for p02 in range(0, min(p[0], p[2]) + 1):
            for p12 in range(0, min(p[1], p[2]) + 1):
                if (p[0] - p01 - p02) % 2 != 0 or p[0] < p01 + p02:
                    continue
                if (p[1] - p01 - p12) % 2 != 0 or p[1] < p01 + p12:
                    continue
                if (p[2] - p12 - p02) % 2 != 0 or p[2] < p12 + p02:
                    continue
                d = max(d, p01 + p02 + p12)
    print(d)