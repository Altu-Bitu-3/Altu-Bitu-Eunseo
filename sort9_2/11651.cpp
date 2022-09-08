
//입력 n
//y(-1)< y(0) 처럼 증가순으로 y값이 동일하다면 x(1)<x(2)증가순으로  

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coord {
	int x, y;
};

bool cmpYX(const coord& a, const coord& b) {
	if (a.y != b.y) {// y값이 다를 때
		return a.y < b.y;
	}
	else {// y값이 같을 때
		return a.x < b.x;

	}
}

int main() {
	int n; //입력 개수
	cin >> n;

	vector <coord> plane(n);

	for (int i = 0; i < n; i++) {
		cin >> plane[i].x >> plane[i].y;
	}
	sort(plane.begin(), plane.end(), cmpYX);


	for (int i = 0; i < n; i++) {
		cout << plane[i].x << ' ' << plane[i].y << "\n";
	}
}

