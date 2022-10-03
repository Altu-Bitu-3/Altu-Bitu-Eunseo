//도도 : 5인 카드 존재
//수연 a1+a2 = 5
//카드의 개수 : N  게임 진행 횟수 :M
//맨 밑줄부터 역순으로
//종을 치면 쌓인 카드는 밑으로


#include <iostream>
#include<deque>

using namespace std;



int main() {
	int  n,  m;
	
	//입력
	cin >> n >> m;
	string fin[] = { "do","su","dosu" };
	int fin_n = 0;
	deque<int> tot_do,tot_su, gr_do,gr_su ;//tot: 전체 카드 gr: 그라운드 카드
	for (int i = 0; i < n; i++) {
		int d, s;
		cin >> d >> s;
		tot_do.push_front(d);//push front로 해야 넣은 숫자 역순으로 가능 push_back(s);하면 넣은 순서대로
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
		//도도의 카드가 없고  진행횟수가 0일때


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