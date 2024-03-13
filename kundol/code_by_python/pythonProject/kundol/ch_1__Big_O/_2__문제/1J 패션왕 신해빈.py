t = int(input())

for _ in range(t):
    n = int(input())

    dict = {}
    for _ in range(n):
        value, key = input().split()
        if dict.get(key) is None:
            dict[key] = [value]
        else:
            dict[key].append(value)
    prd = 1
    for values in dict.values():
        prd *= len(values) + 1
    prd -= 1
    print(prd)
