#include <iostream>
#include <string>

using namespace std;

#define max_size 10001
int arr[max_size];

class deque {
private:
	int start;
	int end;
	int size;

public:
	deque() {
		start = 0;
		end = 0;
		size = 0;
	}

	void push_front(int x) {
		if (size > 0)
			start = (start - 1 + max_size) % max_size;
		arr[start] = x;
		size++;
	}

	void push_back(int x) {
		if (size > 0)
			end = (end + 1) % max_size;
		arr[end] = x;
		size++;
	}

	int pop_front() {
		if (empty()) return -1;
		int tmp = arr[start];
		start = (start + 1) % max_size;
		size--;
		if (size == 0) end = start;
		return tmp;
	}

	int pop_back() {
		if (empty()) return -1;
		int tmp = arr[end];
		end = (end - 1 + max_size) % max_size;
		size--;
		if (size == 0) start = end;
		return tmp;
	}

	int getSize() {
		return size;
	}

	int empty() {
		if (size == 0)return 1;
		return 0;
	}

	int front() {
		if (empty()) return -1;
		return arr[start];
	}

	int back() {
		if (empty()) return -1;
		return arr[end];
	}

};



int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N;
	string str;
	deque D;
	cin >> N;

	while (N--) {
		cin >> str;
		if (str == "push_front") {
			int x;
			cin >> x;
			D.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			D.push_back(x);
		}
		else if (str == "pop_front") {
			cout << D.pop_front() << "\n";
		}
		else if (str == "pop_back") {
			cout << D.pop_back() << "\n";
		}
		else if (str == "size") {
			cout << D.getSize() << "\n";
		}
		else if (str == "empty") {
			cout << D.empty() << "\n";
		}
		else if (str == "front") {
			cout << D.front() << "\n";
		}
		else if (str == "back") {
			cout << D.back() << "\n";
		}

	}
}