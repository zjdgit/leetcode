/*
请你设计一个迭代器类，包括以下内容：

一个构造函数，输入参数包括：一个 有序且字符唯一 的字符串 characters（该字符串只包含小写英文字母）和一个数字 combinationLength 。
函数 next() ，按 字典序 返回长度为 combinationLength 的下一个字母组合。
函数 hasNext() ，只有存在长度为 combinationLength 的下一个字母组合时，才返回 True；否则，返回 False。

*/


class CombinationIterator {
private:
	bool bFinished;
	string m_str;
	vector<int> m_vecPos;

public:
	CombinationIterator(string characters, int combinationLength) {
		bFinished = false;
		m_str = characters;
		m_vecPos.resize(combinationLength);
		iota(m_vecPos.begin(), m_vecPos.end(), 0);
	}

	string next() {
		string ans;
		int len = m_vecPos.size();
		for (int i : m_vecPos)
		{
			ans += m_str[i];
		}
		int i = -1;

		//判断当前数组是否为最大数组，即数组每个位置都为最大值
		for (int k = len - 1; k >= 0; k--)
		{
			if (m_vecPos[k] != m_str.length() - len + k)
			{
				// i为最后一个当前位置不是最大值的情况
				i = k;
				break;
			}
		}
		if (i == -1)
			bFinished = true;
		else
		{
			++m_vecPos[i];
			for (int j = i + 1; j < len; j++)
			{
				m_vecPos[j] = m_vecPos[j - 1] + 1;
			}
		}
		return ans;
	}

	bool hasNext() {
		return !bFinished;
	}
};