#include <iostream>
#include <queue>
using namespace std;
typedef struct Dancer {
	string name;
	char sex;
} Dancer;
void DancePartner(Dancer dancer[], int num, queue<Dancer>& F_Dancer, queue<Dancer>& M_Dancer);

int main() {
	queue<Dancer> F_Dancer, M_Dancer;
	Dancer dancer[] = {{"李辉", 'F'}, {"张三", 'F'}, {"李四", 'F'}, {"翠花", 'M'}, {"小红", 'M'}, {"小丽", 'M'}, {"老李", 'F'}, {"小芳", 'M'}, {"李明", 'F'}, {"丽丽", 'M'}, {"老张", 'F'}};
	int num = sizeof(dancer) / sizeof(Dancer);

	DancePartner(dancer, num, F_Dancer, M_Dancer);
	return 0;
}
void DancePartner(Dancer dancer[], int num, queue<Dancer>& F_Dancer, queue<Dancer>& M_Dancer) {

	for (int i = 0; i < num; i++) {
		Dancer p = dancer[i];
		if (p.sex == 'M')
			M_Dancer.push(p);
		else
			F_Dancer.push(p);
	}
	cout << "男士个数:" << F_Dancer.size() << endl;
	cout << "女士个数:" << M_Dancer.size() << endl;
	while (!F_Dancer.empty() && !M_Dancer.empty()) {
		cout << "男：" << F_Dancer.front().name << "  ";
		F_Dancer.pop();
		cout << "女：" << M_Dancer.front().name << "  ";
		M_Dancer.pop();

		cout << endl;
	}
	if (!F_Dancer.empty()) {
		cout << "第一个待获得舞伴的男士是:" << endl;
		cout << F_Dancer.front().name << endl;
	}
	if (!M_Dancer.empty()) {
		cout << "第一个待获得舞伴的女士是:" << endl;
		cout << M_Dancer.front().name << endl;
	}
}
