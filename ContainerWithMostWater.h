#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		vector<int> res;
		int h, nMin = 0, nMax = height.size() - 1, Area = 0;
		while (nMin != nMax){
			h = height[nMin] < height[nMax] ? height[nMin] : height[nMax];
			Area = (nMax - nMin)*h > Area ? (nMax - nMin)*h : Area;
			height[nMin] < height[nMax] ? nMin++ : nMax--;
		}
		return Area;
	}
};