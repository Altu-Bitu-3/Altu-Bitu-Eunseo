#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Max 100001

int arr[Max];
bool visit[Max];
vector<int> node[Max];

void dfsRecur(int x ) {
    visit[x] = true; // 방문 표기
    
    for (int i = 0; i < node[x].size(); i++) {
        int next = node[x][i];
        if (!visit[next]) {            
            arr[next] = x;
            dfsRecur(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //입력
    int n ;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }

    dfsRecur(1);
    //출력
    for (int i = 2; i <= n; i++) { cout << arr[i] << "\n"; }
}