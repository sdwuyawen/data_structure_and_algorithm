/************************************************************************/
/* @author lynnbest
目标：多项式的乘法
exp: A(X)=2X^3+4
	 B(x)=4X^4+2X^3
	 C(X)=A(x)*B(x)=8X^7+4X^6+16X^4+8X^3
思路：
1.创建两个链表,用于存储两个多项式 用链式存储 系数域+指数域+指针域 
2.完成两个多项式的乘法
3.打印出新结果                                                           */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float coef;//系数
	int exp;	//指数
	struct node *next; //指针域
}listnode;


listnode *CreateList(int n);
int printflist(listnode *head);
int InverseList(listnode *head);
listnode *MultiplisePoly(listnode *head_a,listnode *head_b);

int	main()
{	
	int n;
	listnode *head_a;
	listnode *head_b;
	listnode *head_c;

	printf("  链表实现多项式的乘法   \n");
	
	printf("请输入A(X)的项数(降幂排列)\n");
	scanf("%d",&n);
	head_a=CreateList(n);
	printf("A(X)=");
	printflist(head_a);
	printf("请输入B(X)的项数(降幂排列)\n");
	scanf("%d",&n);
	head_b=CreateList(n);
//	InverseList(head_b);
	printf("B(X)=");
	printflist(head_b);
	head_c=MultiplisePoly(head_a,head_b);
	printf("C(X)=A(X)*B(X)=");
	printflist(head_c);
	
	return 0;
}


listnode *CreateList(int n)
{
	listnode *head = (listnode *)malloc(sizeof(listnode));		//head指向头结点
	listnode *p;												//p指向新开辟的节点
	listnode *pre = head;								
	float coef;													//系数
	int exp;													//指数
	int i;

	if(NULL == head)
	{
		printf("开辟头结点失败\n");
		exit(-1);
	}
	head->next=NULL;
	for(i=0;i<n;i++)
	{
		if(NULL == (p = (listnode *)malloc(sizeof(listnode))))
		{
			printf("新结点malloc失败\n");
			exit(-1);
		}
		printf("请输入第%d个系数和指数\n",i+1);
		scanf("%f,%d",&coef,&exp);
		p->coef=coef;
		p->exp=exp;  //更新节点数据
		p->next=NULL;
		//插入节点
		pre->next=p;
		pre=p;	
	}
	return  head;	//这里是返回堆的内存区 不是局部变量
}

int printflist(listnode *head)
{	
	listnode *p=head->next;
	while(p->next!=NULL)
	{
		printf("%1.1f*X^%d+",p->coef,p->exp);// %1.1f格式输出小数点后只保留一位
		p=p->next;
	}
	printf("%1.1f*X^%d\n",p->coef,p->exp);
	return 0;
}

/************************************************************************/
/* 链式相乘：
思路：
1.因为两个链表都是指数递减，所以A(X)递减，B(x)逆置下，递增,why do this? 
2.先获取两个最大的指数和 exp_max. 这样的话余下的指数就是都在0~7之间了。
	关键来了，遍历相乘本质并不难，但是如何可以找到所有的指数呢？而且还要开辟新的节点来存储没有的指数
解决：用一个新的链来存储结果，从exp_max开始向下查找,每一个可能指数都要遍历到。
这里指数升序+降序的排列就很精妙了。
	for(k=exp_max;k>=0;k--) 
	{
		相乘;
		判断是否还有同类的系数，有就相加;
	}
如何判断呢？就是在步进查找。
若是当前k值,表明该指数找到了，此时就是a,b都后继一位，因为只有这种组合才可能有同样系数
若是当前指数<k,表明则表明要增加系数和，只有a增加
若是当前指数>k,表明要减少系数和，只有b增加
 这也就看出了，a,b两个链表指数一个升序一个降序的好处了。这种思路很好

3.归纳总结下：
 3.1 求k=exp_max;
 3.2 逆置b
 3.3 遍历查找 怎么做循环又是个问题
  一旦查找到了 =k的情况,然后就继续搜索其他可能性 直到都到NULL节点
                                                                    */
/************************************************************************/
listnode *MultiplisePoly(listnode *head_a,listnode *head_b)//链式相乘
{	
	listnode *head_c;
	listnode *pa=head_a;
	listnode *pb=head_b;
	listnode *pc;
	listnode *newnode;
	int exp_max; //指数之和最大值
	float ceof;
	int k;

	if(pa->next!=NULL && pb->next!=NULL)
		 exp_max=pa->next->exp + pb->next->exp; //获取最大指数和 
	else return NULL;
	//初始化链表C头结点
	head_c=(listnode *)malloc(sizeof(listnode));
	if(NULL==head_c)
	{	printf("开辟链表C失败\n");
		exit(-1);
	}
	head_c->coef=0.0;
	head_c->exp=0;
	head_c->next=NULL;
	pc=head_c; 
	InverseList(head_b);	//逆置b链表，此后a降幂，b升幂
	ceof=0.0;
	for(k=exp_max;k>=0;k--)  
	{
		pa=head_a->next; //恢复pa的指向
		while(pa!=NULL && pa->exp>k) //首先查找pa的位置 找不大于k的
				pa=pa->next;
		pb=head_b->next;//恢复Pb的指向
		while(pa!=NULL && pb!=NULL && pa->exp + pb->exp < k)//然后在查找pb的位置 pa+pb的指数和不大于k
				pb=pb->next;
		//经过上面两轮后 pa+pb 的exp<=k
		while(pa!=NULL && pb!=NULL)//此循环进入后,找到所有的同指数的和相加
		{
			if(k == pa->exp + pb->exp)  //目的就是找等于K
			{
				ceof += pa->coef * pb->coef;
				pa = pa->next;
				pb = pb->next;
			}
			else 
			{
				if(pa->exp + pb->exp < k) //小于k 增加pb
					pb = pb->next;
				else
					pa = pa->next; //大于k 减小pa
			}
			
		}
		if(ceof!=0.0)	//有系数了 就将此节点插入到c链表中
		{
			if(NULL == (newnode = (listnode *)malloc(sizeof(listnode))))
			{
				printf("链表C节点开辟失败");
				exit(-1);
			}
			newnode->coef=ceof;
			newnode->exp=k;
			newnode->next=NULL; //插入节点数据
			
			pc->next = newnode;
			pc = newnode;			//插入节点		
			ceof=0.0;
		}
	}
	
		InverseList(head_b);
		return head_c;
}

int InverseList(listnode *head)	//逆置链表
{
	listnode *p = head->next;	//p指向正要逆置的节点，
	listnode *q;				//q指向下一个待逆置的节点
	head->next=NULL;
	while(p)	//当前节点不为空
	{
		q=p->next;//保存下一个节点
		p->next=head->next; //先更新逆置点的 next
		head->next=p;		//在更新head->next 
		p=q;		   //下一轮
	}
	return 0;
}