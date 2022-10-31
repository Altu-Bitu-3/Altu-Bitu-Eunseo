#include <iostream>
#include <queue>

using namespace std; 
struct cmp {
    bool operator()(const int& x1, const int& x2) {//���� ���� ���� �켱���� 
        
        return x2 < x1;
    }
}; 
int main() {
    // ����� �ӵ� ���
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    // �Է�
    cin >> n;
    // �켱���� ť ����
    priority_queue<int, vector<int>, cmp> pq;//cmp�� �Է°��� 1 7 3 �� ��  pq 1 3 7�� �Է�
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {//���� ���� �־����� ���� , 0�� �� 
            if (pq.empty()) { cout << 0 << "\n"; }//���� ����� ������ 0���
            else {
                cout << pq.top() << "\n";// ���� ���� ������ ��� ��
                pq.pop();//ť���� ����
            }
        }else{//x�� �ڿ��� �� ��
            pq.push(x);
        }
    }


    return 0;
}