// Question Link: https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
// Video Link: https://youtu.be/oaVa-9wmpns?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
// Gfg Link: 
// Leetcode Link: https://leetcode.com/problems/sort-colors/
#include <stdio.h>

/* APPROACH 1: Sort the array
Time Complexity: O(N*logN)
Space Complexity: O(1)
 */

/* APPROACH 2: Counting sort
Time Complexity: O(N) + O(N)
Space Complexity: O(K),. Here K = 3 => Constant space
 */

/* APPROACH 3: Partition using 3-Pointers  (Dutch National Flag)

*/

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortColors(int* nums, int numsSize){
    /* 0 to j - 1 ==> 0
    j to i - 1 ==> 1
    i to k ==> unknown
    k + 1 to n - 1 ==> 2
     */

    int i = 0, j = 0, k = numsSize - 1;
    while(i <= k) {
        if(nums[i] == 0) {
            swap(nums, i, j);
            ++i;
            ++j;
        } else if(nums[i] == 1) {
            ++i;
        } else {
            swap(nums, i, k);
            --k;
        }
    }
}

