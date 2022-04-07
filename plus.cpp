#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 300
typedef struct
{
	char ch[MAXSIZE + 1];
	int length;
} String;
void Plus(String num1, String num2);
int main() {
	String s1, s2;
	cin >> s1.ch;
	cin >> s2.ch;
	s1.length = strlen(s1.ch);
	s2.length = strlen(s2.ch);
	Plus(s1, s2);
	return 0;
}
void Plus(String num1, String num2) {
	String result;
	int j = 0;
	char *p1 = &num1.ch[0] + num1.length - 1, *p2 = &num2.ch[0] + num2.length - 1;
	for (int i = num2.length - 1; i >= 0; i--) {
		if (*p1 < *p2) {
			(*(p1 - 1))--;
			result.ch[j++] = (*p1 + 10 - *p2) + '0';
			p2--;
			p1--;
		} else {
			result.ch[j++] = (*p1 - *p2) + '0';
			p1--;
			p2--;
		}
	}
	int n = num1.length - j - 1;
	while (n >= 0) {
		result.ch[j++] = num1.ch[n--];
	}
	result.ch[j] = 0;
	for (int i = 0, m = j - 1; i < j / 2; i++, m--) {
		char temp = result.ch[i];
		result.ch[i] = result.ch[m];
		result.ch[m] = temp;
	}
	cout << result.ch << endl;
}
