#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, std, sex, input_n;
    bool arr[100];
    cin >> n;  //스위치의 개수 입력

    for (int i = 1; i <= n; i++)  cin >> arr[i];  //스위치의 상태 입력  (on :1, off : 0)

    cin >> std;   //학생 수 입력

    while (std--) {

        cin >> sex >> input_n;  //학생의 성별 ,  받은 수

        if (sex == 1) {  //남학생
            for (int i = 1; i <= n; i++)   
                if(i %input_n ==0) arr[i] =! arr[i];  //스위치의 상태 변경
        
        }  else {  //여학생  
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
        if (i % 20 == 0) cout << "\n";  //20개의  출력  시 줄바꾸기
            
    }

}