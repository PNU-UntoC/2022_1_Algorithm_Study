import sys 
N = int(input())
a = []
for _ in range(N):
    a.append(int(sys.stdin.readline()))
a.sort()
for i in range(N):
    print(a[i])
    
# result = "\n".join(a)
# print(result)
