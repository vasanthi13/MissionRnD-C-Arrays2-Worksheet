/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if(Arr==nullptr) return -1;
	if (len < 0) return -1;
	int d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0, c = 0, flag = 0,i,j,k,r,l;

	for (i = 0; date[i] != '-'; i++)
	{
		r = (int)date[i] - 48;
		d1 = d1 * 10 + r;
	}
	for (j = i + 1;date[j] != '-'; j++)
	{
		r = (int)date[j] - 48;
		m1 = m1 * 10 + r;
	}
	for (k = j + 1; date[k] != '\0'; k++)
	{
		r = (int)date[k] - 48;
		y1 = y1 * 10 + r;
	}
	for (l = 0; l < len; l++)
	{
		d2 = 0, m2 = 0, y2 = 0;
		flag = 0;
		for (i = 0; Arr[l].date[i] != '-'; i++)
		{
			r = (int)Arr[l].date[i] - 48;
			d2 = d2 * 10 + r;
		}
		for (j = i + 1; Arr[l].date[j] != '-'; j++)
		{
			r = (int)Arr[l].date[j] - 48;
			m2 = m2 * 10 + r;
		}
		for (k = j + 1; Arr[l].date[k] != '\0'; k++)
		{
			r = (int)Arr[l].date[k] - 48;
			y2 = y2 * 10 + r;
		}
		if (y2>y1)
		{
			flag = 1;
			c++;
		}
		if (y2 == y1)
		{
			if (m2 > m1)
			{
				flag = 1;
				c++;
			}
			if (m1 == m2)
			{
				if (d2 > d1)
				{
					flag = 1;
					c++;
				}
			}
		}
	}
	if (flag == 0) return 0;
	else return c;
}
