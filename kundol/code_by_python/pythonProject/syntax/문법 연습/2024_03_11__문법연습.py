import itertools

one_loop_area = 0


def dfs(y, x):
    global one_loop_area
    cnt += 1


if __name__ == "__main__":
    # str = "abcdef"
    # print(str[1:3])

    # li = []
    # li.extend((1, 3))
    # print(li)

    # arr = [0] * 3
    # arr[0]=3; arr[1]=5; arr[2]=1
    # arr.sort()
    # print(arr)

    # stk = [1,2,3]
    # stk2 = []
    # print()

    # print("a" in "ab")
    # print("a" not in "ab")

    # a = 12
    # print(f'{a:05}')

    # stk=[]
    # stk.append(1)
    # stk.append(2)
    # stk.append(3)
    # stk.pop()
    # print(stk)

    adj = [[] for _ in range(3)]
    adj[0].extend([1, 2])
    adj[1].extend([3])
    adj[2].extend([5])

    print(adj)
