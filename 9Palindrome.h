#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		const int max = 0x7fffffff;  //int最大值  
		const int min = 0x80000000;  //int最小值  
		if (x > max || x < min || x == 0){
			return false;
		}
		int m = x;
		vector<int> M;
		while (m != 0){
			//cout << m % 10 << endl;
			M.push_back(m % 10);
			m = m / 10;
		}
		for (int i = 0; i <= M.size() / 2; i++){
			if (M[i] != M[M.size() - i - 1]){
				return false;
			}
		}
		return true;
	}
};

//#include "9Palindrome.h"
//void main(){
//	Solution a;
//	int target = -2147447412;
//	bool answer = a.isPalindrome(target);
//	cout << answer << endl;
//}