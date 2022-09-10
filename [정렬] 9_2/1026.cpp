//첫 줄 입력 개수 5
//a :1 1 1 6 0
//b :2 7 8 3 1

//01116
//12378 이면 최대이므로 하나는 오름차순 하나는 내림차순이면 될듯

// 01116
// 87321 7 3 2 6
//같은 숫자 들어올 수 있으므로  set,map 사용X

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(int i, int j) {
	return j < i;
}

int main() {
	int n; //입력 개수
	int sum = 0;
	cin >> n;
	vector <int> a(n);
	vector <int> b(n);
	//int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end(), compare);
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;
	return 0;
}

