import re


# 앞에서 0 채우기
def case_1():
    _str = str('123').zfill(5)
    print(_str)


# 뒤에서 0 채우기
def case_2():
    n='123'
    _str=f'{n:05}'
    print(_str)


# 정규식으로 숫자 덩어리를 찾아서 리스트업하기
def case_3():
    some_str = '12ab34c5'
    numbers = re.findall(r'\d+', some_str)
    print(numbers)


if __name__ == "__main__":
    # case_1()
    # case_2()
    case_3()