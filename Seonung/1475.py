N = input()
cnt = 0
tmp = []
for i in '0123456789':
    tmp.append(N.count(i))
tmp.append(round((tmp[6]+tmp[9])/2 + 0.1))
del tmp[6]
del tmp[8]
print(max(tmp))
