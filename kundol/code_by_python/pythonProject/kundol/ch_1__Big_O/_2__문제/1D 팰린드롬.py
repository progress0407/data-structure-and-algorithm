def rev(str):
    rev_str = ''
    for c in str:
        rev_str = c + rev_str

    return rev_str

origin = input()
reverse = rev(origin)

if origin == reverse:
    print(1)
else:
    print(0)
