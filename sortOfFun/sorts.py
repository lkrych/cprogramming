#bubble sort
def bubble_sort(arr):
  sorted = False
  while not sorted: #start bubbling
    sorted = True #sort until there are no more swaps
    for i, el in enumerate(arr):
      #avoid bounds error with this check
      if i < len(arr) - 1:
        if el > arr[i+1]:
          swap(arr, i, i+1)
          sorted = False
  return arr

#helper function for bubble sort
def swap(arr, i, j):
  temp = arr[i]
  arr[i] = arr[j]
  arr[j] = temp
  return arr

#insertion sort
def insertion_sort(arr):
  insertion_idx = 0
  while insertion_idx < len(arr):
    insertion_el = arr[insertion_idx]
    for i, el in enumerate(arr[:insertion_idx]): #loop through every el within the range of insertion_idx
      if i + 1 >= insertion_idx: #compare el to the elements within the range of insertion_idx
        if arr[insertion_idx] < el:
          #remove insertion el and place it where it needs to go
          del arr[insertion_idx]
          arr.insert(i, insertion_el)
          #you don't need to check anymore elements
          break
    insertion_idx += 1
  return arr
          

#merge sort
def merge_sort(arr):
  #base case, the arr is sorted if it is of length 1 or 0
  if len(arr) < 2: 
    return arr
  
  #divide the array in two
  mid_idx = len(arr) // 2
  left_arr = arr[: mid_idx]
  right_arr = arr[mid_idx :]

  #recursively sort the two arrays
  sorted_left_arr = merge_sort(left_arr)
  sorted_right_arr = merge_sort(right_arr)

  #use helper function to merge the two sorted arrays
  return merge(sorted_left_arr, sorted_right_arr)

#helper function for merge sort
def merge(arr1, arr2):
  merged = []
  i = 0 #init indices
  j = 0
  while len(merged) < len(arr1) + len(arr2):
    #if either array has been completely checked, add the other array to merged
    if i >= len(arr1):
      merged.extend(arr2[j:])
      return merged
    elif j >= len(arr2):
      merged.extend(arr1[i:])
      return merged

    #if neither array is empty, check which element is smaller and add to merged
    if arr1[i] > arr2[j]:
      merged.append(arr2[j])
      j+=1
    else:
      merged.append(arr1[i])
      i+=1

  return merged

print("bubblesort: {bubble}".format(bubble = bubble_sort([4,2,3,5,78,9,3,21,1,80])))
print("insertion sort: {insertion} ".format(insertion = insertion_sort([4,2,3,5,78,9,3,21,1,80])))
print("merge sort: {merge}".format(merge = merge_sort([4,2,3,5,78,9,3,21,1,80])))