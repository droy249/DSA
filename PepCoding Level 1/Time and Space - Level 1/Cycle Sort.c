// Video Link: https://youtu.be/JfinxytTYFQ
// Gfg Link: https://www.geeksforgeeks.org/cycle-sort/

#include <stdio.h>
// using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void cyclicSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct]) {
            swap(arr, i, correct);
        } else {
            ++i;
        }
    }
}

int main() {
    int arr[] = {3, 5, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cyclicSort(arr, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Similar leetcode questions

// https://leetcode.com/problems/missing-number/submissions/
/* int missingNumber(int* nums, int numsSize){
    int i = 0;

    while(i < numsSize) {
        if(nums[i] == numsSize) {
            i++;
            continue;
        }

        int correct = nums[i];
        if(nums[i] != nums[correct]) {
            swap(nums, i, correct);
        } else {
            ++i;
        }
    }

    for(int i = 0; i < numsSize; ++i) {
        if(i != nums[i]) {
            return i;
        }
    }

    return numsSize;
} */

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
/* def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
    res = []

    # Cyclic sort
    i = 0
    while i < len(nums):
        correct = nums[i] - 1
        if(nums[i] != nums[correct]):
            nums[i], nums[correct] = nums[correct], nums[i]
        else:
            i += 1


    for i in range(len(nums)):
        if i + 1 != nums[i]:
            res.append(i+1)

    return res */

// https://leetcode.com/problems/set-mismatch/
/* def findErrorNums(self, nums: List[int]) -> List[int]:
    i = 0
    while i < len(nums):
        correct = nums[i] - 1
        if(nums[i] != nums[correct]):
            nums[i], nums[correct] = nums[correct], nums[i]
        else:
            i += 1


    for i in range(len(nums)):
        if i + 1 != nums[i]:
            return [nums[i], i + 1]

    return [] */

// https://leetcode.com/problems/find-the-duplicate-number/
/* def findDuplicate(self, nums: List[int]) -> int:
    i = 0
    while i < len(nums):
        correct = nums[i] - 1
        if(nums[i] != nums[correct]):
            nums[i], nums[correct] = nums[correct], nums[i]
        else:
            i += 1


    for i in range(len(nums)):
        if i + 1 != nums[i]:
            return nums[i]

    return nums[0] */

