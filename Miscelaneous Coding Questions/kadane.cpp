// C++ program to print largest contiguous array sum
// also known as Kadane's algortithm for the same
// Given algorithm below works for both positve and negative arrays.

#include <iostream>
using namespace std;

int largestSubstringSum(int a[], int n) {
    int largest_so_far = 0;
    int current_largest = 0;
    for(int i = 0; i < n; ++i){
        current_largest = max(current_largest + a[i], a[i]);
        largest_so_far = max(largest_so_far, current_largest);
    }
    return largest_so_far;
}

/*The following program is to print the subarray itself with 
  longest contiguous sum.  
*/ 
// #include <climits>
// int largestSubstringSum(int a[], int size)
// {
//     int max_so_far = INT_MIN, max_ending_here = 0,
//        start =0, end = 0, s=0;
 
//     for (int i=0; i< size; i++ )
//     {
//         max_ending_here += a[i];
 
//         if (max_so_far < max_ending_here)
//         {
//             max_so_far = max_ending_here;
//             start = s;
//             end = i;
//         }
 
//         if (max_ending_here < 0)
//         {
//             max_ending_here = 0;
//             s = i + 1;
//         }
//     }
//     cout << "Maximum contiguous sum is "
//         << max_so_far << endl;
//     cout << "Starting index "<< start
//         << endl << "Ending index "<< end << endl;
// }

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};//{23,34,11,4,45,34,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum contiguous sum is " << largestSubstringSum(arr, n) << endl;
}