
//�Է� n
//y(-1)< y(0) ó�� ���������� y���� �����ϴٸ� x(1)<x(2)����������  

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coord {
	int x, y;
};

bool cmpYX(const coord& a, const coord& b) {
	if (a.y != b.y) {// y���� �ٸ� ��
		return a.y < b.y;
	}
	else {// y���� ���� ��
		return a.x < b.x;

	}
}

int main() {
	int n; //�Է� ����
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

