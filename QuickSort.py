"""
Author: Sean Dever
Date: 3/28/2021
Description: Basic implementation of Quick Sort recursive algorithm in Python.

"""
def quickSortSetUp(array):
    quickSort(array,0,len(array) - 1)

def quickSort(array,left,right):
    # Base Case
    if left >= right: 
        return 
    pivot = partition(array,left,right)

    # Recursive Calls
    quickSort(array,left,pivot - 1)
    quickSort(array,pivot + 1, right)

def partition(array,left,right):
    pivot_point = array[right]
    i = left - 1
    for j in range(left,right):
        if array[j] < pivot_point:
            i += 1
            array[i], array[j] = array[j], array[i] # Swap values
    array[i+1], array[right] = array[right], array[i+1]
    return i + 1


testArray1 = [3,2,1]
testArray2 = [9,2,4,8,5,3,1]

print("Test case 1 before Quick Sort: ", testArray1)
quickSortSetUp(testArray1)
print("Test case 1: after Quick Sort: ", testArray1)

print("Test case 2 before Quick Sort: ", testArray2)
quickSortSetUp(testArray2)
print("Test case 2: after Quick Sort: ", testArray2)

