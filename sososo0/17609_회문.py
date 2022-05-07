def firstCheck(l,r):
    while l < r:
        if word[l] == word[r]:
            l += 1
            r -= 1
        else:
            return False
    return True

def compareCheck(l,r):
    while l < r:
        if word[l] == word[r]:
            l += 1
            r -= 1
        else:
            if firstCheck(l+1,r) or firstCheck(l,r-1):
                return 1
            return 2
    return 0


n = int(input())

for _ in range(n):
    word = input()
    print(compareCheck(0,len(word)-1))
