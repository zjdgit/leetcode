/*
����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����

ʾ��:

����: ["eat", "tea", "tan", "ate", "nat", "bat"]
���:
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