#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void printres(vector<double>res){
		for (int x = 0; x < res.size(); x++){
			cout << res[x] << '\t';
		}
		cout << endl;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int i = 0, j = 0;
		vector<double> M;
		vector<double>::iterator iter1;
		vector<double>::iterator iter2;
		if (nums1.empty()) nums1 = nums2;
		if (nums2.empty()) nums2 = nums1;

		int lm = (nums1.size() + nums2.size()) / 2 + 1;
		while (M.size() < lm){
			if (nums1[i] > nums2[j]) {
				M.push_back(nums2[j]);
				j++;
			}
			else {
				M.push_back(nums1[i]);
				i++;
			};
			if (i == nums1.size() || j == nums2.size()) break;
		};
		printres(M);
		while (i<nums1.size() && M.size() < lm){
			M.push_back(nums1[i]);
			i++;
		}
		printres(M);
		while (j<nums2.size() && M.size() < lm){
			M.push_back(nums2[j]);
			j++;
		}
		printres(M);
		iter1 = M.end() - 2;
		iter2 = M.end() - 1;
		if ((nums1.size() + nums2.size()) % 2) return *iter2;
		else return (*iter1+*iter2)/2;
	}
};

//#include "4ArrayMedian.h"
//void main(){
//	vector<int> nums1, nums2;
//	nums1 = { 1, 2, 3 };
//	nums2 = { 2 };
//	Solution a;
//	cout << a.findMedianSortedArrays(nums1, nums2) << endl;
//}