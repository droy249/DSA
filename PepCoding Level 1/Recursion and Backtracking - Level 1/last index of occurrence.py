# Program to find last index of occurrence of a given element. If not found return -1.
def lastIndex(arr: list, index: int, target: int):
	if index == len(arr): return -1
	last_index = lastIndex(arr, index + 1, target)
	if last_index == -1:
		return index if arr[index] == target else -1
	else:
		return last_index

l: list = [3,6,4,6,3,7,3,8]
target: int = 3
index: int = lastIndex(l,0,target)
print('Element not found' if index == -1 else f'Last occurrence of {target} at {index}')