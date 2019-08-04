# Given a string s consisting of digits 0-9 
# and lowercase English letters a-z.

# A string is interesting if you can split it 
# into several substrings, such that each substring 
# starts with a number and this number represents the number of characters after it. 
# Return true if string s is intersting, otherwise false.
# https://leetcode.com/discuss/interview-question/350312/google-onsite-interesting-string
def interesting_string(s: str):
    i = 0
    while i < len(s):
        if s[i].isdigit():
            i += int(s[i]) + 1
            # catch the string going beyond its actual length
            if i > len(s):
                return False
        else:
            return False
    return True




assert interesting_string("4g12y6hunter") == True
assert interesting_string("124gray6hunter") == True
assert interesting_string("31ba2a") == False