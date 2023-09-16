/**
 * str_search - search string witin string
 * @stri: need
 * @str2: haystack
 * REturn: 1 found, 0 not found
 */


int str_search(char *str1, char *str2)
{
	int loc;
	int found;
	
	loc = 0;
	found = 0;

	while (str1[loc] != '\0')
	{
		if (str1[loc] != str2[loc])
		{
			found = 0 ;
			break;
		}

		else
		{
			found = 1;
		}

		loc++;
	}

	return (found);
}

