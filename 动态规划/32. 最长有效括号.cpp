/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
*/
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;

		int size = s.size();
		vector<int> dp(size, 0);
		dp[0] = 0;
		for (int i = 1; i < size; i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				}
				else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				}
			}
		}

		int res = *std::max_element(dp.begin(), dp.end());
		return res;
	}
};