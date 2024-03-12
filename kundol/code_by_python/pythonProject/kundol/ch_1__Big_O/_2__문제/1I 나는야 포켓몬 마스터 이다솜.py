n, m = map(int, input().split())

alp_num_fn = {}
num_alp_fn = {}

for i in range(1, n + 1):
    str = input()
    alp_num_fn[str] = i
    num_alp_fn[i] = str

for i in range(1, m + 1):
    str = input()
    if str.isalpha():
        alp = alp_num_fn[str]
        print(alp)
    elif str.isdecimal():
        num = num_alp_fn[int(str)]
        print(num)
