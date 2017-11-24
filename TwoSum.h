#include<iostream>
#include<vector>
using namespace std;

class twoSum {
public:
	vector<int> Solution(vector<int> &numbers, int target) {
		vector<int> results;
		for (int i = 0; i < numbers.size(); ++i){
			for (int j = i + 1; j < numbers.size(); ++j){
				if (numbers[i] + numbers[j] == target){
					results.push_back(i + 1);
					results.push_back(j + 1);
				}
			}
		}
		return results;
	}
};

//void main(){
//	vector<int> nums = { 1, 3, 4, 5 };
//	twoSum a;
//	int target = 9;
//	for (int i = 0; i < a.Solution(nums, target).size(); i++){
//		cout << a.Solution(nums, target)[i] << ' ';
//	}
//	cout << endl;
//}