//ù �� �Է� ���� 5
//a :1 1 1 6 0
//b :2 7 8 3 1

//01116
//12378 �̸� �ִ��̹Ƿ� �ϳ��� �������� �ϳ��� ���������̸� �ɵ�

// 01116
// 87321 7 3 2 6
//���� ���� ���� �� �����Ƿ�  set,map ���X

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(int i, int j) {
	return j < i;
}

int main() {
	int n; //�Է� ����
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

