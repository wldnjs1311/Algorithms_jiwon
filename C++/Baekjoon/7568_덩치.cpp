#include <iostream>
#include <vector>

using namespace std;

class _pair {
	int hei;
	int wei;
public:
	_pair(){}
	_pair(int hei, int wei) {
		this->hei = hei;
		this->wei = wei;
	}

	bool operator>(const _pair other) {
		if (this->hei > other.hei && this->wei > other.wei)
			return true;
		return false;
	}
};


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N;
	_pair* arr;

	cin >> N;
	arr = new _pair[N];

	for (int i = 0; i < N; i++) {
		int hei, wei;
		cin >> wei >> hei;

		_pair tmp(hei, wei);
		arr[i] = tmp;
	}

	for (int i = 0; i < N; i++) {
		int rate = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[j] > arr[i]) rate++;
		}
		cout << rate << " ";
	}
}