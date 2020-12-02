/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�

*/

class Solution {
public:
	string longestPalindrome(string s) {
		string str("-");
		for (int i = 0; i < s.size(); i++)
		{
			str += s.at(i);
			str += '-';
		}
		int left = 0;
		int right = 0;
		int maxNum = 0;
		for (int i = 1; i < str.size(); i++)
		{
			int l = i - 1, r = i + 1;
			while (l >= 0 && r < str.size())
			{
				if (str[l] == str[r])
				{
					l--;
					r++;
				}
				else
					break;
			}
			if (r - l > maxNum)
			{
				maxNum = r - l;
				left = l + 1;
				right = r - 1;
			}
		}
		string ans = "";
		for (int i = left; i <= right; i++)
		{
			if (str[i] != '-')
				ans += str[i];
		}
		return ans;
	}
};