/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

 

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
*/

class Solution {
public:
	string plusOne(string str, int cul)
	{
		if (str[cul] == '9')
		{
			str[cul] = '0';
		}
		else
		{
			str[cul] += 1;
		}
		return str;
	}

	string minusOne(string str, int cul)
	{
		if (str[cul] == '0')
		{
			str[cul] = '9';
		}
		else
		{
			str[cul] -= 1;
		}
		return str;
	}


	int openLock(vector<string>& deadends, string target) {
		queue<string> q;
		set<string> s;
		q.push("0000");
		s.insert("0000");
		for (auto it : deadends)
		{
			s.insert(it);
		}

		int depth = 0;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				string cul = q.front();
				q.pop();

				//找到死亡数组中的元素，跳过
				if (std::find(deadends.begin(), deadends.end(), cul) != deadends.end())
				{
					continue;
				}
				if (cul == target)
				{
					return depth;
				}

				//将相邻的元素添加到队列中
				for (int j = 0; j < 4; j++)
				{
					string up = plusOne(cul, j);

					//判断是否重复，包括死亡数组中的元素
					if (s.find(up) == s.end())
					{
						q.push(up);
						s.insert(up);
					}
					string down = minusOne(cul, j);

					//判断是否重复，包括死亡数组中的元素
					if (s.find(down) == s.end())
					{
						q.push(down);
						s.insert(down);
					}
				}
			}
			depth++;
		}
		return -1;
	}
};