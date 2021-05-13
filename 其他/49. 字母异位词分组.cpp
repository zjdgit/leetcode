/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		if (strs.empty())
			return res;

		unordered_map<string, vector<string>> mMap;
		for (string str : strs)
		{
			string tmp(str);
			sort(tmp.begin(), tmp.end());
			mMap[tmp].push_back(str);
		}

		for (auto it = mMap.begin(); it != mMap.end(); it++)
		{
			res.push_back(it->second);
		}

		return res;
	}
};