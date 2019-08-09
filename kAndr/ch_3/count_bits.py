# return how many bits are set to 1 in a positive integer
def count_bits(x: int) -> int:
    num_bits = 0
    while x:
        num_bits += x & 1 # ANDS x against 1 
        x >>= 1 # Binary right shift
    return num_bits

# example of count_bits:
# count_bits(5)
# 101 & 1 = 1
# 10 & 1 = 0
# 1 & 1 = 1
# returns 2

assert count_bits(5) == 2
assert count_bits(4) == 1
assert count_bits(255) == 8