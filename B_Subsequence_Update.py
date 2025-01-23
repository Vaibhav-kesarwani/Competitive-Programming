import sys
input=lambda:sys.stdin.readline().rstrip()
 
for _ in range(int(input())):
    n,l,r=map(int,input().split());l-=1
    arr=[*map(int,input().split())]
    brr=arr[:l]+sorted(arr[l:])
    crr=sorted(arr[:r])[::-1]+arr[r:]
    print(min(sum(brr[l:r]),sum(crr[l:r])))