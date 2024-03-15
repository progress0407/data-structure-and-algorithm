N = int(input())

team_1_score = 0
team_2_score = 0
last_time_at = 0
team_1_tot_time_duration = 0
team_2_tot_time_duration = 0
for _ in range(N):
    split = input().split()
    team_no = int(split[0])
    time_split = split[1].split(':')
    current_time_at = int(time_split[0]) * 60 + int(time_split[1])
    time_diff = current_time_at - last_time_at

    if team_1_score > team_2_score:
        team_1_tot_time_duration += time_diff
    elif team_1_score < team_2_score:
        team_2_tot_time_duration += time_diff

    if team_no == 1:
        team_1_score += 1
    else:
        team_2_score += 1

    last_time_at = current_time_at

current_time_at = 48 * 60

time_diff = current_time_at - last_time_at

if team_1_score > team_2_score:
    team_1_tot_time_duration += time_diff
elif team_1_score < team_2_score:
    team_2_tot_time_duration += time_diff


def get_time_format(time_duration):
    hour = time_duration // 60
    sec = time_duration % 60
    return f'{hour:02}:{sec:02}'


print(get_time_format(team_1_tot_time_duration))
print(get_time_format(team_2_tot_time_duration))
