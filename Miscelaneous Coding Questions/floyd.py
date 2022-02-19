'''
    Python program for finding THE ONLY duplicate number in a given list
    of numbers such that maximum element of list does not exceed size of list.
    Solved using Tortoise and Hare Algorithm (also called Floyd's Algorithm).

    Time Complexity: O(n), Space Complexity: O(1)
'''

def findDuplicate(nums)-> int:
    tortoise = nums[0]
    hare = nums [0]
    while True:
        tortoise = nums[tortoise]
        hare = nums[nums[hare]]
        if tortoise == hare:
            break

    ptr1 = nums[0]
    ptr2 = tortoise
    while ptr1 != ptr2:
        ptr1 = nums[ptr1]
        ptr2 = nums[ptr2]
    
    return ptr1

numbers = list(int(item) for item in input('Enter list: ').strip().split())
print('The duplicate element is', findDuplicate(numbers))
