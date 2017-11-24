#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string Res;
		if (numRows == 1) return s;
		int j;
		int L = 2 * (numRows - 1);
		for (int i = 0; i < numRows; i++){
			j = 0;
			while (i + L*j < s.length()){
				Res += s[i + L*j];
				if (i != 0 && i != numRows - 1 && L*(j + 1) - i<s.length()){
					Res += s[L*(j + 1) - i];
				}
				j++;
			}
		}
		return Res;
	}
};