// n:4 m:2
//9 7 9 1
//n개의 숫자 입력 후 순열 조합(중복없이)
//일단 숫자 정렬 
//n과 m문제로 15649 참고

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//1 ≤ M ≤ N ≤ 8
int n, m;

const int SIZE = 8;

//재귀함수 사용 시, 함수를 계속 호출할 때 매개변수도 생성되므로 전역변수로 선언하는 것이 더 효율적
//int input[SIZE], num[SIZE] ;
//bool check[SIZE] = { false };

vector<int> input(SIZE), num(SIZE);
vector<bool> check(SIZE+1);

void backtracking(int cnt) { //cnt: 수열의 인덱스
    if (cnt == m) { //m개의 수열 만든 경우 (기저 조건)
        for (int i = 0; i < m; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int pre_n = 0;
    for (int i = 0; i < n; i++) { //i: 고르려는 수
        if (!check[i]&& pre_n != input[i]) { //현재 수열에 해당 수가 없다면 -> 사용 가능
            num[cnt] = input[i]; //사용
            pre_n = input[i];
            check[i] = true;
            backtracking(cnt + 1); //다음 인덱스 수 호출
            //다시 돌아왔을 때
            check[i] = false; //원래 상태로 돌려놓음
        }
    }
}
int main() {
    //int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.begin()+n);
    
    //연산
    backtracking(0);
    return 0;
}
