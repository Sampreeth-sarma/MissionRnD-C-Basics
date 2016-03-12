/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int strcomp(char *, char *, int,int);
int checkValidity(char *, char *);

int isOlder(char *dob1, char *dob2) {
	int age;
	if ((age = checkValidity(dob1, dob2)) == -1)
	{
		return age;
	}
		if ((age = strcomp(dob1, dob2,6,4)) == 0)
		{
			if ((age = strcomp(dob1, dob2,3,2)) == 0)
			{
				if ((age = strcomp(dob1, dob2,0,2)) == 0)
				{
					return 0;
				}
				return age;
			}
				return age;

		}
		return age;

}
int strcomp(char *dob1, char*dob2, int start, int len)
{
	int i = start;
	while (i <= (start+len-1))
	{
		int ascii1 = (int)dob1[i];
		int ascii2 = (int)dob2[i];
		if (ascii1 >= 48 && ascii1 <= 57 && ascii2 >= 48 && ascii2 <= 57)
		{
			if (ascii1 == ascii2)
			{
				if (i != (start + len-1))
					i++;
				else
					return 0;
			}

			else if (ascii1 > ascii2)
				return 2;
			else if (ascii1 < ascii2)
				return 1;
		}
		else
			break;
		}
	if (i != (start+len-1))
	return -1;

}

int checkValidity(char *dob1, char *dob2)
{
	int i = 0, len1 = 0, len2 = 0;
	while (dob1[i] != '\0'){
		len1++; i++;
	}
	i = 0;
	while (dob2[i] != '\0'){
		len2++; i++;
	}
	i = 0;
	if (len1 != 10 || len2 != 10)
	{
		return -1;
	}

	

	while (dob1[i] != '\0')
	{
		int ascii1 = (int)dob1[i];
		int ascii2 = (int)dob2[i];
		if (i == 2 || i == 5)
		{
			if (ascii1 != 45 || ascii2 != 45)
				return -1;
			else
				i++;
		}
		else
		{
			if (ascii1 >= 48 && ascii1 <= 57 && ascii2 >= 48 && ascii2 <= 57)
				i++;
			else
				return -1;
		}

	}
	int yr1 = ((int)(dob1[8]-48) * 10 + (int)(dob1[9]-48))%4;
	int yr2 = ((int)(dob1[8] - 48) * 10 + (int)(dob1[9] - 48)) % 4;
	if (yr1 == 0)
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >29)
				return -1;
		}
	}
	else
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >28)
				return -1;
		}
	}
	if (yr2 == 0)
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >29)
				return -1;
		}
	}
	else
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >28)
				return -1;
		}
	}
	if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) > 12)
	{
		return -1;
	}
	if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) > 31)
		return -1;
	else
		return 0;
	

}


