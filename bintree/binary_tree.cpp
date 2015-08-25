#include <iostream>
#include <stack>
#include <queue>
#include <locale.h>
using namespace std;
typedef struct BiTNode {//���������
    char data;                      //����
    struct BiTNode *lchild,*rchild; //���Һ���ָ��
} BiTNode,*BiTree;
int CreateBiTree(BiTree *T) {//���������д���������
    char data;
    scanf("%c",&data);//�������������������н���ֵ��һ���ַ�������#����ʾ����
    if (data == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = data;         //���ɸ����
        CreateBiTree(&((*T)->lchild));//����������
        CreateBiTree(&(*T)->rchild);//����������
    }
    return 0;
}

#if 0
int CreateBiTree(BiTree &T) {//���������д���������
    char data;
    scanf("%c",&data);//�������������������н���ֵ��һ���ַ�������#����ʾ����
    if (data == '#') {
        T = NULL;
    } else {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = data;         //���ɸ����
        CreateBiTree(T->lchild);//����������
        CreateBiTree(T->rchild);//����������
    }
    return 0;
}
#endif

void Visit(BiTree T) {//���
    if (T->data != '#') {
        printf("%c ",T->data);
    }
}
void PreOrder(BiTree T) {//�������
    if (T != NULL) {
        Visit(T);               //���ʸ��ڵ�
        PreOrder(T->lchild);    //�������ӽ��
        PreOrder(T->rchild);    //�������ӽ��
    }
}
void InOrder(BiTree T) {//�������
    if (T != NULL) {
        InOrder(T->lchild);     //�������ӽ��
        Visit(T);               //���ʸ��ڵ�
        InOrder(T->rchild);     //�������ӽ��
    }
}
void PostOrder(BiTree T) {//�������
    if (T != NULL) {
        PostOrder(T->lchild);   //�������ӽ��
        PostOrder(T->rchild);   //�������ӽ��
        Visit(T);               //���ʸ��ڵ�
    }
}
void PreOrder2(BiTree T) {//�������(�ǵݹ�)
//����T->data�󣬽�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ�����������T����������
    stack<BiTree> stack;
    BiTree p = T;//p�Ǳ���ָ��
    while (p || !stack.empty()) {   //ջ���ջ���p����ʱѭ��
        if (p != NULL) {
            stack.push(p);          //����ջ��
            printf("%c ",p->data);  //���ʸ��ڵ�
            p = p->lchild;          //����������
        } else {
            p = stack.top();        //��ջ
            stack.pop();
            p = p->rchild;          //����������
        }
    }
}
void InOrder2(BiTree T) {//�������(�ǵݹ�)
//T��Ҫ�������ĸ�ָ�룬�������Ҫ���ڱ������������󣬷��ʸ����ٱ�����������
//�Ƚ�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ������T->data�����������T����������
    stack<BiTree> stack;
    BiTree p = T;//p�Ǳ���ָ��
    while (p || !stack.empty()) {   //ջ���ջ���p����ʱѭ��
        if (p != NULL) {
            stack.push(p);          //����ջ��
            p = p->lchild;          //����������
        } else {
            p = stack.top();        //��ջ�����ʸ��ڵ�
            printf("%c ",p->data);
            stack.pop();
            p = p->rchild;          //����������
        }
    }
}

typedef struct BiTNodePost{
    BiTree biTree;
    char tag;
} BiTNodePost,*BiTreePost;
void PostOrder2(BiTree T) {//�������(�ǵݹ�)
    stack<BiTreePost> stack;
    BiTree p = T;//p�Ǳ���ָ��
    BiTreePost BT;
    while (p != NULL || !stack.empty()) {//ջ���ջ���p����ʱѭ��
        while (p != NULL) {//����������
            BT = (BiTreePost)malloc(sizeof(BiTNodePost));
            BT->biTree = p;
            BT->tag = 'L';//���ʹ�������
            stack.push(BT);
            p = p->lchild;
        }
        while (!stack.empty() && (stack.top())->tag == 'R') {//��������������Ϸ��ʸ��ڵ�
            BT = stack.top();
            stack.pop();//��ջ
            printf("%c ",BT->biTree->data);
        }
        if (!stack.empty()) {//����������
            BT = stack.top();
            BT->tag = 'R';//���ʹ�������
            p = BT->biTree;
            p = p->rchild;
        }
    }
}

void LevelOrder(BiTree T) {//��α���
    if (T == NULL) return;
    BiTree p = T;
    queue<BiTree> queue;//����
    queue.push(p);//���ڵ����
    while (!queue.empty()) {    //���в���ѭ��
        p = queue.front();      //��ͷԪ�س���
        printf("%c ",p->data);  //����pָ��Ľ��
        queue.pop();            //�˳�����
        if (p->lchild != NULL) {//���������գ������������
            queue.push(p->lchild);
        }
        if (p->rchild != NULL) {//���������գ������������
            queue.push(p->rchild);
        }
    }
}
int main() {
    BiTree T;

    setlocale(LC_ALL,"chs");
    CreateBiTree(&T);

    printf("�������        ��");PreOrder  (T);printf("\n");
    printf("�������(�ǵݹ�)��");PreOrder2 (T);printf("\n");
                                               printf("\n");
    printf("�������        ��");InOrder   (T);printf("\n");
    printf("�������(�ǵݹ�)��");InOrder2  (T);printf("\n");
                                               printf("\n");
    printf("�������        ��");PostOrder (T);printf("\n");
    printf("�������(�ǵݹ�)��");PostOrder2(T);printf("\n");
                                               printf("\n");
    printf("��α���        ��");LevelOrder(T);printf("\n");

	while(1)
	{
		
	}

    return 0;
}
//ABC##DE#G##F###
//�������        ��A B C D E G F
//�������(�ǵݹ�)��A B C D E G F
//
//�������        ��C B E G D F A
//�������(�ǵݹ�)��C B E G D F A
//
//�������        ��C G E F D B A
//�������(�ǵݹ�)��C G E F D B A
//
//��α���        ��A B C D E F G
//

///       A
///      /
///     B
///    / \
///   C   D
///      / \
///     E   F
///      \
///       G
