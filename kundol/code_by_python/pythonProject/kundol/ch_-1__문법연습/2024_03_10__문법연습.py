import itertools


if __name__ == "__main__":
    # for i in range(1,3):
    #     print(i)

    str = "abc"
    rev_str = ''
    for c in str:
        rev_str = c + rev_str
    print(rev_str)
