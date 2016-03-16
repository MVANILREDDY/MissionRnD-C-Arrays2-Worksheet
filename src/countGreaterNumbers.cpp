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
int validation(char*);
int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	if (Arr&&date)
	{
		int i = 0, g_date, a_date, count = 0, eval = 1;
		g_date = 10 * (date[0] - '0') + date[1] - '0' + (10 * date[3] + date[4] - 11 * '0') * 31 + (1000 * date[6] + 100 * date[7] + 10 * date[8] + date[9] - 1111 * '0') * 31 * 12;
		while (i<len)
		{
			eval = validation(date)*validation(Arr[i].date);// eval is used to check input dates are valid or not.
			if (eval)
			{
				a_date = 10 * (Arr[i].date[0] - '0') + Arr[i].date[1] - '0' + (10 * Arr[i].date[3] + Arr[i].date[4] - 11 * '0') * 31 + (1000 * Arr[i].date[6] + 100 * Arr[i].date[7] + 10 * Arr[i].date[8] + Arr[i].date[9] - 1111 * '0') * 31 * 12;
				if (g_date<a_date)
					count++;
				i++;
			}
			else
			{
				return -1;
			}
		}
		return count;
	}
	return -1;
}

int validation(char* a)//function to check whether given input dates are valid or not.
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
			return x;//x  value detemines whether date valid or not.if x=1,date is valid,else not valid
		}
	}
	return 0;
}


