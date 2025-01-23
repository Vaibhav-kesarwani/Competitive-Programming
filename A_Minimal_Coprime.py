for i in range(int(input())):
    x,y=map(int,input().split())
    if x==y==1:
        print(1)
    else:
        print(y-x)