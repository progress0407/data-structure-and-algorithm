ps = ['[', ']', '(', ')']


def check_by_stack(ps_st):
    stk = []
    for cur_ch in ps_st:
        if len(stk) == 0 and (cur_ch == ')' or cur_ch == ']'):
            stk.append(cur_ch)
            break
        else:
            if len(stk) == 0:
                stk.append(cur_ch)
            else:
                last = stk[-1]
                if (last == '(' and cur_ch == ')') or (last == '[' and cur_ch == ']'):
                    stk.pop()
                else:
                    stk.append(cur_ch)
    if len(stk) == 0:
        print('yes')
    else:
        print('no')


while True:
    ps_st_input = input()

    if ps_st_input == '.':
        break

    ps_st = []
    for ch in ps_st_input:
        if ch in ps:
            ps_st.append(ch)

    check_by_stack(ps_st)
