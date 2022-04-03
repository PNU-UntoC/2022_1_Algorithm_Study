import sys
input = sys.stdin.readline

C = int(input())

for _ in range(0,C) :
    # 입력값 받기 
    N, L = map(int,input().split())
    
    N_lst = list(map(int,input().split()))

    # 1번째값 
    price = 0
    for k in range(0,L) :
        price += N_lst[k]
    price /= L

    # 구현 
    for i in range(0,N) :
        tmp = 0
        for j in range(i,N) :
            tmp += N_lst[j]

            if (j-i+1 >= L) and (tmp/(j-i+1) < price) :
                price = tmp/(j-i+1)
    
    print(price)



