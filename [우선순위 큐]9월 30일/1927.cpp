#include <iostream>
#include <queue>

using namespace std; 
struct cmp {
    bool operator()(const int& x1, const int& x2) {//값이 작은 수가 우선순위 
        
        return x2 < x1;
    }
}; 
int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    // 입력
    cin >> n;
    // 우선순위 큐 선언
    priority_queue<int, vector<int>, cmp> pq;//cmp로 입력값이 1 7 3 일 때  pq 1 3 7로 입력
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {//음의 정수 주어지지 않음 , 0일 때 
            if (pq.empty()) { cout << 0 << "\n"; }//만약 비워져 있으면 0출력
            else {
                cout << pq.top() << "\n";// 가장 작은 값부터 출력 후
                pq.pop();//큐에서 삭제
            }
        }else{//x가 자연수 일 때
            pq.push(x);
        }
    }


    return 0;
}