N = int(input())


for _ in range(N):
    string = input()

    stk=[]
    for ch in string:
        if len(stk) == 0:
            stk.append(ch)
        else:
            last = stk[-1]
            if last == '(' and ch == ')':
                stk.pop()
            else:
                stk.append(ch)

    if len(stk) == 0:
        print("YES")
    else:
        print("NO")
