# Given two strings s1 and s2, write a function to return true 
# if s2 contains the permutation of s1. 
# In other words, one of the first string's permutations is the substring of the second string.
def check_permutation(s1: str, s2: str):
    #find perms in s1 

    #check if each perm exists in s2


assert check_permutation('ab', 'eidbaooo') == True
assert check_permutation('ab', 'eidboaoo') == False