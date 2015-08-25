#include "stdio.h"

typedef char datatype;

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

void preorder_dev(bintree t){
    seqstack s;
    s.top = -1;     //因为top在这里表示了数组中的位置，所以空为-1
    if(!t){
        printf("the tree is empty\n");
    }else{
        while(t || s.top != -1){
            while(t){    //只要结点不为空就应该入栈保存，与其左右结点无关    
                push(&s,t);
                t= t->lchild;
            }
			t=pop(&s);  
			printf("%c ",t->data);
            t=t->rchild;  
		}
	}
}


