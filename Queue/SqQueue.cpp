#include <iostream>
#define MAXSIZE 100
#define OVERFLOW -1
#define OK 1
#define ERROR -1
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct SqQueue {
	ElemType* base;
	int front;
	int rear;
} SqQueue;
Status InitQueue(SqQueue& Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue& Q, ElemType e);
Status EnQueue(SqQueue& Q, ElemType e);
Status DeQueue(SqQueue& Q, ElemType& e);
ElemType getHead(SqQueue Q);
void QueueDisp(SqQueue Q);
int main() {
	SqQueue Q;
	InitQueue(Q);
	for (int i = 1; i <= 10; i++) {
		EnQueue(Q, i);
	}
	cout << "Length:" << QueueLength(Q) << endl;
	QueueDisp(Q);
	ElemType e;
	DeQueue(Q, e);
	cout << "删除:" << e << endl;
	QueueDisp(Q);
	return 0;
}
Status InitQueue(SqQueue& Q) {
	Q.base = new ElemType[MAXSIZE];
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnQueue(SqQueue& Q, ElemType e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue& Q, ElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
ElemType getHead(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
	else {
		exit(0);
	}
}
void QueueDisp(SqQueue Q) {
	cout << "---------------" << endl
	     << "队首" << endl;
	if (Q.front == Q.rear) {
		cout << "空队" << endl;
	} else {
		while (Q.front != Q.rear) {
			cout << Q.base[Q.front++] << "  ";
		}
	}
	cout << endl
	     << "---------------" << endl;
}
