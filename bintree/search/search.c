#include "stdio.h"
#include "stdlib.h"

typedef int datatype;

typedef struct BinNode{
    datatype data;
    struct BinNode* lchild;
    struct BinNode* rchild;
}BinNode;

typedef BinNode* bintree;	//bintree本身是个指向结点的指针

#define SIZE 100
typedef struct seqstack{
    bintree data[SIZE];
    int tag[SIZE];			//为后续遍历准备的
    int top;				//top为数组的下标
}seqstack;

void push(seqstack *s,bintree t){

    if(s->top == SIZE){
        printf("the stack is full\n");
    }else{
        s->top++;
        s->data[s->top]=t;
    }
}

bintree pop(seqstack *s){
    if(s->top == -1){
        return NULL;
    }else{
        s->top--;
        return s->data[s->top+1];
    }
}

//前序遍历，非递归
void preorder_dev(bintree t){
    seqstack s;
    s.top = -1;     //因为top在这里表示了数组中的位置，所以空为-1
    if(!t){
        printf("the tree is empty\n");
    }else{
        while(t || s.top != -1){
            while(t){    //只要结点不为空就应该入栈保存，与其左右结点无关    
				printf("%d ",t->data);
                push(&s,t);
                t= t->lchild;
            }
			t=pop(&s);  
            t=t->rchild;  
		}
	}
}

//中序遍历，非递归
void inorder_dev(bintree t){  
    seqstack s;  
    s.top = -1;  
    if(!t){  
        printf("the tree is empty!\n");  
    }else{  
        while(t ||s.top != -1){  
            while(t){  
                push(&s,t);  
                t= t->lchild;  
            }  
            t=pop(&s);  
            printf("%d ",t->data);  
            t=t->rchild;  
        }  
    }  
}

//后续遍历，非递归
void postorder_dev(bintree t){  
    seqstack s;  
    s.top = -1;  
    if(!t){  
        printf("the tree is empty!\n");  
    }else{  
        while(t || s.top != -1){    //栈空了的同时t也为空。  
            while(t){  
                push(&s,t);  
                s.tag[s.top] = 0;   //设置访问标记，0为第一次访问，1为第二次访问  
                t= t->lchild;  
            }  
            if(s.tag[s.top] == 0){  //第一次访问时，转向同层右结点  
                t= s.data[s.top];   //左走到底时t是为空的，必须有这步！  
                s.tag[s.top]=1;       
                t=t->rchild;  
            }else {  
                while (s.tag[s.top] == 1){ //找到栈中下一个第一次访问的结点，退出循环时并没有pop所以为其左子结点  
                    t = pop(&s);  
                    printf("%d ",t->data);  
                }  
                t = NULL; //必须将t置空。跳过向左走，直接向右走  
            }  
        }  
    }  
}  

//前序遍历，递归实现
void preorder(bintree t){  
    if(t){  
        printf("%d ",t->data);  
        preorder(t->lchild);  
        preorder(t->rchild);  
    }  
} 


//中序遍历，递归实现
void inorder(bintree t){  
    if(t){  
        inorder(t->lchild);  
        printf("%d ",t->data);  
        inorder(t->rchild);  
    }  
} 


//后序遍历，递归实现
void postorder(bintree t){  
    if(t){  
        postorder(t->lchild);  
        postorder(t->rchild);  
        printf("%d ",t->data);  
    }  
} 

//输入前序序列，生成二叉树
void createtree_preorder(bintree *t){        
    datatype c;  

	scanf("%d", &c);
	if(c == -1)
		*t = NULL;
//    if((c=getchar()) == '#')  
//        *t = NULL;  
    else{  
        *t = (bintree)malloc(sizeof(BinNode));  
        (*t)->data = c;  
        createtree_preorder(&(*t)->lchild);  
        createtree_preorder(&(*t)->rchild);  
    }  
} 

//查找，递归
bintree search_tree(bintree t,datatype x){  
	bintree ret;
    if(!t){  
        return NULL;  
    }  
    if(t->data == x){  
        return t;  
    }else{  
        if(!(ret = search_tree(t->lchild,x))){  
            return search_tree(t->rchild,x);  
        }
		else{
			return ret;  
		}
    }  
}  

//统计节点个数
int count_tree(bintree t){  
    if(t){  
        return (count_tree(t->lchild)+count_tree(t->rchild)+1);  
    }  
    return 0;  
}

int main(void)
{
	datatype search_value;
	int count;
	bintree root;
	bintree node;

	//创建二叉树
	createtree_preorder(&root);

	//非递归遍历
	preorder_dev(root);
	printf("\n");
	inorder_dev(root);
	printf("\n");
	postorder_dev(root);
	printf("\n");
	printf("\n");

	//递归遍历
	printf("\n");
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	//统计节点个数
	count = count_tree(root);
	printf("total %d nodes\n", count);
	

	//查找
	while(1)
	{
		scanf("%d", &search_value);
		if(!(node = search_tree(root, search_value)))
		{
			printf("can not find %d\n", search_value);
		}
		else
		{
			printf("find %d, value is %d\n", search_value, node->data);
		}

	}
	

	return 0;
}

