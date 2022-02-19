# Display array elements in reverse using recursion
from typing import List

def displayArr(arr: List[int], index: int) -> None:
	if index == len(arr): return
	displayArr(arr, index + 1)
	print(arr[index], end = ' ')
	
# def _displayArr(arr, index: int) -> None:
	# if index == 0: return
	# displayArr(arr, index - 1)
	# print(arr[index], end = ' ')
	
def displayarray(arr: list,idx: int) -> None:
    if idx == 0:
        print(arr[0], end = ' ')
        return
    print(arr[idx], end = ' ')
    displayarray(arr,idx-1)

arr = [34,54,45,98,12]
print('Elements in array in reverse are: ')
displayArr(arr, 0)
print('\nElements in array in reverse are: ')
displayarray(arr, len(arr) - 1)
# print()
# _displayArr(arr,len(arr)-1)