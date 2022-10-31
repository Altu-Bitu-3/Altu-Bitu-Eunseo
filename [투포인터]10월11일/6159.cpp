
#include <vector>
#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s; //ù° �ٿ��� ���� N(���� ��)�� S(�ڽ�Ƭ�� ũ��)
    cin >> n >> s;

    vector<int> cow(n);

    for (int i = 0; i < n; i++) {
        int size;
        cin >> cow[i] ;
    }
    //2�� ���� s���� ������ ¦ �����ϹǷ� 
    int pair = 0;//¦ ����
    for (int i = 0; i < cow.size(); i++) { //2�� ���̹Ƿ� �ε��� i, j �� 
        for (int j = n-1; i< j ; j--) {

            if (cow[i] + cow[j] <= s)        pair++;
            
        }
    }
    cout << pair ;
    return 0;
}