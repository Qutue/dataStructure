#include <iostream>
#define OK 1
#define ERROR -1
#define OVERFLOW -2
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
} StackNode, *LinkStack;
//初始化栈
Status InitStack(LinkStack& S);
//入栈
Status Push(LinkStack& S, ElemType e);
//出栈
Status Pop(LinkStack& S, ElemType& e);
//获取栈顶元素
ElemType getTop(LinkStack S);
//显示栈中所有元素
void StackDisp(LinkStack S);
//进制转换
void conversion(int n, int d);
int main() {
	LinkStack S;
	InitStack(S);
	ElemType e;
	for (int i = 1; i <= 10; i++)
		Push(S, i);
	StackDisp(S);
	Pop(S, e);
	cout << e << "出栈" << endl;
	cout << "栈顶元素为:" << getTop(S) << endl;
	StackDisp(S);
	conversion(999999999, 8);
	conversion(999999999, 2);
	return 0;
}
Status InitStack(LinkStack& S) {
	S = nullptr;
	return OK;
}
Status Push(LinkStack& S, ElemType e) {
	LinkStack p = new StackNode;
	p->next = S;
	p->data = e;
	S = p;
	return OK;
}
Status Pop(LinkStack& S, ElemType& e) {
	if (!S) return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
ElemType getTop(LinkStack S) {
	if (S)
		return S->data;
	else
		return false;
}
void StackDisp(LinkStack S) {
	cout << "---------------" << endl;
	if (!S) cout << "空栈" << endl;
	while (S) {
		cout << S->data << "  ";
		S = S->next;
	}
	cout << endl
	     << "---------------" << endl;
}
void conversion(int n, int d) {
	LinkStack S;
	InitStack(S);
	cout << "将 " << n << " 转换为" << d << "进制: ";
	while (n) {
		Push(S, n % d);
		n /= d;
	}
	while (S) {
		ElemType e;
		Pop(S, e);
		if (e < 10) {
			cout << e;
		} else {
			cout << char(e + 'A' - 10);
		}
	}
	cout << endl;
}
