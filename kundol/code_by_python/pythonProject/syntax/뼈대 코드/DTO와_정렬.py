class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __repr__(self):
        return f'Person(name={self.name}, age={self.age})'


# 리스트 생성
people = [
    Person("Alice", 30),
    Person("Bob", 35),
    Person("Charlie", 30),
    Person("David", 35)
]

# 나이로 먼저 정렬하고, 나이가 같으면 이름으로 오름차순 정렬
people_sorted = sorted(people, key=lambda p: (p.age, p.name))

for person in people_sorted:
    print(person)
