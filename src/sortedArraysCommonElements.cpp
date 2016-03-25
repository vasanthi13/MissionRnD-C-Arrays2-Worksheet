/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if(A==NULL||B==NULL)
		return NULL;
	if (ALen < 0 || BLen < 0)
		return NULL;
	struct transaction *a;
	a = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int i,flag, j, k, l=0, m = 0, n = 0, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0, r,c=0;
	for (m = 0; m < ALen ; m++)
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
		for (n = 0; n < BLen; n++)
		{
			flag = 0;
			 d2 = 0,  m2 = 0,  y2 = 0;
			
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
			if (y2 == y1)
			{
				if (m1 == m2)
				{
					if (d1 == d2)
					{
						a[l] = B[n];
						l++;
					}
					if (d1 < d2)
					{
						 break;
					}
				}
				if (m1 < m2)
				{
					break;
				}
			}
			if (y1 < y2)
			{
				break;
			}
		}
	}
	if (l==0)    return NULL;
	else return a;
	
	
		
}
