#include <iostream>
#include <string>
using namespace std;
int BF(string S, string target,int pos);
int main() {
	string S, target;
	cin >> S;
	cin >> target;
	cout << BF(S, target,0) << endl;
	return 0;
}
int BF(string S, string target,int pos=0) {
	int i = pos, j = 0;
	while (i < S.length() && j < target.length()) {
		if (S[i] == target[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= target.length()) {
		return i - target.length();
	} else
		return -1;
}
