
#include <iostream>
#include<algorithm>
using namespace std;

int main(){	
	int n, tot = 0;
	string word;
	cin >> n;
	
	for(int i=0; i<n; i++){
		bool group = true;
		cin >> word;//aabbbccb
		//unique �ߺ����� �ڷ� ����
		word.erase(unique(word.begin(), word.end()), word.end());//abcb�� earse�� �ߺ��� ����
		sort(word.begin(), word.end());//abbc�� ����
		
		for(int j=0; j<word.size(); j++){
			
			if(word[j] == word[j+1]){//word[1] ,word[2]�� �Ѵ� b�̹Ƿ� �׷�ܾ�X
				group = false;
				break;			
				}				
			}
	
		if(group) tot++;
	}
	
	cout << tot;

    return 0;
}