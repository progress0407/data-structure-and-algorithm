N = int(input())
A = list(map(int, input().split()))
O = [-1 for _ in range(N)]
stk=[]

for i in range(N):
    current_num = A[i]
    if len(stk) ==0:
        stk.append(i)
    else:
        last_index = stk[-1]
        last = A[last_index]
        while len(stk) > 0 and last < current_num:
            O[last_index] = current_num
            stk.pop()
            if len(stk) > 0:
                last_index = stk[-1]
                last = A[last_index]
        stk.append(i)

print(O)