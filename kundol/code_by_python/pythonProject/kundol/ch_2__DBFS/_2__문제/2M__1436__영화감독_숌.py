N = int(input())

six_cnt = 1  # 666이 발견된 횟수
current_num = 666
while True:
    if six_cnt == N:
        break
    current_num += 1
    if str(current_num).find('666') > -1:
        six_cnt += 1

print(current_num)
