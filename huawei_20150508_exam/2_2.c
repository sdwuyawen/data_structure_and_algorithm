#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	char str[100][50] = {0};
	int len;
	int i;
	int j;

	int sum = 0;
	int value = 0;

	i = 0;
	while(scanf("%s", &str[i][0]) != EOF)
	{
		if(i >= 32)
		{
			printf("ERROR");
			
			return 0;
		}

		len = strlen(&str[i][0]);

		for(j = 0; j < len; j++)
		{
			if(str[i][j] < '0' || str[i][j] > '9')
			{
				printf("ERROR");
				
				return 0;
			}
		}
		
		value = atoi(&str[i][0]);

		sum += value;

//		printf("%d\n", value);

		i++;
	}

	printf("%d", sum);
//	len = strlen(str);

	return 0;
}