#pragma once
template<typename T>
struct stack {
	struct Node {
		//Node() :info(0), next(nullptr) {};
		explicit Node(int a) :info(a), next(nullptr) {};
		Node(T a, Node* anext) :info(a), next(anext) {};

		T info;
		Node* next = nullptr;
	};

	stack() : first(nullptr), length(0) {};

	void push(T x) {
		first = new Node(x, first);
		length++;
	}

	bool IsEmpty() {
		if (first != nullptr)
			return 0;
		return 1;
	}

	bool pop() {
		if (first == nullptr)
			return 0;
		Node* p = first;
		first = p->next;
		delete p;
		length--;
		return 1;
	}

	T top() {
		return first->info;
	}

	int size() {
		return length;
	}

private:
	Node* first;
	int length;
};