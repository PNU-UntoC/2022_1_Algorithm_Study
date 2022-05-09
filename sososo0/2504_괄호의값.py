brackets = list(input())

stack = []
answer = 0
temp = 1

for i in range(len(brackets)):

    if brackets[i] == "(":
        stack.append(brackets[i])
        temp = temp * 2

    elif brackets[i] == "[":
        stack.append(brackets[i])
        temp = temp * 3

    elif brackets[i] == ")":
        if not stack or stack[-1] == "[":
            answer = 0
            break
        if brackets[i-1] == "(":
            answer = answer + temp
        stack.pop()
        temp = temp // 2

    else:
        if not stack or stack[-1] == "(":
            answer = 0
            break
        if brackets[i-1] == "[":
            answer = answer + temp
        stack.pop()
        temp = temp // 3

if stack:
    print(0)
else:
    print(answer)
