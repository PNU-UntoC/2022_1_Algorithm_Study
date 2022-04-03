import sys
input = sys.stdin.readline

C = int(input())

for i in range(C) :
    x_lst = [0]*4
    y_lst = [0]*4

    for j in range(0,3) :
        a, b = map(int,input().split())
        x_lst[j] = a
        y_lst[j] = b
    
    x = 0
    y = 0
    for j in range(0,3) :
        if (x_lst.count(x_lst[j]) == 1) : 
            x = x_lst[j]
        if (y_lst.count(y_lst[j]) == 1) : 
            y = y_lst[j]
    
    print(x,y)
    
