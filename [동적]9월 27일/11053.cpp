#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
int max(int a1, int a2) {
	if (a1 > a2) return a1;
	return a2;
}*/
int main() {
	int n,sum=0;
	//�Է�
	cin >> n;
	//int n_arr[1000];//1 �� N �� 1,000
	vector <int> arr(n,0), n_arr(n,1);//n_arr�� �� ������ �� ����
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //arr�� ��° �� �־���
	}
	for (int i= 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) { n_arr[i] = max(n_arr[i], n_arr[j] + 1); }
		}
		sum = max(sum, n_arr[i]);
	}


	cout << sum;
	return 0;
}