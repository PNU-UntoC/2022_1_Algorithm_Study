N = int(input())
target = int(input())

snail_lst = [ [0] * (N+2) for _ in range(N+2)] 

snail_lst[0][N] = 0 
snail_lst[0][N+1] = 0 

def it_is_target(num) :
    if num == target :
        return True
    else :
        return False

def snail(N,n,m,snail_list) :
    if N == 1 :
        if it_is_target(N) :
            snail_list[0][N] = m + 1
            snail_list[0][N+1] = m + 1
        
        snail_list[m][m] = 1
        return snail_list 
    elif n == 1 :
        if it_is_target(n) :
            snail_list[0][N] = m + 1
            snail_list[0][N+1] = m + 1

        snail_list[m][m] = 1
        return snail_list

    loc = n**2

    # 1 first line 
    for i in range(0,n) :
        if it_is_target(loc) : 
            snail_list[0][N] = m+i + 1
            snail_list[0][N+1] = m + 1
        snail_list[m+i][m] = loc  
        loc -= 1
        
    loc += 1
    
    # 2 second line 
    for i in range(1,N-2*m) :
        loc -= 1 
        if it_is_target(loc) : 
            snail_list[0][N] = N-1-m + 1
            snail_list[0][N+1] = m+i + 1
        snail_list[N-1-m][i+m] = loc 
    
    
    # 3 third line
    for i in range(1,N-2*m) :
        loc -= 1 
        if it_is_target(loc) : 
            snail_list[0][N] = N-1-i-m + 1
            snail_list[0][N+1] = N-1-m + 1
        snail_list[N-1-i-m][N-1-m] = loc 


    # 4 forth line 
    for i in range(1,N-2*m-1) :
        loc -= 1 
        
        if it_is_target(loc) : 
            snail_list[0][N] = m + 1
            snail_list[0][N+1] = N-m-1-i + 1

        snail_list[m][N-m-1-i] = loc  
    

    return snail(N,n-2,m+1,snail_list)




snail(N,N,0,snail_lst)


for i in range(N) :
    for j in range(0,N-1) :
        print(snail_lst[i][j] , end=" ")
    print(snail_lst[i][N-1])

print(snail_lst[0][N],end = " ")
print(snail_lst[0][N+1])
