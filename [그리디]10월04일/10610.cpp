#include<iostream>  
#include<string>  
#include<algorithm> 
using namespace std;

//30�� ����� �Ǵ� ���ڸ� ����� ��

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string num;
    cin >> num;
    sort(num.begin(), num.end(), greater<>());

    int sum = 0; //�� �ڸ������� ���Ѱ� sum
    bool TF = false; //TF�� 0 �� ������ -1 ���

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