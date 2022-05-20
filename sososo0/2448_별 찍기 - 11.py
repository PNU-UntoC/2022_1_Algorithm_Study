def makeTree(t):
    l = len(t)
    for i in range(l):
        t.append(t[i]+" "+t[i])
        t[i] = " "*l + t[i] + " "*l
    return t

n = int(input())
t = ["  *  "," * * ","*****"]
n = n//3

cnt = 0

while n>1:
    n = n//2
    cnt += 1
    
for i in range(cnt):
    makeTree(t)
    
for i in t:
    print(i)
