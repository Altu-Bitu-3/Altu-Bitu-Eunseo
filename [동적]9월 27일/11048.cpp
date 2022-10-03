
#include <algorithm> //알고리즘을 사용하기 위한 헤더
#include <iostream>//c++입출력 헤더
#include <vector>//벡터를 사용하기 위한 헤더

using namespace std; //std:: 대신 사용

/*
* 동적프로그래밍을 이용하여 값을 업데이트
* 더미 인덱스를 사용하여 예외 없이 한 번에 처리
* max(): 두 개 이상의 값을 비교할 때는 {}로 묶기
*/

int maxCandy(int n, int m, vector<vector<int>>dp) //최대 사탕 개수를 찾아줌 
{
	// 동적 계획법으로 사탕의 개수 계산
	for (int i = 1; i <= n; i++) {//n*m인 미로에 시작이(1,1)이므로 i =1부터 
		for (int j = 1; j <= m; j++) {// j를 1로 놓고 반복문 
			dp[i][j] += max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }); //  그 칸까지 경로의 가장 큰 사탕 수를 더해줌
		}
	}
	return dp[n][m];// [n][m]으로 이동했을 시 도착하므로 리턴
}

int main()
{
	
	int n, m;// 미로 크기 n*m
	cin >> n >> m; // 입력
	vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0)); // [n+1][m+1]인 벡터 생성 후 0으로 초기화
	for (int i = 1; i <= n; i++) {		// n * m인 미로인데 준규의 현재 위치가 (1,1)이므로 1부터 시작
		for (int j = 1; j <= m; j++) {//(1,1) 이므로 1부터 시작
			cin >> maze[i][j];//입력값을  벡터[i][j]에 삽입
		}
	}
	// 연산 & 출력
	cout << maxCandy(n, m, maze);
	return 0;//종료
}