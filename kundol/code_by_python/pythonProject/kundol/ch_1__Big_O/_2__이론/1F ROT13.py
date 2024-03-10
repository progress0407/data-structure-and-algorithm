upper_list = [chr(i) for i in range(ord('A'), ord('Z')+1)]
upper_list *= 2

# print(upper_list)
upper_dict = {}
for i in range(26):
    k = upper_list[i]
    v= upper_list[i + 13]
    upper_dict[k] = v

lower_list = [chr(i) for i in range(ord('a'), ord('z')+1)]
lower_list *= 2

lower_dict = {}
for i in range(26):
    k = lower_list[i]
    v= lower_list[i + 13]
    lower_dict[k] = v

str = input()

res = ''
for ch in str:
    if ch.isupper():
        res += upper_dict[ch]
    elif ch.islower():
        res += lower_dict[ch]
    else:
        res += ch

print(res)