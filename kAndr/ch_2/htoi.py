# htoi takes a hexadecimal string and converts it to an integer
hex_trans = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6, 
    '7': 7,
    '8': 8,
    '9': 9,
    'a': 10,
    'b': 11,
    'c': 12,
    'd': 13,
    'e': 14,
    'f': 15,
}

def htoi(n: str) -> int:
    int_val = 0
    i = len(n) - 1
    power = 0
    while i >= 0:
        int_val = ((16 ** power) * hex_trans[n[i]]) + int_val
        i-=1
        power+=1
    return int_val


print(htoi("f")) # 15
print(htoi("13")) # 19
print(htoi("a156")) # 41302