T = int(input())

for i in range(T) :
    x1, y1, x2, y2 = map(int,input().split())
    n = int(input())
    
    result = 0
    # planet 
    planet = [0 for _ in range(3*n)]
    for j in range(0,n) :
        x = planet[3*j] 
        y = planet[3*j+1] 
        r = planet[3*j+2] 
        x , y , r = map(int,input().split())
        
        if ((x1-x)**2 + (y1-y)**2 <= r**2) and ((x2-x)**2 + (y2-y)**2 <= r**2) :
            result += 0
        elif ((x1-x)**2 + (y1-y)**2 <= r**2) :
            result += 1
        elif ((x2-x)**2 + (y2-y)**2 <= r**2) :
            result += 1

    print(result)

