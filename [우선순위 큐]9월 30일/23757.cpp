/*
n�� ���� ���� m ���� ���̵�

�� ������ ���� ���� present  ���� child - �ְ� ���� ���� ���� ����� ������ �� ����

���̰� ���ϴ� ���� ���� child
ť�� �켱���� ť�� ���� :3 1 5��� ���ڰ� ������ �� ť�� ������� 3 1 5�� ó�� �켱���� ť�� 5 3 1�� ó��
*/
#include<iostream>
#include<queue>
using namespace std;
int p, c;
int presentChild(priority_queue<int> &present, int m) {
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (present.top() >= c) {//������ ū ������ �Ǿտ� ���ĵǹǷ� ���̰� ���ϴ� ������ Ŭ ���� ����
			present.push(present.top() - c);
			present.pop();
		}	else {	return 0;	}//���� ������ ��
	}
	return 1;//��� ���̵��� ������ ������ ��
	
}
int main() {
	//�Է�
	int n, m;
	cin >> n >> m;
	priority_queue<int> present, child; //�׳� queue����  �ٽ� �����ؾ��ϹǷ� �켱���� ť ����
	
	for (int i = 0; i < n; i++) {
		cin >> p;
		present.push(p);
	}

	cout <<presentChild(present,m);
	

	return 0;

}