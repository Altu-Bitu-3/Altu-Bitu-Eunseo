
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
		//unique 중복값을 뒤로 보냄
		word.erase(unique(word.begin(), word.end()), word.end());//abcb로 earse로 중복값 제거
		sort(word.begin(), word.end());//abbc로 정렬
		
		for(int j=0; j<word.size(); j++){
			
			if(word[j] == word[j+1]){//word[1] ,word[2]가 둘다 b이므로 그룹단어X
				group = false;
				break;			
				}				
			}
	
		if(group) tot++;
	}
	
	cout << tot;

    return 0;
}