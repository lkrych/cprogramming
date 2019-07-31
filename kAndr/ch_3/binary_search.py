from typing import List
def binary_search(arr: List, x: int) -> int:
    if len(arr) <= 0:
        return -1
    mid_idx = len(arr) // 2
    selected = arr[mid_idx]
    if selected == x:
        return mid_idx
    elif selected > x:
        return binary_search(arr[0:mid_idx], x)
    else:
        ans = binary_search(arr[mid_idx+1:], x)
        if ans == -1:
            return ans
        else:
            return mid_idx + 1 + ans

print("The index of {x} in {arr} is {i}".format(x=1,arr=[1,2,3,4,5,6],i=binary_search([1,2,3,4,5,6],1)))
print("The index of {x} in {arr} is {i}".format(x=0,arr=[1,2,3,4,5,6],i=binary_search([1,2,3,4,5,6],0)))
print("The index of {x} in {arr} is {i}".format(x=18,arr=[1,2,3,4,5,6],i=binary_search([1,2,3,4,5,6],18)))
print("The index of {x} in {arr} is {i}".format(x=3,arr=[1,2,3,4,5,6],i=binary_search([1,2,3,4,5,6],3)))