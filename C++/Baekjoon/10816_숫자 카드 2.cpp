#include <iostream>
#include <algorithm>

using namespace std;

int lowerBound(int m, int size, int* arr) {
	int mid;
	int start = 0; int end = size - 1;

	while (start <= end) {
		mid = (start + end) / 2;

		if (arr[mid] >= m)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return end;
}

int upperBound(int m, int size, int* arr) {
	int mid;
	int start = 0; int end = size - 1;

	while (start <= end) {
		mid = (start + end) / 2;

		if (arr[mid] > m)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return end;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;

	int* arrN;
	arrN = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arrN[i];
	}


	cin >> M;

	int* arrM;
	arrM = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> arrM[i];
	}

	sort(arrN, arrN + N);

	for (int i = 0; i < M; i++) {
		cout << upperBound(arrM[i], N, arrN) - lowerBound(arrM[i], N, arrN) << " ";
	}
}
