import sys

def convert(x: str):
    i = int(x, 16)
    print("dec: {}, bin: {}, hex: {}".format(i, bin(i), x))

if __name__ == "__main__":
    num = sys.argv[1]
    convert(num)