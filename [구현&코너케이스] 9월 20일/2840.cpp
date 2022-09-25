// 칸의 개수 :N    돌리는 횟수 :K
// 마지막 글자를 index 0 으로 잡기



#include <iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main() {
	int n, k,index=0;
	cin >> n >> k;
	vector <char> v(n, '?'); //크기 n개인 벡터에 ?로 초기화
	char arr[25][2];//2<=n<=25이므로 
	for (int i = 0; i < k; i++) {
		cin >> arr[i][0] >> arr[i][1]; //1 A
	}

	for (int i = k-1; 0 <=i; i--) {
		int s = arr[i+1][0] -'0';
		char alpa = arr[i][1];
		index = (s + index) % n;
		if (i == (k-1)) { 
			v[0] = alpa; 
			index = 0;
		}// continue;
		
		else if (v[index] != '?' && v[index] != alpa) {//이미 그 자리에 문자가 있을 때 alpa와 v[]에 존재하는 문자가 다른 경우 '!'
			cout << '!';
			return 0;//존재하지 않는 원판이므로 중지하기
		} else {
			v[index] = alpa;
		}
	}
	for (int i = 0; i < v.size(); i++) {

		cout << v[i] ;
	}

	return 0;
}


/*
8 8
  4 V / HONITAVR / i = (3+3) % 8 = 6
  3 I / HONITA?R / i = (4+7) % 8 = 3
  7 T / HON?TA?R / i = (5+7) % 8 = 4
  7 A / HON??A?R / i = (7+6) % 8 = 5
  6 R / HON????R / i = (2+5) % 8 = 7
  5 N / HON????? / i = (1+1) % 8 = 2
  1 O / HO?????? / i = (0+9) % 8 = 1
  9 H / H??????? / i = 0

5 6
1 A /같은 글자 X
2 B / 같은 글자X
5 B / 같은 글자 X
1 C / B?A ?C/i=(2+2) %6=4
2 A / B?A??? / i= 2%6 = 2
2 B / B????? / i=0

	3 3
	1 A  / /i = 2%3=2
	2 B /  / i =3%3 =0 --> 글자 인덱스 겹침 !
	3 C /C?? / i=0
  4 4
  1 a 1%4 =1
  1 a 1%4 =1
  1 a 1%4 =1
  1 a 0

*/












