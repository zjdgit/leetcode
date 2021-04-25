/*
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和 year，分别表示日、月、年。

您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

*/

class Solution {
public:
	string dayOfTheWeek(int day, int month, int year) {
		const string ch[] = { "Thursday", "Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday" };
		const int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30,31,30,31 };
		int yeardif = year - 1970;
		int daydif = -1;
		for (int i = 1; i < month; i++)
		{
			daydif += mon[i];
		}
		daydif += day;

		daydif += (365 * yeardif);
		if (yeardif < 2)
		{

		}
		else
		{
			int rYear = (yeardif - 2) / 4 + 1;
			if ((yeardif - 2) % 4 == 0)
			{
				if (year % 100 == 0 && year % 400 != 0)
				{
					daydif = daydif + rYear - 1;
				}
				else
				{
					if (month > 2)
					{
						daydif = daydif + rYear;
					}
					else
					{
						daydif = daydif + rYear - 1;
					}
				}
			}
			else
			{
				daydif = daydif + rYear;
			}
		}
		int mod = daydif % 7;
		return ch[mod];
	}
};