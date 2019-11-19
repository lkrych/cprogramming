import sys

def convert(x: int):
    print("dec: {}, bin: {}, hex: {}".format(x, bin(x), hex(x)))

if __name__ == "__main__":
    num = int(sys.argv[1])
    convert(num)