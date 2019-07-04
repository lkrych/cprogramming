import re

ALPHA = "abcdefghijklmnopqrstuvwxyz"
ALPHA_COUNT = {}
ALPHA_RE = re.compile('([A-z]+)')


user_input = input("Type in your input and then press enter to print histogram: ")

split_input = list(user_input)

for char in split_input:
	if ALPHA_RE.match(char):
		lower_char = char.lower()
		if lower_char in ALPHA_COUNT:
			ALPHA_COUNT[lower_char] = ALPHA_COUNT[lower_char] + 1
		else:
			ALPHA_COUNT[lower_char] = 1

print("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
print("<><> histogram of different characters used in input <><>");
print("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
for alpha in ALPHA:
	if alpha in ALPHA_COUNT:
		print(alpha + "\t", end='')
		for i in range(ALPHA_COUNT[alpha]):
			print("*", end='')
		print()

