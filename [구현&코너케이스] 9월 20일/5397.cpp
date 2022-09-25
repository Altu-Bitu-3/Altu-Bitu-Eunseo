// '-' �� backspace   '<' :���� 1   '>' :������ 1        ���� >0


#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int n;//  n  :�� �� ���̽����� 

	stack <char> s1, s2;
	string cmd;//���� ����

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		int l = cmd.size();
		for (int j = 0; j < l; j++) {
			char c = cmd.at(j);//c�� �ε��� j��° ����
			if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) s1.push(c);//�� �ؿ� else�� ������  ����� �� �ɸ��� ������ ��������
		
			else if (!s1.empty() && c == '<') {
				s2.push(s1.top());
				s1.pop();
			}
			else if (!s2.empty() && c == '>') {
				s1.push(s2.top());
				s2.pop();
			}
			else if (!s1.empty() && c == '-') s1.pop();
			
		}

		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		while (!s2.empty()) {
			cout << s2.top();
			s2.pop();
		}
		cout << '\n';
	}


		return 0;
	
}
