#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, std, sex, input_n;
    bool arr[100];
    cin >> n;  //����ġ�� ���� �Է�

    for (int i = 1; i <= n; i++)  cin >> arr[i];  //����ġ�� ���� �Է�  (on :1, off : 0)

    cin >> std;   //�л� �� �Է�

    while (std--) {

        cin >> sex >> input_n;  //�л��� ���� ,  ���� ��

        if (sex == 1) {  //���л�
            for (int i = 1; i <= n; i++)   
                if(i %input_n ==0) arr[i] =! arr[i];  //����ġ�� ���� ����
        
        }  else {  //���л�  
            arr[input_n] =! arr[input_n];
            for (int i = 1; arr[input_n - i] == arr[input_n + i] ; i++) {
                if ((input_n - i) < 1 || (input_n + i )> n) break;

                arr[input_n + i] =! arr[input_n + i];
                arr[input_n - i] =! arr[input_n - i];
            }
        }
    }

    for (int i = 1; i <= n; i++)    {
        cout << arr[i] << ' ';
        if (i % 20 == 0) cout << "\n";  //20����  ���  �� �ٹٲٱ�
            
    }

}