#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//if (s.empty()) return 0;
		//string temp, res = "";
		//temp += s[0];
		//res = temp;

		//for (int i = 1; i < s.size(); i++){
		//	auto ind = temp.find(s[i]);
		//	if (ind != string::npos){
		//		temp.erase(0, ind + 1);
		//		temp += s[i];
		//	}
		//	else
		//		temp += s[i];
		//	if (temp.length()>res.length()) res = temp;
		//}
		//cout << res << endl;
		//return res.size();
		bool h[256] = { false };
		int l = 0, ans = 0;
		for (int i = 0, sz = s.size(); i < sz; i++) {
			char c = s[i];
			if (h[c]) {
				while (h[c]) h[s[l++]] = false;
			}
			else {
				ans = (ans>i - l + 1)?ans:i-l+1;
			}
			h[c] = true;
		}
		return ans;
	}
};