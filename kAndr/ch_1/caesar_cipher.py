def caesar_cipher(string: str, shift: int) -> str:
  shifted = ''
  for char in string.lower():
    if char.isalnum():
      # ascii fanciness
      # ord converts a char to ascii val
      # chr converts an ascii val to char
      # 122 = 'z'
      # 97 = 'a'
      new_char_ascii = ord(char) + shift
      if new_char_ascii > 122:
        new_char_ascii = (new_char_ascii % 122) + 96
      shifted += chr(new_char_ascii)
    else:
      shifted += char
  return shifted

print(caesar_cipher("hello world", 4))