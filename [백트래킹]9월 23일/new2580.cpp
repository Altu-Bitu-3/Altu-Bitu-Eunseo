//������ ���� 0�� ���� ã��
// ���� | ���� | 3*3 Ž��

#include<iostream>
#include <vector>
using namespace std;


int main() {
	//int 9x9  - �Է°� �־��� �迭
	int num[9][9];
	//bool 9x9x9 �ϳ� check[����][����][3*3]
	bool check[9][9][9] = { };

	memset(check, true, sizeof(check));//���� true�� �ٲٱ�
	/*
	* ���ؿ��� memset �۵�X...why?
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) { check[i][j][k] = true; }
		}
	}*/

	//�Է�
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num[i][j]; //9*9 �迭�� �־���
			} 
		}
	int n = 4;
	while (n--) {
		for (int i = 0; i < 9; i++)	{
			for (int j = 0; j < 9; j++)	{
				// 0 �� ���� üũ��
				if (num[i][j] == 0)	{
					for (int k = 0; k < 9; k++)	{
						// ���� üũ
						if (j != k && num[i][k] != 0)	check[i][j][num[i][k] - 1] = false;//���� �ٿ��� num[i][k]�� 0�� �ƴϸ� false�� �־ ����
						// ���� üũ
						if (i != k && num[k][j] != 0)	check[i][j][num[k][j] - 1] = false;//���� �ٿ��� num[k][j]�� 0�� �ƴϸ� false�� �־ ����
					}
					//3*3 üũ
					int iSub = i / 3;//3*3 ������ ���� ���
					int jSub = j / 3;//3*3 ������ ���� ���
					for (int m = 0; m < 2; m++){
						for (int n = 0; n < 2; n++)	{
							if (num[iSub * 3 + m][jSub * 3 + n] != 0)//0�� �ƴ� ��
								check[i][j][num[iSub * 3 + m][jSub * 3 + n] - 1] = false;//false�� ����
						}
					}

					// true �� ������ �����ִ� ����
					int iTrueCount = 0;
					int k1 = 0; // ���� �����ϴ� Temp
					for (int k = 0; k < 9; k++){
						if (check[i][j][k])		{ 
							iTrueCount++;//true�� +1		
						k1 = k + 1;//�ε����� ���־� n-1�̹Ƿ� +1
						}
					}
					if (iTrueCount == 1)	{	num[i][j] = k1;	}// �Ѱ��� ��� num[i][j] �� ���� ���� -> �ٸ� ���� �������� �ʱ� ������
				}
			}
		}
	}
	  //���
	  for (int i = 0; i < 9; i++) {
		  for (int j = 0; j < 9; j++) {
			  cout << num[i][j] << ' ';
		  }cout << '\n';
	  }


	  return 0;
}
