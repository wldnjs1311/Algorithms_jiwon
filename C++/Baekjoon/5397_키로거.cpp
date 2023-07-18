#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

class node {
private:
	node* pre;
	node* next;
	char character;
public:
	node() {
		this->pre = NULL;
		this->next = NULL;
		character = ' ';
	}
	~node() {
		delete pre;
		delete next;
	}
	friend class List;
};

class List {
private:
	int size;
	node* head;
	node* cursor;
public:
	List() {
		size = 0;
		head = NULL;
		cursor = new node();
	}
	void _input(char c) {
		if (c == '<' || c == '>') {
			moveCursor(c);
		}
		else if (c == '-') {
			deleteChar();
		}
		else {//
			node* tmp;
			tmp->character = c;

			cursor->pre->next = tmp;
			tmp->pre = cursor->pre;

			tmp->next = cursor;
			cursor->pre = tmp;
		}
	}

	void moveCursor(char c) {//
		if (c == '<') {
			if (cursor->pre = NULL) return;

			cursor->pre->next = cursor->next;
			cursor->next->pre = cursor->pre;

			cursor->next = cursor->pre;
			cursor->pre = cursor->next->pre;

			cursor->pre->next = cursor;
		}
		else {

		}
	}

	void deleteChar() {
		if (cursor->pre == NULL) return;
		cursor->pre = cursor->pre->pre;

		if (cursor->pre == NULL) return;
		cursor->pre->next = cursor;
	}

	void printList() {
		node* tmp = head;

		cout << head->character;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			cout << tmp->character;
		}
		cout << "\n";
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		List L;
		string password;
		cin >> password;

		for(char c : password) {
			L._input(c);
		}

		L.printList();
	}
}