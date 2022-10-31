#include<iostream>
#include<string>
#include<vector>

using namespace std;

//���ٸ� ����: n ���ε� ����: m  ���ε� ��ġ x

int Search(int n, int m, vector<int>& lamp) {
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool flag = false;
        
        for (int i = 0; i < m - 1; i++) { //���� �� ���� ���� Ȯ��
            if (lamp[i + 1] - lamp[i] > mid * 2) { flag = true; break; }
        }
        if (lamp[0] > mid || n - lamp[m - 1] > mid) flag = true; //���� ���� & �� ���� Ȯ��
        if (!flag) { r = mid - 1; }
        else { l = mid + 1; }
    }
    return l;
}

int main() {
    //�ӵ� ������
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    //�Է�
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> lamp(m, 0);
	for (int i = 0; i < m; i++) { 		cin >> lamp[i]; 	}
	

    //���
	cout << Search(n,m,lamp);
	return 0;
}
