#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, input_n, strike = 0, ball = 0, ans = 0;

	//횟수 입력
	cin >> n;

	bool arr[1000];
	memset(arr, true, sizeof(arr));	//  true로 초기화



	for (int i = 123; i <= 987; i++) {

		string num_str = to_string(i);
		char n1 = num_str[0], n2 = num_str[1], n3 = num_str[2];

		if (n1 == n2 || n2 == n3 || n3 == n1) arr[i] = false; //숫자가 같으면 안되므로 false로 제거
		if (n1 == '0' || n2 == '0' || n3 == '0')	arr[i] = false; //1~9까지이므로 제거

	}

	for (int i = 1; i <= n; i++) {

		cin >> input_n >> strike >> ball;

		for (int i = 123; i <= 987; i++) {

			int strike_cnt = 0, ball_cnt = 0;

			if (arr[i]) {

				string input_str = to_string(input_n), comp = to_string(i); //i하고 input_n을 str로 변경해 비교

				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {

						if (input_str[i] == comp[j]) {//같은 숫자가 존재할 때
							if (i == j)strike_cnt++; //자리도 동일
							else { ball_cnt++; }//자리는 다를 시
						}
					}
				}
				if (strike_cnt != strike || ball_cnt != ball) 	arr[i] = false;

			}

		}

	}

	for (int i = 123; i <= 987; i++) 	if (arr[i]) 	ans++;




	cout << ans << endl;

	return 0;

}