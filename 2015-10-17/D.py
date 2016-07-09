import math
def nCr(n,r):
    f = math.factorial
    return f(n)//f(r)//f(n-r)
    
    




T = int(raw_input())
for i in xrange(T):
    C,B = [int(x) for x in raw_input().split()]
    member = [int(x) for x in raw_input().split()]
    # first caculate the denominator
    total = sum(member)
    
    # then nominator
    if (B == C):
        
        nom = 1
        for m in member:
            nom = nom*nCr(m,1)
        deno = nCr(total,B)    
    elif (B > C):
        nom = 1
        for m in member:
            nom = nom*nCr(m,1)
        nom = nom*nCr(total-C,B-C)//math.factorial(B) 
        deno = nCr(total,B)
    else:
        nom = 0               
    if (B == 0 or B < C):
        print format(0,'.6f')
    else:
                
        print format(float(nom)/deno,'.6f')    
    