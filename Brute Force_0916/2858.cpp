//���� ũ�� L * W  (L >=W)
//��� ���� B
// 8 1 �߰� 1*1 -> 3*3       10 2 �߰� 2*1 -> 4*3 
//24 24 �߰� 6*4 �̰� �ѷ����� ���-> 8*6
//��Ģ : �߰� ���� >����   ���� :B +2  ����: B+2    B�� ���� ���δ�  �߰� ���



#include <iostream>


using namespace std;

int main() {
	int r, b;
	int l = 2, w = 2;
	cin >> r >> b;

	//����ó�� ���...? 8 1 �� ��� ����
	if (b == 1) {
		l+=1;
		w += 1;
	}


	for (int i = 1; i <= b / 2; i++) {
		w++;
		if (b % i == 0) {
			int n = b / i; //i *n  --> L*W ==(n+2)*(i+2) 
			//l += n;
			int a = n + 2;
			int tot = a * w - b;
			if (r == tot) {
				l = a;
				break;

			}
		}
	}

	// ���
	cout << l << " " << w;

	return 0;
}