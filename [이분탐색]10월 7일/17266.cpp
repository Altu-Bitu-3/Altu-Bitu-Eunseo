#include<iostream>
#include<string>
#include<vector>

using namespace std;

//굴다리 길이: n 가로등 개수: m  가로등 위치 x

int Search(int n, int m, vector<int>& lamp) {
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool flag = false;
        
        for (int i = 0; i < m - 1; i++) { //시작 끝 제외 구간 확인
            if (lamp[i + 1] - lamp[i] > mid * 2) { flag = true; break; }
        }
        if (lamp[0] > mid || n - lamp[m - 1] > mid) flag = true; //시작 구간 & 끝 구간 확인
        if (!flag) { r = mid - 1; }
        else { l = mid + 1; }
    }
    return l;
}

int main() {
    //속도 빠르게
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    //입력
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> lamp(m, 0);
	for (int i = 0; i < m; i++) { 		cin >> lamp[i]; 	}
	

    //출력
	cout << Search(n,m,lamp);
	return 0;
}
