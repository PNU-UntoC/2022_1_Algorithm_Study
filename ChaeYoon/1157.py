def count_ch(str,ch):
    count=0
    for c in str:
        if c==ch:
           count=count+1
    return count
count_list=[]
input_string=input().upper()
alpha_list="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for ch in alpha_list:
    count_list.append(count_ch(input_string,ch))
max_alpha=0
max_index=0
for i in range(len(alpha_list)):
    if count_list[i]>max_alpha:
        max_alpha=count_list[i]
        max_index=i

count=0
for i in range(len(alpha_list)):
    if max_alpha==count_list[i]:
        count=count+1

if count==1:
    print(alpha_list[max_index])
else:
    print("?")
