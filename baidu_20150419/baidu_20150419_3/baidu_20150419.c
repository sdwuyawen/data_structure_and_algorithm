#include <stdio.h>
#include <string.h>

unsigned int input[10010];
unsigned int output[10010];

int abs(int val)
{
	if(val < 0)
		return (-val);
	else
		return val;
}


int main(void)
{
	unsigned int sum = 0;
	int num_per_line = 0;
	unsigned int value;

	unsigned int T;
	unsigned int T_count;

	int i;
	int j;
	int count;
	int k;

//	scanf("%d", &T);
//	for(T_count = 0; T_count < T; T_count++)
	{
		scanf("%d", &num_per_line);
		count = 0;
		for(i = 0; i < num_per_line; i++)
		{
			scanf("%d", &input[count]);
//			scanf("%d", &value);
			for(j = count - 1; j >= 0; j--)
			{
				if(input[count] == input[j])		//Ĩȥ
				{
					count = j;
				}
			}

			count++;
		}
		
		printf("%d", input[count - 1]);
		printf("->");
		for(k = count - 2; k > 0; k--)
		{
			printf("%d", input[k]);
			printf("->");
		}
		printf("%d", input[0]);
		printf("\n");
		
	}

	return 0;
}