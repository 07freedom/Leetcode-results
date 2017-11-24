#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += '#';
		}
		int* P = new int[t.size()];
		memset(P, 0, sizeof(string)*t.size());
		int Mi = 0, Right = 0;
		for (int i = 0; i<t.size(); i++){
			cout << P[i+1] << '\t';
			*P[i] = Right > i ? min(*P[2 * Mi - i], Right - i) : 1; //从之前数据推断回文
			while (t[i - P[i]] == t[i + P[i]]){
				++P[i];//继续找
			}
			if (P[i]>P[Mi]) {
				Mi = i;
				Right = Mi + P[i] - 1;
			}
		}
		string res = s.substr((Mi - P[Mi]) / 2, P[Mi] - 1);
		delete[] P;
		return 

	}
};

//class Solution {
//public:
//	string longestPalindrome(string s) {
//		string t = "$#";
//		for (int i = 0; i < s.size(); ++i) {
//			t += s[i];
//			t += '#';
//		}
//		int P[t.size()] = { 0 }, Mi = 0, Right = 0;
//		for (int i = 0; i<t.size(); i++){
//			P[i] = Right > i ? min(P[2 * Mi - i], Right - i) : 1; //从之前数据推断回文
//			while (t[i - P[i]] == t[i + P[i]]){
//				++P[i];//继续找
//			}
//			cout << P[i] << '\t';
//			if (P[i]>P[Mi]) {
//				Mi = i;
//				Right = Mi + P[i] - 1;
//			}
//		}
//		return s.substr((Mi - P[Mi]) / 2, P[Mi] - 1);
//	}
//};