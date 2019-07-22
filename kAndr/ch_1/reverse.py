# reverses the character string s
def reverse(s):
    reversed = ""

    # create new string by appending the characters of s in reverse order
    current_idx = len(s) - 1
    while current_idx >= 0:
        reversed += s[current_idx]
        current_idx -= 1
    return reversed

print(reverse("hello world"))