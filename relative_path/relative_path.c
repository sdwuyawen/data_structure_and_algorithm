#include <stdio.h>
#include <string.h>


//дһ���������������ļ��ľ���·��������·����
//�� a="/qihoo/app/a/b/c/d/new.c",b="/qihoo/app/1/2/test.c'����ôb�����a�����·����"../../../../1/2/test.c"

char *a = "/qihoo/app/a/b/c/d/new.c";
char *b = "/qihoo/app/1/2/test.c";

int relative_path(char *a, char *b)
{
	int len1, len2;
	int i;
	int ret_count;
	char *pa;
	char *pb;
	char *p;
	char relative[100];
	
	memset(relative, 0, sizeof(relative));
	
	//ͳ����ͬ��·������
	i = 0;
	while(a[i] == b[i])
	{
		i++;
	}
	
	//�õ���ͬ·�����׵�ַ
	//"a/b/c/d/new.c"
	//"1/2/test.c"
	pa = &a[i];
	pb = &b[i];
	
	len1 = strlen(pa);
	len2 = strlen(pb);
	
	//ͳ���践�صĴ���
	ret_count = 0;
	p = pa;
	while((p = strchr(p, '/')) != NULL)
	{
		ret_count++;
		p = p + 1;
	}
	
	printf("ret_count = %d\n", ret_count);
	
	//�������·��
	for(i = 0; i < ret_count; i++)
	{
		strcat(relative, "../");
	}
	strcat(relative, pb);
	
	printf("relative = %s\n", relative);
	
	return 0;
}



int main(void)
{
	char a[100];
	char b[100];

	scanf("%s", a);
	scanf("%s", b);

	relative_path(a,b);
	
	return 0;
}