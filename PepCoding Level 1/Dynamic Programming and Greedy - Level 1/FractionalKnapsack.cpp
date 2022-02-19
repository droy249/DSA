// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/fractional-knapsack-official/ojquestion
// Video Link(PepCoding): https://youtu.be/tUiJu5DYO1Y
// Video Link(Apna College): https://youtu.be/2i5pclQprGk
// GeeksForGeeks Link: https://www.geeksforgeeks.org/fractional-knapsack-problem/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define value first
#define weight second

int main(){
	// cout << "Enter the number of items: ";
	// int n; cin >> n;
	
	// pair<float, float> items[n];
	
	// printf("Enter values of %d items: ", n);
	// for(auto &item : items)
		// cin >> item.value;
	
	// printf("Enter weights of %d items: ", n);
	// for(auto &item : items)
		// cin >> item.weight;
	
	// cout << "Enter weight of knapsack: ";
	// int givenWeight; cin >> givenWeight;
	
	pair<float, float> items[] = {{21, 7}, {24, 4}, {12, 6}, {40, 5}, {30, 6}};
	int n = 5;
	int givenWeight = 20;
	
	// Sorting all items on basis of ratios of value/weight
	sort(items, items + n, [&](const auto& a, const auto& b){
		return (a.value / a.weight) > (b.value / b.weight);
	});
	
	int maxValue{};
	
	for(const auto &item : items){
		if(givenWeight >= item.weight){
			givenWeight -= item.weight;
			maxValue += item.value;
			continue;
		} 
		
		maxValue += item.value / item.weight * givenWeight;
		break;
	}
	
	cout << "Maximum possible value is " << maxValue << endl;
}