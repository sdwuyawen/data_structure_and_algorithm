#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//#define max(a,b) (a > b ? a : b)
//#define min(a,b) (a < b ? a : b)
#define MAXN 1010
 
int matrix[MAXN][MAXN];
int lagest_rectangle(int m, int n) 
{
    int i, j;
    int *H = (int*) malloc(n * sizeof(int)); // 高度
    int *L = (int*) malloc(n * sizeof(int)); // 左边界
    int *R = (int*) malloc(n * sizeof(int)); // 右边界
    int ret = 0;
    memset(H, 0, n * sizeof(int));
    memset(L, 0, n * sizeof(int));
    for (i = 0; i < n; i++) R[i] = n;
    for (i = 0; i < m; ++i)					//行
	{
        int left = 0, right = n;
        // calculate L(i, j) from left to right
        for (j = 0; j < n; ++j)				//列
		{
            if (matrix[i][j] == 1) 
			{
                ++H[j];
                L[j] = max(L[j], left);
            } 
			else 
			{
                left = j + 1;
                H[j] = 0;
                L[j] = 0;
                R[j] = n;
            }
        }
        // calculate R(i, j) from right to left
        for (j = n - 1; j >= 0; --j) 
		{
            if (matrix[i][j] == 1) 
			{
                R[j] = min(R[j], right);
                ret = max(ret, H[j] * (R[j] - L[j]));
            }
            else 
			{
                right = j;
            }
        }
    }
    return ret;
}
int main() 
{
    int m, n;
    int i, j;
    while (scanf("%d%d", &m, &n) > 0) 
	{
        for (i = 0; i < m; i++) 
		{
            for (j = 0; j < n; j++) 
			{
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("%d\n", lagest_rectangle(m, n));
    }
    return 0;
}