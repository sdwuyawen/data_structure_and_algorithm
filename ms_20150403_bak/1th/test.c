#include <stdio.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

int desired_x, desired_y, desired_z;
char input_sequence[20000] = {0};


int num_max = 0;
int num_now = 0;

int num_red = 0;
int num_yellow = 0;
int num_blue = 0;

int abs_int(int value)
{
	if(value < 0)
		return -value;
	else
		return value;
}

int process_ball(char input_sequence)
{
	int delta_A = 0;
	int delta_B = 0;
	int delta_C = 0;

	int match_flag = FALSE;
	
	num_now++;		//当前球个数+1
	if(num_now > num_max)
	{
		num_max = num_now;	//保存最大值
	}

	switch (input_sequence)
	{
		case 'R':
			num_red++;
			break;

		case 'Y':
			num_yellow++;
			break;

		case 'B':
			num_blue++;
			break;

		default:
			break;
	}

	delta_A = abs_int(num_red - num_yellow);
	delta_B = abs_int(num_yellow - num_blue);
	delta_C = abs_int(num_blue - num_red);

	if(delta_A == desired_x)
	{
		if(delta_B == desired_y)
		{
			if(delta_C == desired_z)
			{
				match_flag = TRUE;
			}
		}
		else if(delta_B == desired_z)
		{
			if(delta_C == desired_y)
			{
				match_flag = TRUE;
			}
		}
	}
	else if(delta_A == desired_y)
	{
		if(delta_B == desired_x)
		{
			if(delta_C == desired_z)
			{
				match_flag = TRUE;
			}
		}
		else if(delta_B == desired_z)
		{
			if(delta_C == desired_x)
			{
				match_flag = TRUE;
			}
		}
	}
	else if(delta_A == desired_z)
	{
		if(delta_B == desired_x)
		{
			if(delta_C == desired_y)
			{
				match_flag = TRUE;
			}
		}
		else if(delta_B == desired_y)
		{
			if(delta_C == desired_x)
			{
				match_flag = TRUE;
			}
		}
	}

	if(match_flag == TRUE)		//匹配
	{
		num_now = 0;			//清空球
		num_red = 0;
		num_yellow = 0;
		num_blue = 0;
	}

	return 0;
}

int main(void) 
{
    int loop_count = 0;
	int num_total = 0;

	scanf("%d%d%d", &desired_x, &desired_y, &desired_z);
//	printf("%d %d %d\r\n", desired_x, desired_y ,desired_z);
	
	scanf("%s", input_sequence);
//	printf("%s\r\n" ,input_sequence);
	
	num_total = strlen(input_sequence);
	
//	printf("num_total=%d\r\n",num_total);
	
	for(loop_count = 0; loop_count < num_total; loop_count++)	//循环放入球
	{
		process_ball(input_sequence[loop_count]);
	}
	
//	printf("num_total=%d\r\n",num_total);
//	printf("num_max=%d\r\n",num_max);
//	printf("num_now=%d\r\n",num_now);
	
	printf("%d\r\n",num_max);

    return 0;
}
