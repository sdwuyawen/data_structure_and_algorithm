/************************************************************************/
/* @author lynnbest
Ŀ�꣺����ʽ�ĳ˷�
exp: A(X)=2X^3+4
	 B(x)=4X^4+2X^3
	 C(X)=A(x)*B(x)=8X^7+4X^6+16X^4+8X^3
˼·��
1.������������,���ڴ洢��������ʽ ����ʽ�洢 ϵ����+ָ����+ָ���� 
2.�����������ʽ�ĳ˷�
3.��ӡ���½��                                                           */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float coef;//ϵ��
	int exp;	//ָ��
	struct node *next; //ָ����
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

	printf("  ����ʵ�ֶ���ʽ�ĳ˷�   \n");
	
	printf("������A(X)������(��������)\n");
	scanf("%d",&n);
	head_a=CreateList(n);
	printf("A(X)=");
	printflist(head_a);
	printf("������B(X)������(��������)\n");
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
	listnode *head = (listnode *)malloc(sizeof(listnode));		//headָ��ͷ���
	listnode *p;												//pָ���¿��ٵĽڵ�
	listnode *pre = head;								
	float coef;													//ϵ��
	int exp;													//ָ��
	int i;

	if(NULL == head)
	{
		printf("����ͷ���ʧ��\n");
		exit(-1);
	}
	head->next=NULL;
	for(i=0;i<n;i++)
	{
		if(NULL == (p = (listnode *)malloc(sizeof(listnode))))
		{
			printf("�½��mallocʧ��\n");
			exit(-1);
		}
		printf("�������%d��ϵ����ָ��\n",i+1);
		scanf("%f,%d",&coef,&exp);
		p->coef=coef;
		p->exp=exp;  //���½ڵ�����
		p->next=NULL;
		//����ڵ�
		pre->next=p;
		pre=p;	
	}
	return  head;	//�����Ƿ��ضѵ��ڴ��� ���Ǿֲ�����
}

int printflist(listnode *head)
{	
	listnode *p=head->next;
	while(p->next!=NULL)
	{
		printf("%1.1f*X^%d+",p->coef,p->exp);// %1.1f��ʽ���С�����ֻ����һλ
		p=p->next;
	}
	printf("%1.1f*X^%d\n",p->coef,p->exp);
	return 0;
}

/************************************************************************/
/* ��ʽ��ˣ�
˼·��
1.��Ϊ����������ָ���ݼ�������A(X)�ݼ���B(x)�����£�����,why do this? 
2.�Ȼ�ȡ��������ָ���� exp_max. �����Ļ����µ�ָ�����Ƕ���0~7֮���ˡ�
	�ؼ����ˣ�������˱��ʲ����ѣ�������ο����ҵ����е�ָ���أ����һ�Ҫ�����µĽڵ����洢û�е�ָ��
�������һ���µ������洢�������exp_max��ʼ���²���,ÿһ������ָ����Ҫ��������
����ָ������+��������оͺܾ����ˡ�
	for(k=exp_max;k>=0;k--) 
	{
		���;
		�ж��Ƿ���ͬ���ϵ�����о����;
	}
����ж��أ������ڲ������ҡ�
���ǵ�ǰkֵ,������ָ���ҵ��ˣ���ʱ����a,b�����һλ����Ϊֻ��������ϲſ�����ͬ��ϵ��
���ǵ�ǰָ��<k,���������Ҫ����ϵ���ͣ�ֻ��a����
���ǵ�ǰָ��>k,����Ҫ����ϵ���ͣ�ֻ��b����
 ��Ҳ�Ϳ����ˣ�a,b��������ָ��һ������һ������ĺô��ˡ�����˼·�ܺ�

3.�����ܽ��£�
 3.1 ��k=exp_max;
 3.2 ����b
 3.3 �������� ��ô��ѭ�����Ǹ�����
  һ�����ҵ��� =k�����,Ȼ��ͼ����������������� ֱ������NULL�ڵ�
                                                                    */
/************************************************************************/
listnode *MultiplisePoly(listnode *head_a,listnode *head_b)//��ʽ���
{	
	listnode *head_c;
	listnode *pa=head_a;
	listnode *pb=head_b;
	listnode *pc;
	listnode *newnode;
	int exp_max; //ָ��֮�����ֵ
	float ceof;
	int k;

	if(pa->next!=NULL && pb->next!=NULL)
		 exp_max=pa->next->exp + pb->next->exp; //��ȡ���ָ���� 
	else return NULL;
	//��ʼ������Cͷ���
	head_c=(listnode *)malloc(sizeof(listnode));
	if(NULL==head_c)
	{	printf("��������Cʧ��\n");
		exit(-1);
	}
	head_c->coef=0.0;
	head_c->exp=0;
	head_c->next=NULL;
	pc=head_c; 
	InverseList(head_b);	//����b�����˺�a���ݣ�b����
	ceof=0.0;
	for(k=exp_max;k>=0;k--)  
	{
		pa=head_a->next; //�ָ�pa��ָ��
		while(pa!=NULL && pa->exp>k) //���Ȳ���pa��λ�� �Ҳ�����k��
				pa=pa->next;
		pb=head_b->next;//�ָ�Pb��ָ��
		while(pa!=NULL && pb!=NULL && pa->exp + pb->exp < k)//Ȼ���ڲ���pb��λ�� pa+pb��ָ���Ͳ�����k
				pb=pb->next;
		//�����������ֺ� pa+pb ��exp<=k
		while(pa!=NULL && pb!=NULL)//��ѭ�������,�ҵ����е�ָͬ���ĺ����
		{
			if(k == pa->exp + pb->exp)  //Ŀ�ľ����ҵ���K
			{
				ceof += pa->coef * pb->coef;
				pa = pa->next;
				pb = pb->next;
			}
			else 
			{
				if(pa->exp + pb->exp < k) //С��k ����pb
					pb = pb->next;
				else
					pa = pa->next; //����k ��Сpa
			}
			
		}
		if(ceof!=0.0)	//��ϵ���� �ͽ��˽ڵ���뵽c������
		{
			if(NULL == (newnode = (listnode *)malloc(sizeof(listnode))))
			{
				printf("����C�ڵ㿪��ʧ��");
				exit(-1);
			}
			newnode->coef=ceof;
			newnode->exp=k;
			newnode->next=NULL; //����ڵ�����
			
			pc->next = newnode;
			pc = newnode;			//����ڵ�		
			ceof=0.0;
		}
	}
	
		InverseList(head_b);
		return head_c;
}

int InverseList(listnode *head)	//��������
{
	listnode *p = head->next;	//pָ����Ҫ���õĽڵ㣬
	listnode *q;				//qָ����һ�������õĽڵ�
	head->next=NULL;
	while(p)	//��ǰ�ڵ㲻Ϊ��
	{
		q=p->next;//������һ���ڵ�
		p->next=head->next; //�ȸ������õ�� next
		head->next=p;		//�ڸ���head->next 
		p=q;		   //��һ��
	}
	return 0;
}