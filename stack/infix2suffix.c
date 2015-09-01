#include <stdio.h>

/* 中缀表达式转后缀表达式

算法： 可以使用栈来完成中缀表达式到后缀表达式的转换

1、栈stack[]用来存储操作符，top指向栈顶，但不存储元素，top=0表示栈为空

2、从左向右遍历中缀表达式

　　a.如果遇到的是操作数num，则直接输出到后缀表达式

　　b.如果遇到的是操作符op，则有几种情况：

　　　　b.1.如果op==')'，则依次弹出栈顶直到弹出'('，但'('不输出到后缀表达式

　　　　b.2:如果op=='('，则直接入栈

　　　　b.3:如果栈为空，则直接入栈

　　　　b.4:如果op的优先级高于栈顶操作符的优先级，则入栈

　　　　b.5:如果op的优先级低于或等于栈顶操作符的优先级，则依次弹出栈顶直到op的优先级高于栈顶操作符的优先级（或栈为空），再将op入栈

3、遍历完时，如果栈仍不为空，则依次弹出栈顶直到栈为空 */

/* return 1:  b优先级 >  a优先级 
 * return 0:  b优先级 <= a优先级
 */
int prioritycmp(char a, char b) {
    if(b == '(')
        return 1;//左括号直接入栈
    else if((b == '*' || b == '/') &&(a == '+' || a == '-' || a == '('))
        return 1;//*、/优先级高于+、-、(，入栈
    else if((b == '+' || b == '-') && (a == '('))
        return 1;//+、-优先级高于(，入栈
    else
        return 0;
}

/* 中缀表达式转后缀表达式
 * 中缀表达式之间无分割
 * 后缀表达式操作数、操作符之间用空格分割，便于区分不同操作数
 */
void infix_to_suffix(char* infix, char* suffix) {
    int i, j = 0;
	int top = 0;			//top是下次入栈要写入的位置，top-1是栈顶元素
    char stack[1000];	//存储运算符的栈

    for(i=0; infix[i]!='\0'; i++) {
        if(infix[i] >= '0' && infix[i] <= '9') {
            suffix[j++] = infix[i];//操作数则直接输出
        } else {
            if(i != 0 && infix[i-1] >= '0' && infix[i-1] <= '9') {
                suffix[j++] = ' ';//操作数后补充空格分割
            }
            if(infix[i] == ')') {
                //遇到右括号则一直弹出直到左括号，但左括号不输出
                while(stack[top-1] != '(') {
                    suffix[j++] = stack[--top];
                    suffix[j++] = ' ';
                }
                top--;
            } else if(top == 0 || prioritycmp(stack[top-1], infix[i])) {
                //栈为空或当前操作符的优先级高于栈顶操作符，当前操作符入栈
                stack[top++] = infix[i];
            } else {
                //当前操作符优先级等于或低于栈顶操作符则弹出栈顶
                while(!prioritycmp(stack[top-1], infix[i])) {
                    suffix[j++] = stack[--top];
                    suffix[j++] = ' ';
                    if(top == 0)
                        break;
                }
                stack[top++] = infix[i];//当前操作符入栈
            }
        }
    }
    //补充空格分割
    if(suffix[j-1] != ' ') {
        suffix[j++] = ' ';
    }
    //如果操作符栈不为空，弹出所有操作符
    while(top != 0) {
        suffix[j++] = stack[--top];
        suffix[j++] = ' ';
    }
    suffix[j] = '\0';
}

int main(void)
{
	char infix[1000];
	char suffix[1000];

	fgets(infix, sizeof(infix), stdin);
	infix_to_suffix(infix, suffix);

	printf("%s\n", infix);
	printf("%s\n", suffix);

	return 0;
}
