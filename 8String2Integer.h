#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int sign = 1, base = 0, i = 0, n = str.size();
		while (i < n && str[i] == ' ') ++i;
		if (str[i] == '+' || str[i] == '-') {
			sign = (str[i++] == '+') ? 1 : -1;
		}
		while (i < n && str[i] >= '0' && str[i] <= '9') {//直接使用ACII编写计算
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			base = 10 * base + (str[i++] - '0');
		}
		return base * sign;
		//原版
		//string Str1 = "0 +-";
		//string Str2 = "0123456789";
		//int i = 0;
		//int Res = 0;
		//int NumPM = 0;
		//int DeRes = 1;
		//bool isZero = false;
		//while (Str1.find(str[i]) != -1 && Str2.find(str[i])==-1){
		//	if (Str1.find(str[i]) > 1) {
		//		isZero = true;
		//		if (Str1.find(str[i]) == 3) DeRes = -1;
		//		if (NumPM == 0){ 
		//			NumPM++; 
		//			i++;
		//		}
		//		else return 0;
		//		continue;
		//	}
		//	if (Str1.find(str[i]) == 0) isZero = true;
		//	if (isZero && Str1.find(str[i]) != 0) return 0;
		//	//cout<<str[i++];
		//	i++;
		//}
		////cout << "___"<<endl;

		//while (Str2.find(str[i]) != -1){
		//	Res = Res * 10 + Str2.find(str[i++]);
		//}

		//Res = DeRes*Res;
		//return Res;
	}
};