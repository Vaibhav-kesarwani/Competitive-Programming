test_case_T = int(input())
for _ in range(test_case_T):
    num = int(input())
    a = list(map(int, input().split()))
    mappd = {}
    mpoos = {}
    for j in range(num):
        temp = a[j]
        temp >>= 2
        if temp not in mappd:
            mappd[temp] = []
            mpoos[temp] = []
        mappd[temp].append(a[j])
        mpoos[temp].append(j)
    for it in mappd.values():
        it.sort()
    for it in mpoos.values():
        it.sort()
    ans = [0] * num
    for k, v in mpoos.items():
        for j in range(len(v)):
            ans[v[j]] = mappd[k][j]
    print(*ans)