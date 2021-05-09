/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/
class Solution {
public:
	bool isValid(string s) {
		std::stack<char> stack;
		unordered_map<char, char> mMap;
		mMap[')'] = '(';
		mMap[']'] = '[';
		mMap['}'] = '{';
		for (char c : s)
		{
			if (c == '(' || c == '{' || c == '[')
			{
				stack.push(c);
			}
			else
			{
				if (stack.empty())
					return false;
				char tmp = stack.top();
				if (mMap[c] != tmp)
					return false;
				else
					stack.pop();
			}
		}
		return stack.empty() ? true : false;
	}
};