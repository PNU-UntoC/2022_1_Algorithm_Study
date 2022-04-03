def cycle(num):
    num_first = num // 10
    num_second = num % 10
    num_sum = num_first + num_second
    num_new = num_second * 10 + num_sum % 10
    return num_new


num_list=[]
num=int(input())
num_cycle=num
count=0
for i in range(1,100):
    num_cycle=cycle(num_cycle)
    if num_cycle==num:
        count=i
        break
print(count)