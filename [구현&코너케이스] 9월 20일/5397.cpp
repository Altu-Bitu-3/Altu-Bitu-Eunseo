// '-' 는 backspace   '<' :왼쪽 1   '>' :오른쪽 1        길이 >0


#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int n;//  n  :몇 개 케이스인지 

	stack <char> s1, s2;
	string cmd;//받은 문장

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		int l = cmd.size();
		for (int j = 0; j < l; j++) {
			char c = cmd.at(j);//c에 인덱스 j번째 삽입
			if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) s1.push(c);//맨 밑에 else로 넣으면  제대로 못 걸르기 때문에 설정해줌
		
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
