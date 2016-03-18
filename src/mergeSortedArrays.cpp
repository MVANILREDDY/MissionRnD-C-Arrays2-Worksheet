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
int validator(char*);

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	struct transaction *merge;
	int i = 0, j = 0, index = 0, eval = 1, A_date, B_date;
	if (A&&B)// for NULL input validation.
	{
		int lenA = ALen, lenB = BLen;
		while (lenA)
		{
			eval = validator(A[lenA - 1].date);
			lenA--;
		}                           //this two while loops are to determine input dates are valid or not.
		while (lenB)
		{
			eval = validator(B[lenB - 1].date);
			lenB--;
		}
		if (eval) //if eval=1 all input dates are valid.if eval=0  input is invalid.
		{
			merge = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
			while (index<(ALen + BLen))
			{
				A_date = (10 * A[i].date[0]+ A[i].date[1]) + (10 * A[i].date[3] + A[i].date[4]) * 31 + (1000 * A[i].date[6] + 100 * A[i].date[7] + 10 * A[i].date[8] + A[i].date[9]) * 31 * 12;
				B_date = (10 * B[j].date[0] + B[j].date[1]) + (10 * B[j].date[3] + B[j].date[4]) * 31 + (1000 * B[j].date[6] + 100 * B[j].date[7] + 10 * B[j].date[8] + B[j].date[9]) * 31 * 12;
				if (i<ALen&&j<BLen)//i and j are indexes for A and B arrays.
				{
					if (A_date <= B_date)   //A_date & B_date are given dates after converting them to integers based on day prototype.  
					{
						merge[index] = A[i];
						index++;
						i++;
					}
					else
					{
						merge[index] = B[j];
						index++;
						j++;
					}
				}
				else if (i >= ALen)
				{
					merge[index] = B[j];
					index++;
					j++;
				}
				else
				{
					merge[index] = A[i];
					index++;
					i++;
				}
			}
			return merge;
		}
		else return NULL;
	}
	else
	{
		return NULL;
	}
}
int validator(char* a)//used to check whether input dates are valid or not.
{
	int day, m, yr, x = 0;
	day = 10 * (a[0] - '0') + a[1] - '0';
	m = 10 * (a[3] - '0') + a[4] - '0';
	yr = 1000 * (a[6] - '0') + 100 * (a[7] - '0') + 10 * (a[8] - '0') + (a[9] - '0');
	if (yr != 0)
	{
		if (m < 13 && m>0)
		{
			if (m == 4 || m == 6 || m == 9 || m == 11)
			{
				if (day < 31 && day>0){ x = 1; }
			}
			else if (m == 2)
			{
				if ((yr % 4 == 0) && (yr % 100 != 0) || yr % 400 == 0)
				{
					if (day < 30 && day>0){ x = 1; }
				}
				else
				{
					if (day < 29 && day>0){ x = 1; }
				}
			}
			else
			{
				if (day < 32 && day>0){ x = 1; }
			}
			return x;
		}
	}
	return 0;
}
