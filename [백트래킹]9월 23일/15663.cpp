// n:4 m:2
//9 7 9 1
//n���� ���� �Է� �� ���� ����(�ߺ�����)
//�ϴ� ���� ���� 
//n�� m������ 15649 ����

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//1 �� M �� N �� 8
int n, m;

const int SIZE = 8;

//����Լ� ��� ��, �Լ��� ��� ȣ���� �� �Ű������� �����ǹǷ� ���������� �����ϴ� ���� �� ȿ����
//int input[SIZE], num[SIZE] ;
//bool check[SIZE] = { false };

vector<int> input(SIZE), num(SIZE);
vector<bool> check(SIZE+1);

void backtracking(int cnt) { //cnt: ������ �ε���
    if (cnt == m) { //m���� ���� ���� ��� (���� ����)
        for (int i = 0; i < m; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int pre_n = 0;
    for (int i = 0; i < n; i++) { //i: ������ ��
        if (!check[i]&& pre_n != input[i]) { //���� ������ �ش� ���� ���ٸ� -> ��� ����
            num[cnt] = input[i]; //���
            pre_n = input[i];
            check[i] = true;
            backtracking(cnt + 1); //���� �ε��� �� ȣ��
            //�ٽ� ���ƿ��� ��
            check[i] = false; //���� ���·� ��������
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
    
    //����
    backtracking(0);
    return 0;
}
