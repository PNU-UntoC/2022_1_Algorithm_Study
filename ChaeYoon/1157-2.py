input_string=input().upper()
alpha_list="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dic={}
for ch in alpha_list:
    dic[ch]=0
for ch in input_string:
    dic[ch.upper()]=dic[ch.upper()]+1

max_alpha=0
max_index=""
for idx in dic:
    if dic[idx]>max_alpha:
        max_alpha=dic[idx]
        max_index=idx

count=0
for idx in dic:
    if dic[idx]==dic[max_index]:
        count=count+1
if count==1:
    print(max_index)
else:
    print("?")