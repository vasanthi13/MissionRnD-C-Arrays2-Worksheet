/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if(A==NULL) 
		return NULL;
	if (B == NULL)
		return NULL;
	if (ALen < 0 || BLen < 0)
		return NULL;
	struct transaction *a;
	a = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int i, j, k, l, m = 0, n = 0,d1=0,d2=0,m1=0,m2=0,y1=0,y2=0,r;
	for (l = 0; l < ALen + BLen; l++,m++,n++)
	{
		d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
		if (m < ALen)
		{
			for (i = 0; A[m].date[i] != '-'; i++)
			{
				r = (int)A[m].date[i] - 48;
				d1 = d1 * 10 + r;
			}
			for (j = i + 1; A[m].date[j] != '-'; j++)
			{
				r = (int)A[m].date[j] - 48;
				m1 = m1 * 10 + r;
			}
			for (k = j + 1; A[m].date[k] != '\0'; k++)
			{
				r = (int)A[m].date[k] - 48;
				y1 = y1 * 10 + r;
			}
		}
		if (n < BLen)
		{
			for (i = 0; B[n].date[i] != '-'; i++)
			{
				r = (int)B[n].date[i] - 48;
				d2 = d2 * 10 + r;
			}
			for (j = i + 1; B[n].date[j] != '-'; j++)
			{
				r = (int)B[n].date[j] - 48;
				m2 = m2 * 10 + r;
			}
			for (k = j + 1; B[n].date[k] != '\0'; k++)
			{
				r = (int)B[n].date[k] - 48;
				y2 = y2 * 10 + r;
			}
		}
		if (m == ALen)
		{
			while (n < BLen)
			{
				d2 = 0, m2 = 0, y2 = 0;
				for (i = 0; B[n].date[i] != '-'; i++)
				{
					r = (int)B[n].date[i] - 48;
					d2 = d2 * 10 + r;
				}
				for (j = i + 1; B[n].date[j] != '-'; j++)
				{
					r = (int)B[n].date[j] - 48;
					m2 = m2 * 10 + r;
				}
				for (k = j + 1; B[n].date[k] != '\0'; k++)
				{
					r = (int)B[n].date[k] - 48;
					y2 = y2 * 10 + r;
				}
				a[l] = B[n];
				n++;
				l++;
			}
			break;
		}
		if (n == BLen)
		{
			while (m < ALen)
			{
				d1 = 0, m1 = 0, y1 = 0;
				for (i = 0; A[m].date[i] != '-'; i++)
				{
					r = (int)A[m].date[i] - 48;
					d1 = d1 * 10 + r;
				}
				for (j = i + 1; A[m].date[j] != '-'; j++)
				{
					r = (int)A[m].date[j] - 48;
					m1 = m1 * 10 + r;
				}
				for (k = j + 1; A[m].date[k] != '\0'; k++)
				{
					r = (int)A[m].date[k] - 48;
					y1 = y1 * 10 + r;
				}
				a[l] = A[m];
				m++;
				l++;
			}
			break;
		}
		if (y1 < y2)
		{
			a[l] = A[m];
			n--;
		}
		if (y2 < y1)
		{
			a[l] = B[n];
			m--;
		}
		if (y1 == y2)
		{
			if (m1 < m2)
			{
				a[l] = A[m];
				n--;
			}
			if (m2 < m1)
			{
				a[l] = B[n];
				m--;
			}
			if (m1 == m2)
			{
				if (d1 < d2)
				{
					a[l] = A[m];
					n--;
				}
				if (d2 < d1)
				{
					a[l] = B[n];
					m--;
				}
				if (d1 == d2)
				{
					a[l] = A[m];
					l++;
					a[l] = B[n];
				}
			}
		}
	}
	return a;
}