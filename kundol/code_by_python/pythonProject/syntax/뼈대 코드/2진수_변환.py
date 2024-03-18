def to_binary_string(number):
  """
  10진수 숫자를 2진수 문자열로 변환합니다.

  Args:
      number (int): 10진수 숫자

  Returns:
      str: 2진수 문자열
  """
  binary_string = ""
  while number > 0:
    binary_string += str(number % 2)
    number //= 2
  return binary_string[::-1]


def case_1():
    number = 10
    binary_string = bin(number)
    print(f"2진수 문자열: {binary_string}")  # 출력: 0b1010
    print(f"2진수 문자열: {binary_string[2:]}")  # 출력: 1010


def case_2():
    number = 10
    binary_string = f"{number:#b}"
    print(f"2진수 문자열: {binary_string}")  # 출력: 0b1010


def case_3():
    number = 10
    binary_string = to_binary_string(number)
    print(f"2진수 문자열: {binary_string}")  # 출력: 0b1010


if __name__ == "__main__":
    case_1()
    # case_2()
    # case_3()
