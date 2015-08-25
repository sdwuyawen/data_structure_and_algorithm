#include "stdio.h"


//二叉树的定义
typedef char datatype;  
  
typedef struct BinNode{  
    datatype data;  
    struct BinNode* lchild;  
    struct BinNode* rchild;  
}BinNode;  
  
typedef BinNode* bintree;          //bintree本身是个指向结点的指针  


#define MAX 1000

typedef struct seqqueue{
    bintree data[MAX];
    int front;
    int rear;
}seqqueue;


int enter(seqqueue *q,bintree t){
	//队列满
	if((q->rear + 1) % MAX == q->front){
		return -1;
	}else{
        q->data[q->rear] = t;
        q->rear++;
		return 0;
	}
}

bintree del(seqqueue *q){
    if(q->front == q->rear){
        return NULL;
    }else{
		bintree value = q->data[q->front];
        q->front = (q->front++) % MAX;
        return value;
    }
}

void level_tree(bintree t){  
    seqqueue q;  
    bintree temp;  
    q.front = q.rear = 0;  
    if(!t){  
        printf("the tree is empty\n");  
        return ;  
    }  
    enter(&q,t);  
    while(q.front != q.rear){  
        t=del(&q);  
        printf("%c ",t->data);  
        if(t->lchild){  
            enter(&q,t->lchild);  
        }  
        if(t->rchild){  
            enter(&q,t->rchild);  
        }  
    }  
}  
