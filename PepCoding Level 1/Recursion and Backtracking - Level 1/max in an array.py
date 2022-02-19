# def maxOfArray(arr: list, index: int) -> int:
	# if index == len(arr):
		# return arr[0]
	# arr[0] = max(arr[0], arr[index])
	# return maxOfArray(arr, index + 1)

def maxOfArray(arr: list, index: int) -> int:
	if index == len(arr) - 1:
		return arr[index]
	return max(maxOfArray(arr, index + 1), arr[index])

arr = [100,34,54,45,98]
print('Max of given array is:', maxOfArray(arr, 0))