/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
class Solution {
public:
	vector<string> m_res;
	string m_digits;
	unordered_map<char, string> m_store;

	void dfs(string strRes, int size)
	{
		int totalSize = m_digits.size();
		if (size == totalSize)
		{
			m_res.push_back(strRes);
			return;
		}
		char target = m_digits[size];
		string targetStr = m_store[target];
		for (char it : targetStr)
		{
			dfs(strRes + it, size + 1);
		}
		return;
	}

	vector<string> letterCombinations(string digits) {
		if (digits.empty())
		{
			return m_res;
		}
		m_digits = digits;
		m_store = unordered_map<char, string>{
			{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
		dfs("", 0);

		return m_res;
	}
};