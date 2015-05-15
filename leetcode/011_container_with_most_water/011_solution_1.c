int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int maxArea(int* height, int heightSize)
{
	int l = 0;
	int r = heightSize - 1;

	int ret = 0;

	while(l < r)
	{
		ret = max(ret, (r - l) * min(height[l], height[r]));

		if(height[l] < height[r])		//从左侧开始向里推进
		{
			l++;
		}
		else							//从右侧开始推进
		{
			r--;
		}
	}

	return ret;
}
