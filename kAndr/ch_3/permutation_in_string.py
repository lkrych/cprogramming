from typing import List

def permutation(d: List, i: int, l: int, results: List) -> List[str]:
    if i == l:
        results.append(''.join(d))
    else:
        for j in range(i, l):
            d[i], d[j] = d[j], d[i]
            permutation(d, i+1, l, results)
            d[i], d[j] = d[j], d[i]
#r = []
#test = permutation(list('abcd'), 0, len('abcd'), r)
#print(r)

# Given two strings s1 and s2, write a function to return true 
# if s2 contains the permutation of s1. 
# In other words, one of the first string's permutations is the substring of the second string.
def check_permutation(s1: str, s2: str) -> bool:
    #find perms in s1
    perms = []
    permutation(list(s1), 0, len(s1), perms)

    #check if each perm exists in s2
    for perm in perms:
        if perm in s2:
            return True
    return False

assert check_permutation('ab', 'eidbaooo') == True
assert check_permutation('ab', 'eidboaoo') == False

