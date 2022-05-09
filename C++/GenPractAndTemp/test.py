t=1
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
   
    ans=0
    for i in range(n):
        ans+=(a[i]*a[i])*(n-1)
        
        ans+=(b[i]*b[i])*(n-1)
    print(ans)
    dp=[[-1]*10001 for i in range(101)]
    chum = [0]*(n+1)
    chum[n-1]=a[n-1]+b[n-1]
    for i in range(n-2,-1,-1):
        chum[i]=chum[i+1]+a[i]+b[i]
    print(chum)
    def fun(x,y,cst):
        if x==-1:
            return cst
        z=chum[x+1]-y
        
        if dp[x][y]!=-1:
            return dp[x][y]
        
        dp[x][y]= min(fun(x-1,y+a[x],a[x]*y+b[x]*z+cst),fun(x-1,y+b[x],b[x]*y+a[x]*z+cst))
        return dp[x][y]
    # print(*chum)
    print(ans+2*fun(n-1,0,0))