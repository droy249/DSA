/* Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.

Note: The distance between two points on a plane is the Euclidean distance.

Example:
Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2 
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

long distanceFromOrigin(pair<int,int> &point){
	return point.first*point.first + point.second*point.second;
}

vector<pair<int,int>> kClosestPointsToOrigin(vector<pair<int,int>> &points, const int &k){
	priority_queue<pair<long,int>> maxHeap;
	for(int i{}; i < points.size(); ++i){
		maxHeap.emplace(distanceFromOrigin(points.at(i)),i);
		if(maxHeap.size() > k)
			maxHeap.pop();
	}
	vector<pair<int,int>> ans;
	while(!maxHeap.empty()){
		ans.emplace_back(points.at(maxHeap.top().second));
		maxHeap.pop();
	}
	return ans;
}

int main(){
	vector<pair<int,int>> points{{3, 3}, {5, -1}, {-2, 4}};
	const int k = 2;
	vector<pair<int,int>> ans{kClosestPointsToOrigin(points,k)};
	cout << "The " << k << " closest point to (0,0) are: " << endl;
	for(const pair<int,int> point : ans)
		cout << point.first << ' ' << point.second << endl;
	cout << endl;
}