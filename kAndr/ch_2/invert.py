# invert(x,p,n) that returns x with the n bits that 
# begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
# leaving the others unchanged
def invert(x: int, p: int, n: int) -> str:
    bin = to_binary_str(x)
    rev_bin = reverse_str(bin) 
    for i in range(p-n, p):
        flip_bit(rev_bin, i)
    return reverse_str(rev_bin)
    
        
def to_binary_str(x: int) -> str:
    if x < 0:
        raise TypeError('x cannot be negative')
    if x == 0:
        return '0'
    
    bin_string = ""
    while x > 0:
        digit = x % 2
        bin_string = str(digit) + bin_string # add to front
        x = x // 2
    return bin_string

def reverse_str(s: str) -> str:
    i = 0
    reverse = ''
    while i < len(s):
        reverse = s[i] + reverse
        i+=1
    return reverse


def flip_bit(x: str, i: int):
    if x[i] == '0':
        return '1'
    else:
        return '0'

print(invert(5, 1, 1)) # 101 ->  110
print(invert(8, 2, 2)) # 1000 -> 1011
print(invert(26, 4, 3)) # 11010 -> 10100