/* ALLOCATE MINIMUM NUMBER OF PAGES:

Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Example :

Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed 
in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 
      2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student
      2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 
      1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.
 */
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &bookPages, const int &m, const int &curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;
 
    // iterate over all books
    for (const int &bookPage:bookPages) {
        // check if current number of pages are greater
        // than curr_min that means we will get the result
        // after mid no. of pages
        if (bookPage > curr_min)
            return false;
 
        // count how many students are required
        // to distribute curr_min pages
        if (curr_sum + bookPage > curr_min) {
            // increment student count
            studentsRequired++;
 
            // update curr_sum
            curr_sum = bookPage;
 
            // if students required becomes greater
            // than given no. of students,return false
            if (studentsRequired > m)
                return false;
        }
 
        // else update curr_sum
        else
            curr_sum += bookPage;
    }
    return true;
}

int allocateMinimunPages(vector<int> &bookPages, const int &kids) {
	if(kids > bookPages.size()) return -1;
	long sum = 0, maxElement = - (1l<<32);
	for(const int bookPage : bookPages) {
		if(bookPage > maxElement) maxElement = bookPage;
		sum += bookPage;
	}
	
	int start = maxElement, end = sum, result = -1;
	while(start < end) {
		const int mid = start + (end - start) / 2;
		isPossible(bookPages,kids,mid) ? (end = mid - 1, result = mid) : start = mid + 1;
	}
	return result;
	
}

// Driver Function
int main() {
	vector <int> noOfPages = {
		10,20,30,40
		// 1,2,3,4,5,6,7,8,9,10
		// 3,2,2,4,1,4
		// 1,2,3,1,1
	};
	const int noOfChildren = 
		2
		// 5
		// 3
		// 4
	;
	int ans = allocateMinimunPages(noOfPages, noOfChildren);
	if(ans == -1) cout << "Not Possible\n";
	else cout << "Minimum number of pages = " << ans << "\n";
}