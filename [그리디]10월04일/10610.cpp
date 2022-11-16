#include<iostream>  
#include<string>  
#include<algorithm> 
using namespace std;

//30의 배수가 되는 숫자를 만들면 됨

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string num;
    cin >> num;
    sort(num.begin(), num.end(), greater<>());

    int sum = 0; //각 자리수들을 더한값 sum
    bool TF = false; //TF로 0 이 없으면 -1 출력

    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '0') TF = true;
        sum += num[i] - '0';
    }
    if (TF && sum % 3 == 0) {

        cout << num << "\n";
    }
    else { cout << "-1"; }
    return 0;
}