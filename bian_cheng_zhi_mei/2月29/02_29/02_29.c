#include <stdio.h>
#include <string.h>

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

char *strMonth[] = 
{
	"January", 
	"February", 
	"March", 
	"April", 
	"May", 
	"June", 
	"July", 
	"August", 
	"September", 
	"October", 
	"November" , 
	"December"
};

char month_start_str[20];
unsigned int month_start;
unsigned int day_start;
unsigned int year_start;

char month_end_str[20];
unsigned int month_end;
unsigned int day_end;
unsigned int year_end;

unsigned int is_leap_year(unsigned int year)
{
	if(year % 4 == 0 && year % 100 != 0)
	{
		return TRUE;
	}

	if(year % 400 == 0)
	{
		return TRUE;
	}

	return FALSE;
}

int main(void)
{
	unsigned int i,j;
	unsigned int T;
	unsigned int num_0229 = 0;
	unsigned char start_OK = FALSE;
	unsigned char end_OK = FALSE;

	scanf("%d", &T);

	for(i = 0; i < T; i++)
	{
		num_0229 = 0;
		start_OK = FALSE;
		end_OK = FALSE;

		scanf("%s %d, %d", month_start_str, &day_start, &year_start);
		scanf("%s %d, %d", month_end_str, &day_end, &year_end);

		for(j = 0; j < 12; j++)
		{
			if(strcmp(month_start_str, strMonth[j]) == 0)
			{
				month_start = j + 1;
				break;
			}
		}

		for(j = 0; j < 12; j++)
		{
			if(strcmp(month_end_str, strMonth[j]) == 0)
			{
				month_end = j + 1;
				break;
			}
		}
		
		if(year_start == year_end)				//开始和结束是同一年
		{
			if(is_leap_year(year_start))		//是闰年
			{
				if(month_start <= 2)
				{
					start_OK = TRUE;
				}

				if(month_end == 2 && day_end >= 29)
				{
					end_OK = TRUE;
				}
				else if(month_end >= 3)
				{
					end_OK = TRUE;
				}

				if(start_OK == TRUE && end_OK == TRUE)
				{
					num_0229++;
				}
			}
			else
			{
				num_0229 = 0;
			}
		}
		else									//开始和结束不是同一年
		{
			//判断起始年是否包含0229
			if(is_leap_year(year_start))		//是闰年
			{
				if(month_start <= 2)
				{
					num_0229++;
				}
			}

			//判断结束年是否包含0229
			if(is_leap_year(year_end))		//是闰年
			{
				if(month_end == 2 && day_end >= 29)
				{
					num_0229++;
				}
				else if(month_end >= 3)
				{
					num_0229++;
				}
			}

			//判断中间年份
			for(j = year_start + 1; j < year_end; j++)
			{
				if(is_leap_year(j))
				{
					num_0229++;
				}
			}
		}

		printf("Case #%d: %d\n", i+1, num_0229);

	}
}