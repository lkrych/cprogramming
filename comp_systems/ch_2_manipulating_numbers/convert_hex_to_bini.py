import sys

def convert(x: str):
    i = int(x, 16)
    print("dec: {}, bin: {}, hex: 0x{}".format(i, bin(i), x))

if __name__ == "__main__":
    num = sys.argv[1]
    convert(num)