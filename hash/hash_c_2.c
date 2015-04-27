#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 26
#define FILENAMELENGTH 20
#define TRUE 1
#define FALSE 0

struct file
{
    char name[FILENAMELENGTH];
    struct file *next;
};

struct file * files[HASHSIZE];	//hash table

/**将大写字符转为小写字母，本程序中哈希表不区分大小写*/
char case_insensitive(char ch)
{
    if(isupper(ch))
        return ch - 'A' + 'a';
    return ch;
}

/**完成初始化工作*/
void init()
{
    int i;
    for(i = 0 ; i < HASHSIZE; i++)
        files[i] = NULL;
}

/**哈希函数，返回在哈希表中的位置，哈希表各项以文件名首字母a-z区分*/
int hash(char *s)
{
   return case_insensitive(s[0]) - 'a';
}

/**查询某个文件名在哈希结构中是否已存在*/
int search(char *s)
{
    int num = hash(s);
    if(files[num] != NULL) //如果哈希表不空，已出现以该文件名首字母开头的文件名
    {
        struct file *p = files[num]; //p指向链表中第一个节点
        while(p != NULL)
        {
            if(strcmp(p->name,s) == 0)
                return TRUE;
            p = p->next;
        }
    }
    return FALSE;
}

/**如果文件名在哈希结构中不存在，则插入*/
void insert(char *s)
{
    if(search(s) == FALSE)			//文件名在原哈希表中不存在
    {
        int num = hash(s);			//得到哈希地址
        struct file *new_node = (struct file*)malloc(sizeof(struct file));
        strcpy(new_node->name,s);
        if(files[num] == NULL) //如果链表为空，将作为第一个节点
        {
            files[num] = new_node;
            files[num]->next = NULL;
        }
        else //如果链表不空，将其放在第一个节点位置
        {
            new_node->next = files[num];
            files[num] = new_node;
        }
    }
    // else do nothing;
}

/**显示该哈希结构中存储的所有文件名*/
void show_all()
{
    int i;
    struct file *p = NULL;

	//scan hash table
    for(i = 0 ; i < HASHSIZE ; i++)
    {
        p = files[i];
        if(p != NULL)
        {
            printf("For file begins with %c:\n",i + 'a');
            while(p != NULL)
            {
                printf("%s\n",p->name);
                p = p->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    char *file_names[] = {"apple","because","song","Dan","discuz","cartoon","nobody","android","information","love","like","No","nothing","like","alone","nothing"};
    int len = sizeof(file_names) / sizeof(char *); //获得字符串数组的长度
    int i;
    for(i = 0; i < len; i++)
        insert(file_names[i]);
    show_all();
    return 0;
}

