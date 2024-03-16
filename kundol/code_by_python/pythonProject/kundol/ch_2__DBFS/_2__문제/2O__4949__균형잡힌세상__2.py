while True:
    s = input()

    if s == '.':
        break

    stk = []
    is_balanced = True
    for cur_ch in s:
        if cur_ch not in '[]()':
            continue
        if cur_ch in '[(':
            stk.append(cur_ch)
        else:
            if not stk:  # ] or )
                is_balanced = False
                break
            else:
                last = stk[-1]
                if (last == '(' and cur_ch == ')') or (last == '[' and cur_ch == ']'):
                    stk.pop()
                else:
                    stk.append(cur_ch)
    if stk:  # 스택에 괄호가 존재한다면
        is_balanced = False

    print('yes' if is_balanced else 'no')
