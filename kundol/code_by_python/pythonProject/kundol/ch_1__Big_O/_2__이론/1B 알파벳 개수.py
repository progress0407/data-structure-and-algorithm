str = input()

cnt_dict = {chr(i): 0 for i in range(ord('a'), ord('z')+1)}

for ch in str:
    cnt_dict[ch] += 1

digit_arr = [cnt_dict[v] for v in cnt_dict]
print(*digit_arr)