//스도쿠 문제 0인 숫자 찾고
// 가로 | 세로 | 3*3 탐색

#include<iostream>
#include <vector>
using namespace std;

int main() {
	//int 9x9  - 입력값 넣어줄 배열
	int num[9][9];
	//bool 9x9x9 하나 check[가로][세로][3*3]
	bool check[9][9][9] = { };

	memset(check, true, sizeof(check));//전부 true로 바꾸기
	/*
	* 백준에서 memset 작동X...why?
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) { check[i][j][k] = true; }
		}
	}*/

	//입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num[i][j]; //9*9 배열에 넣어줌
			} 
		}
	int n = 4;
	while (n--) {//1번에 0을 다 해결하지 못할 수 있으므로 약간의 반복 사용
		for (int i = 0; i < 9; i++)	{
			for (int j = 0; j < 9; j++)	{
				// 0 인 값을 체크함
				if (num[i][j] == 0)	{
					for (int k = 0; k < 9; k++)	{
						// 가로 체크
						if (j != k && num[i][k] != 0)	check[i][j][num[i][k] - 1] = false;//가로 줄에서 num[i][k]가 0이 아니면 false를 주어서 제외
						// 세로 체크
						if (i != k && num[k][j] != 0)	check[i][j][num[k][j] - 1] = false;//세로 줄에서 num[k][j]가 0이 아니면 false를 주어서 제외
					}
					//3*3 체크
					int iSub = i / 3;//3*3 조합을 위해 사용
					int jSub = j / 3;//3*3 조합을 위해 사용
					for (int m = 0; m < 2; m++){
						for (int n = 0; n < 2; n++)	{
							if (num[iSub * 3 + m][jSub * 3 + n] != 0)//0이 아닐 때
								check[i][j][num[iSub * 3 + m][jSub * 3 + n] - 1] = false;//check를 false로 변경
						}
					}

					// true 인 개수를 세어주는 변수
					int iTrueCount = 0;
					int k1 = 0; // 값을 저장하는 Temp
					for (int k = 0; k < 9; k++){
						if (check[i][j][k])		{ 
							iTrueCount++;//true면 +1		
						k1 = k + 1;//인덱스로 해주어 n-1이므로 +1
						}
					}
					if (iTrueCount == 1)	{	num[i][j] = k1;	}// 한개인 경우 num[i][j] 에 값을 넣음 -> 다른 값이 존재하지 않기 때문에
				}
			}
		}
	}
	  //출력
	  for (int i = 0; i < 9; i++) {
		  for (int j = 0; j < 9; j++) {
			  cout << num[i][j] << ' ';
		  }cout << '\n';
	  }
	  return 0;
}
