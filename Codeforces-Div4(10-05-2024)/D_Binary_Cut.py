test_case_T = int(input())
for _ in range(test_case_T):
    ao = input().strip()
    f = True
    for i in range(1, len(ao)):
        if ao[i] < ao[i - 1]:
            f = False
            break
    if f:
        print(1)
    else:
        count = 1
        check = 0
        for i in range(1, len(ao)):
            if ao[i] != ao[i - 1]:
                if ao[i] == '1' and ao[i - 1] == '0':
                    check = 1
                count += 1
        print(count - check)