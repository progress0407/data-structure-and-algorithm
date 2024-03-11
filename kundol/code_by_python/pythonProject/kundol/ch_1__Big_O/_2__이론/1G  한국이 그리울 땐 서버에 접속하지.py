n = int(input())

pattern = input()
st, ed = pattern.split('*')

for _ in range(n):
    str = input()

    str_st = str[:len(st)]
    str_ed = str[-len(ed):]

    if st == str_st and ed == str_ed:
        print("DA")
    else:
        print("NE")
