import itertools

cnt = 0

def dfs(y, x):
    global cnt
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

    chs = [chr(i) for i in range(ord('a'), ord('z'))]
    vowels = ['a', 'e', 'i', 'o', 'u']
    for v in vowels:
        chs.remove(v)
    print(chs)
