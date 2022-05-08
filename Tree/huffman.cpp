#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector<string> HuffmanCode;
typedef struct {
	int weight;                //Ȩ��
	int parent, lchild, rchild;//˫�׽ڵ㣬���ӣ��Һ���
} HTNode, *HuffmanTree;
void creatHuffmanCode(HuffmanTree T, int n, HuffmanCode& huffmanCode);
void creatHuffmanTree(HuffmanTree& T, int n);
void SelectMin(HuffmanTree& HT, int n, int& s1, int& s2);
int main() {
	int n;
	cout << "�������ַ�������";
	cin >> n;
	cin.get();
	vector<string> HC(n + 1);//���ÿ���ַ��Ĺ���������
	HuffmanTree T;
	char ch[2 * n];
	string s;
	cout << "�����ַ����ո�ָ���";
	cin.getline(ch, 2 * n);
	for (int i = 0; i < n; i++) {
		s += ch[2 * i];
	}
	cout << "����Ȩ�أ��ո�ָ���";
	creatHuffmanTree(T, n);
	creatHuffmanCode(T, n, HC);
	cout << "�ַ�"
	     << "\t"
	     << "Ȩ��"
	     << "\t"
	     << "����" << endl;
	cout << "----------------------" << endl;
	for (int i = 1; i <= n; i++) {
		cout << s[i - 1] << '\t' << T[i].weight << '\t' << HC[i] << endl;
	}
	return 0;
}
void creatHuffmanTree(HuffmanTree& T, int n) {
	if (n <= 1) return;
	int m = 2 * n - 1;
	T = new HTNode[m + 1];
	for (int i = 1; i <= m; i++) {
		{//��˫�׽ڵ㡢���ӡ��Һ��ӳ�ʼ��Ϊ0
			T[i].parent = 0;
			T[i].lchild = 0;
			T[i].rchild = 0;
		}
	}
	for (int i = 1; i <= n; i++) {//����Ȩ��
		cin >> T[i].weight;
	}
	//������������
	for (int i = n + 1; i <= m; i++) {
		int min1, min2;
		//�ҵ���С�������ڵ�
		SelectMin(T, i - 1, min1, min2);
		T[min1].parent = i;
		T[min2].parent = i;
		T[i].lchild = min1;
		T[i].rchild = min2;
		T[i].weight = T[min1].weight + T[min2].weight;//��Ȩ�����
	}
}
void SelectMin(HuffmanTree& HT, int n, int& s1, int& s2) {
	//Ѱ�ҵ�һ��˫����Ϊ0��Ȩֵ��С�Ľ��
	int min;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0) {
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0) {
			if (HT[i].weight < HT[min].weight) {
				min = i;
			}
		}
	}
	s1 = min;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && i != s1) {
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && i != s1) {
			if (HT[i].weight < HT[min].weight) {
				min = i;
			}
		}
	}
	s2 = min;
}

void creatHuffmanCode(HuffmanTree T, int n, HuffmanCode& HC) {
	string code;//��ʱ��ű���
	for (int i = 1; i <= n; i++) {
		int c = i, f = T[i].parent;
		while (f != 0) {
			if (T[f].lchild == c) code += "0";
			else
				code += "1";
			c = f;
			f = T[f].parent;
		}
		reverse(code.begin(), code.end());//��code��ת
		HC[i] = code;
		code.clear();//���code
	}
}
