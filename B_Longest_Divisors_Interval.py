for n in[*map(int,open(0))][1:]:
    i=1
    while n%i<1:i+=1
    print(i-1)