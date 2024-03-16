N, S = map(int, input().split())

nums = list(map(int, input().split()))
mem_cur_nums = [0 for i in range(N)]
cnt = 0

# loop_cnt = 0


def call_recur(depth, tot):
    global loop_cnt
    global cnt
    if depth == N - 1:
        # loop_cnt += 1
        # print(f'depth={depth}, loop_cnt={loop_cnt}, tot={tot}')
        if tot == S:
            cnt += 1
    else:
        call_recur(depth + 1, tot)
        call_recur(depth + 1, tot + nums[depth + 1])


depth = 0
tot = 0
call_recur(depth, tot)
call_recur(depth, tot + nums[depth])

if S == 0:
    cnt -= 1

print(cnt)