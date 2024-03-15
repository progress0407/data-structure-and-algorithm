from copy import deepcopy

all_alphabet = [chr(i) for i in range(ord('a'), ord('z') + 1)]
vowels = ['a', 'e', 'i', 'o', 'u']
consonant = deepcopy(all_alphabet)
for vowel in vowels:
    consonant.remove(vowel)


# 모음 1개 이상 포함
def cond_1(str):
    for vowel in vowels:
        if vowel in str:
            return True
    return False


# 자음 혹은 모음이 3개 이상 올수없다
def cond_2(str):
    v_cnt = 0  # 연속된 모음의 갯수
    c_cnt = 0  # '' 자음의 갯수
    for ch in str:
        if cond_1(ch):
            v_cnt += 1
            c_cnt = 0
        else:
            c_cnt += 1
            v_cnt = 0
        if v_cnt == 3 or c_cnt == 3:
            return False
    return True


# 같은 글자 연속 2번은 안되지만 ee나 oo는 허용한다
def cond_3(str):
    pre_alpha = str[0]
    ex_alphas = ['e', 'o']

    for i in range(1, len(str)):
        ch = str[i]
        if ch in ex_alphas:
            continue
        if ch == pre_alpha:
            return False
        pre_alpha = ch

    return True


while True:
    str = input()

    if str == 'end':
        break

    if cond_1(str) and cond_2(str) and cond_3(str):
        print(f'<{str}> is acceptable.')
    else:
        print(f'<{str}> is not acceptable.')
