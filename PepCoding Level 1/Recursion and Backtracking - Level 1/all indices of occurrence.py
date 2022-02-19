# Program to find all occurrences of given element.

# # My answer: 
# def allIndices(arr: list[int], index: int, target: int) -> list[int]:
	# indices : list = []
	
	# def allIndicesHelper(arr,index,target,indices):
		# if index == len(arr): return
		# if arr[index] == target: indices.append(index)
		# allIndicesHelper(arr,index+1,target,indices)
	
	# allIndicesHelper(arr,0,target,indices)
	# return indices

# PepCoding answer: (works in Java for simple arrays)
def allIndices(arr: list[int], index: int, target: int, fsf: int = 0) -> list[int]:		# fsf -> found so far
	if index == len(arr):
		return [0] * fsf
	if(arr[index] == target):
		listSoFar: list = allIndices(arr, index + 1, target, fsf + 1)
		listSoFar[fsf] = index
		return listSoFar
	
	return allIndices(arr, index + 1, target, fsf)
		

l: list = [3,6,4,6,3,7,3,8]
target: int = 3
print('Indices at which', target, 'occurs are:')
print(*allIndices(l,0,target))