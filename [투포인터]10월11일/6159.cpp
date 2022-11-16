
#include <vector>
#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s; //첫째 줄에는 정수 N(소의 수)과 S(코스튬의 크기)
    cin >> n >> s;

    vector<int> cow(n);

    for (int i = 0; i < n; i++) {
        int size;
        cin >> cow[i] ;
    }
    //2개 합이 s보다 작으면 짝 가능하므로 
    int pair = 0;//짝 개수
    for (int i = 0; i < cow.size(); i++) { //2개 합이므로 인덱스 i, j 로 
        for (int j = n-1; i< j ; j--) {

            if (cow[i] + cow[j] <= s)        pair++;
            
        }
    }
    cout << pair ;
    return 0;
}