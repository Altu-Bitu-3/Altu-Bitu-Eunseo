//���� : 5�� ī�� ����
//���� a1+a2 = 5
//ī���� ���� : N  ���� ���� Ƚ�� :M
//�� ���ٺ��� ��������
//���� ġ�� ���� ī��� ������


#include <iostream>
#include<deque>

using namespace std;



int main() {
	int  n,  m;
	
	//�Է�
	cin >> n >> m;
	string fin[] = { "do","su","dosu" };
	int fin_n = 0;
	deque<int> tot_do,tot_su, gr_do,gr_su ;//tot: ��ü ī�� gr: �׶��� ī��
	for (int i = 0; i < n; i++) {
		int d, s;
		cin >> d >> s;
		tot_do.push_front(d);//push front�� �ؾ� ���� ���� �������� ���� push_back(s);�ϸ� ���� �������
		tot_su.push_front(s);
	}

	while (m>0) {
		
		int a = tot_su[0];
		gr_do.push_back(tot_do.front()); 
		tot_do.pop_front();
		m--;
		if (m == 0)break;
		if (gr_do.back() == 5 ) {
			for (int n : gr_su) 	tot_do.push_back(n);
			gr_su.clear();
			for (int n : gr_do) 	tot_do.push_back(n);
			gr_do.clear();

		}		
		if (!gr_do.empty() && !gr_su.empty() && (gr_do.back() + gr_su.back() == 5)) {
			for (int n : gr_do) 	tot_su.push_back(n);
			gr_do.clear();
			for (int n : gr_su) 	tot_su.push_back(n);
			gr_su.clear();
		}


		gr_su.push_back(tot_su.front());
		tot_su.pop_front();
		m--;
		if (m == 0)break;
		/*
		if (tot_do.empty() && tot_su.empty()) { fin_n = 2; break; }
		else if (tot_do.empty() ) { fin_n = 1; break; }
		else if (tot_su.empty()) {break; }*/
		//������ ī�尡 ����  ����Ƚ���� 0�϶�


		if (gr_su.back() ==5) {
			for (int n : gr_su) 	tot_do.push_back(n);
			gr_su.clear();
			for (int n : gr_do) 	tot_do.push_back(n);
			gr_do.clear();

		}
		if (!gr_do.empty() && !gr_su.empty() &&( gr_do.back() + gr_su.back() == 5)) {
			for (int n : gr_do) 	tot_su.push_back(n);
			gr_do.clear();
			for (int n : gr_su) 	tot_su.push_back(n);
			gr_su.clear();
		}

	}

	if (tot_do.size() == tot_su.size()) fin_n = 2;
	else if (tot_su.size() > tot_do.size()) fin_n = 1;

	cout << fin[fin_n];

	return 0;
}