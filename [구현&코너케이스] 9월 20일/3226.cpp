/*
20:05 12 12*5 =60
06:45 30 15*5 15*10
13:08 15 15*10 ==>300 +60+75 

7~19h 1m=10원
19~07h 1m =5원
*/

#include <iostream>
#include<string>

using namespace std;

int main() {
	int n,tot = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		int dd;
		cin >> cmd >> dd;
		string s1 = cmd.substr(0,2), s2 =  cmd.substr(3, 2);//시간 ':'경계로 자르기
		int h1 = stoi(s1), m1= stoi(s2);//숫자로 변환 06:50 ==>h1=06    m1 =50
		int tot_m = dd + m1;

		if ((tot_m) >= 60 && ((h1 + 1) == 7 || (h1 + 1) == 19)) {
			int m2 = (60-m1), m3 = dd - m2;
			if ((h1 + 1) == 7) { tot += m2 * 5;	tot += m3 * 10; }//6h에서 7h 로 갈 때
			if ((h1 + 1) == 19) {	tot += m2 * 10; 	tot += m3 * 5;	}//18h->19h
		}
		else  {
			if (7 <= h1 && h1 <19) {tot += dd * 10;	}
			else { tot += dd * 5; }
		}

	}
	
	cout << tot;
	return 0;
}