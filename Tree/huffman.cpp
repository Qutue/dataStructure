#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector<string> HuffmanCode;
typedef struct {
	int weight;                //权重
	int parent, lchild, rchild;//双亲节点，左孩子，右孩子
} HTNode, *HuffmanTree;
void creatHuffmanCode(HuffmanTree T, int n, HuffmanCode& huffmanCode);
void creatHuffmanTree(HuffmanTree& T, int n);
void SelectMin(HuffmanTree& HT, int n, int& s1, int& s2);
int main() {
	int n;
	cout << "请输入字符个数：";
	cin >> n;
	cin.get();
	vector<string> HC(n + 1);//存放每个字符的哈夫曼编码
	HuffmanTree T;
	char ch[2 * n];
	string s;
	cout << "输入字符，空格分隔：";
	cin.getline(ch, 2 * n);
	for (int i = 0; i < n; i++) {
		s += ch[2 * i];
	}
	cout << "输入权重，空格分隔：";
	creatHuffmanTree(T, n);
	creatHuffmanCode(T, n, HC);
	cout << "字符"
	     << "\t"
	     << "权重"
	     << "\t"
	     << "编码" << endl;
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
		{//将双亲节点、左孩子、右孩子初始化为0
			T[i].parent = 0;
			T[i].lchild = 0;
			T[i].rchild = 0;
		}
	}
	for (int i = 1; i <= n; i++) {//输入权重
		cin >> T[i].weight;
	}
	//创建哈夫曼树
	for (int i = n + 1; i <= m; i++) {
		int min1, min2;
		//找到最小的两个节点
		SelectMin(T, i - 1, min1, min2);
		T[min1].parent = i;
		T[min2].parent = i;
		T[i].lchild = min1;
		T[i].rchild = min2;
		T[i].weight = T[min1].weight + T[min2].weight;//将权重相加
	}
}
void SelectMin(HuffmanTree& HT, int n, int& s1, int& s2) {
	//寻找第一个双亲域为0且权值最小的结点
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
	string code;//临时存放编码
	for (int i = 1; i <= n; i++) {
		int c = i, f = T[i].parent;
		while (f != 0) {
			if (T[f].lchild == c) code += "0";
			else
				code += "1";
			c = f;
			f = T[f].parent;
		}
		reverse(code.begin(), code.end());//将code反转
		HC[i] = code;
		code.clear();//清空code
	}
}
