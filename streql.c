/**
 *streql - comapre two strig
 *@str1: first string
 *@str2: secod string
 *Return: 1 Equall string
*/
int streql(char  *str1, char *str2)
{       int loc;
	int eql = 1;

	loc = 0;

	while (str1[loc] != '\0')
	{
		if (str1[loc] != str2[loc])
		{
			eql  = 0;
			break;
		}
		loc++;
	}

	return (eql);
}
