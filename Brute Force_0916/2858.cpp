//방의 크기 L * W  (L >=W)
//가운데 갈색 B
// 8 1 중간 1*1 -> 3*3       10 2 중간 2*1 -> 4*3 
//24 24 중간 6*4 이고 둘러싸인 모양-> 8*6
//규칙 : 중간 가로 >세로   가로 :B +2  세로: B+2    B의 가로 세로는  중간 약수



#include <iostream>


using namespace std;

int main() {
	int r, b;
	int l = 2, w = 2;
	cin >> r >> b;

	//예외처리 어떻게...? 8 1 인 경우 에러
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

	// 출력
	cout << l << " " << w;

	return 0;
}