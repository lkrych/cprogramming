#test with hamlet.txt
def longest_word(file_name):
	longest_word = ""
	file = open(file_name, "r") 
	for line in file: 
		split_line = line.split(" ")
		for word in split_line:
			if len(word) > len(longest_word):
				longest_word = word
	print("The longest word in {file} is {word}".format(file=file_name, word=longest_word))

longest_word("hamlet.txt")
