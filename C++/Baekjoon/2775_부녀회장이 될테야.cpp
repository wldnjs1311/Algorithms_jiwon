#include <iostream>

using namespace std;

int people(int floor, int room) {
	if (floor == 0) return room;
	int sum=0;
	
	for (int i = 1; i <= room; i++) {
		sum += people(floor - 1, i);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T, k, n;

	cin >> T;

	while (T--) {
		cin >> k >> n;
		cout << people(k, n) << "\n";
	}
}


