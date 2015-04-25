#include <stdio.h>
#include <string.h>

unsigned int height[1010];

int abs(int val)
{
	if(val < 0)
		return (-val);
	else
		return val;
}


int main(void)
{
	unsigned __int64 sum = 0;
	unsigned int num_per_line = 0;

	unsigned int T;
	unsigned int T_count;

	unsigned int i;

	scanf("%d", &T);
	for(T_count = 0; T_count < T; T_count++)
	{
		scanf("%d", &num_per_line);
		for(i = 0; i < num_per_line; i++)
		{
			scanf("%d", &height[i]);
		}

		sum = 0;

		sum += 2 * height[0];

		for(i = 1; i < num_per_line; i++)
		{
			sum += 2 * abs(height[i] - height[i - 1]);
		}

		sum += 2 * height[num_per_line - 1];

		printf("%I64u\n", sum);
	}

	return 0;
}