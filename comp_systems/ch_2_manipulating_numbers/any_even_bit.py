import sys

def any_even_bit(x):
    x = int(x)
    print(bin(x)[2:])
    mask = 0x55
    mask |= (mask << 8)
    mask |= (mask << 16)
    print(bin(mask)[2:])
    return not not (x & mask)

if __name__ == "__main__":
    ans = any_even_bit(sys.argv[1])
    if ans:
        print("An even bit was set to 1")
    else:
        print("No even bits were set")
