#include <iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType* base;
	ElemType* top;
	int stackSize;
} SqStack;
//初始化栈
Status InitStack(SqStack& S);
//入栈
Status Push(SqStack& S, ElemType e);
//出栈
Status Pop(SqStack& S, ElemType& e);
//获取栈顶元素
ElemType getTop(SqStack S);
//判断栈是否为空
Status StackEmpty(SqStack S);
//显示栈中所有元素
void StackDisp(SqStack S);
//进制转换,输入十进制数n,转换为d(2,8,16)进制数
void conversion(int n, int d);
int main() {
	SqStack S;
	ElemType e;
	InitStack(S);
	if (StackEmpty(S))
		cout << "空栈!" << endl;
	else
		cout << "栈非空!" << endl;
	for (int i = 1; i <= 5; i++) {
		Push(S, i);
	}
	StackDisp(S);
	cout << "栈顶元素为:" << getTop(S) << endl;
	Pop(S, e);
	cout << e << " 出栈" << endl;
	StackDisp(S);
	conversion(999999999, 8);
	conversion(999999999, 2);
	conversion(999999999, 16);
	return 0;
}
Status InitStack(SqStack& S) {
	S.base = new ElemType[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stackSize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, ElemType e) {
	if (S.top - S.base == S.stackSize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S, ElemType& e) {
	if (S.base == S.top)
		return ERROR;
	e = *--S.top;
	return OK;
}
ElemType getTop(SqStack S) {
	if (S.base == S.top) return ERROR;
	return *--S.top;
}
Status StackEmpty(SqStack S) {
	return S.base == S.top ? true : false;
}
void StackDisp(SqStack S) {
	cout << "---------------" << endl;
	if (StackEmpty(S))
		cout << "空栈" << endl;
	else {
		while (S.base < S.top) {
			cout << *S.base++ << "  ";
		}
		cout << endl;
	}
	cout << "---------------" << endl;
}
void conversion(int n, int d) {

	SqStack S;
	InitStack(S);
	cout << "将 " << n << " 转换为" << d << "进制: ";
	while (n) {
		Push(S, n % d);
		n /= d;
	}
	while (!StackEmpty(S)) {
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
