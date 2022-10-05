/*
n개 선물 상자 m 명의 아이들

각 상자의 선물 개수 present  에서 child - 주고 남는 선물 다음 사람이 가져갈 수 있음

아이가 원하는 선물 개수 child
큐와 우선순위 큐의 차이 :3 1 5라는 숫자가 들어왔을 때 큐는 순서대로 3 1 5로 처리 우선순위 큐는 5 3 1로 처리
*/
#include<iostream>
#include<queue>
using namespace std;
int p, c;
int presentChild(priority_queue<int> &present, int m) {
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (present.top() >= c) {//선물이 큰 개수가 맨앞에 정렬되므로 아이가 원하는 수보다 클 때만 가능
			present.push(present.top() - c);
			present.pop();
		}	else {	return 0;	}//조건 불충족 시
	}
	return 1;//모든 아이들이 선물을 가져갈 시
	
}
int main() {
	//입력
	int n, m;
	cin >> n >> m;
	priority_queue<int> present, child; //그냥 queue쓰면  다시 정렬해야하므로 우선순위 큐 선언
	
	for (int i = 0; i < n; i++) {
		cin >> p;
		present.push(p);
	}

	cout <<presentChild(present,m);
	

	return 0;

}