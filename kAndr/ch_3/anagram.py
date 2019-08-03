from typing import List

result = []

def permute(data: List, i: int , length: int):
    if i == length:
        result.append(''.join(data))
    else:
        for j in range(i, length):
            #swap
            data[i], data[j] = data[j], data[i]
            permute(data, i+1, length)
            data[i], data[j] = data[j], data[i]

test = 'abcd'
permute(list(test), 0, len(test))
print(str(result))