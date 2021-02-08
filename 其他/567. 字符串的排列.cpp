/*
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False

*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		unordered_map<char, int> need, window;
		int left = 0, right = 0;
		int valid = 0;
		for (char c : s1)
		{
			need[c]++;
		}

		while (right < s2.size())
		{
			char c = s2[right];
			right++;
			if (need.count(c))
			{
				window[c]++;
				if (window[c] == need[c])
				{
					valid++;
				}
			}
			while (right - left == s1.size())
			{
				if (valid == need.size())
				{
					return true;
				}
				char d = s2[left];
				left++;
				if (need.count(d))
				{
					if (need[d] == window[d])
					{
						valid--;
					}
					window[d]--;
				}
			}
		}
		return false;
	}
};