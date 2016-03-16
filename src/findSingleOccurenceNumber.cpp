/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int findSingleOccurenceNumber(int *A, int len)
{
	if (A&&len % 3 == 1 && len != 1)//for NULL input and invalid length.
	{
		int i = 0, j = 1, count = 0, unique = 0;
		while (i<len - 1)    // while loop is used for finding all elements in the  given array with single occurance.
		{
			if (A[i] == A[j])
			{
				unique = unique + A[i];
				A[i] = 0;
				i++;
				count++;
				j = i + 1;
			}
			else if (j == len - 1)
			{
				i++;
				j = i + 1;
			}
			else
			{
				j++;
			}
		}
		count = count + len / 3 + 1;
		if (count == len) //for determining whether input is valid or not.
		{
			unique = -unique / 2;
			for (i = 0; i<len; i++)//used for finding unique element in the given array
			{
				unique = unique + A[i];
			}
			return (unique);
		}

	}
	return -1;
}
