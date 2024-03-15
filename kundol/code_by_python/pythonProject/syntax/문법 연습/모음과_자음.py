from copy import deepcopy

all_alphabet = [chr(i) for i in range(ord('a'), ord('z') + 1)]
consonant = deepcopy(all_alphabet)
vowels = ['a', 'e', 'i', 'o', 'u']

for v in vowels:
    consonant.remove(v)

print(consonant)
