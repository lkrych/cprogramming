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
def check_permutation_naive(s1: str, s2: str) -> bool:
    #find perms in s1
    perms = []
    permutation(list(s1), 0, len(s1), perms)

    #check if each perm exists in s2
    for perm in perms:
        if perm in s2:
            return True
    return False

assert check_permutation_naive('ab', 'eidbaooo') == True
assert check_permutation_naive('ab', 'eidboaoo') == False

# a permutation of a word is going to have the same number of characters
# use an array to store these chars and compare each window in the array
def check_permutation_optimized(s1: str, s2: str) -> bool:
    s1_window = create_window(s1)
    for i in range(len(s2) - len(s1)):
        check_window = create_window(s2[i:i+len(s1)])
        if check_window_equality(s1_window, check_window):
            return True
    return False

def create_window(s: str) -> List[int]:
    ALPHA = { 'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25 }
    alpha_arr = [0] * 26
    
    for char in s:
        i = ALPHA[char]
        alpha_arr[i] += 1
    
    return alpha_arr

def check_window_equality(arr1: List[int], arr2: List[int]) -> bool:
    for i in range(len(arr1)):
        if arr1[i] != arr2[i]:
            return False
    return True

assert check_permutation_optimized('ab', 'eidbaooo') == True
assert check_permutation_optimized('ab', 'eidboaoo') == False