if __name__ == "__main__":
    print('and')
    print(0 and 0)
    print(0 and 1)
    print(1 and 0)
    print(1 and 1)

    print('or')
    print(0 or 0)
    print(0 or 1)
    print(1 or 0)
    print(1 or 1)

    N = 5
    adj = [[] for i in range(N)]
    adj[1].append(2)
    adj[1].append(3)
    adj[2].extend([3, 4])
    adj[4].append(5)
    print(*adj)
