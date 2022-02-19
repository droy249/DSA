# Program to find first index of occurrence of a given element. If not found return -1.
def firstIndex(arr: list, index: int, target: int):
	if index == len(arr): return -1
	return index if arr[index] == target else firstIndex(arr, index + 1, target)

l: list = [3,6,4,6,3,7,3,8]
target: int = 9
index = firstIndex(l,0,target)
print('Element not found' if index == -1 else f'First occurrence of {target} at {index}')