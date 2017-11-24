#include<iostream>
using namespace std;

class Solution {
	//321->123
public:
	int reverse(int x) {
		int temp;
		const int max = 0x7fffffff;  //int最大值  
		const int min = 0x80000000;  //int最小值  
		long long sum = 0;
		while (x != 0){
			temp = x % 10;
			x = x / 10;
			sum = sum * 10 + temp;
			if (sum > max || sum < min){
				//sum = sum > 0 ? max : min;
				return 0;
			}
		}
		return sum;
	}
};

//#include "7ReverseInteger.h"
//void main(){
//	int target = 12345;
//	Solution a;
//	cout << a.reverse(target) << endl;
//}