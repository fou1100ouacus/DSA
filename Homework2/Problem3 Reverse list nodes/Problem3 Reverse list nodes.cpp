// Problem2_Insert front.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data{ };
	Node* next{ };
	Node(int data) :
		data(data) {
	}

	~Node() {
		//To easily test your nodes are destructed
		cout << "Destroy value: " << data << "\n";
	}
};

class LinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int length = 0;	// let's maintain how many nodes
	vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

public:
	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	LinkedList(const LinkedList&) = delete;
	LinkedList& operator=(const LinkedList& another) = delete;

	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int)debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n" << flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
		for (Node* cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		}
		else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?
		assert(length == len);
		assert(length == (int)debug_data.size());
	}

	////////////////////////////////////////////////////////////

	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	// These 2 simple functions just to not forget changing the vector and length
	void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}

	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}

	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else
			tail->next = item, tail = item;
	}

	void insert_front(int val) {
		// O(1) time - O(1) memory
		Node* item = new Node(val);
		add_node(item);

		item->next = head;
		head = item;

		if (length == 1)
			tail = head;

		debug_verify_data_integrity();
	}
	void Delete_front()
	{
		// O(1) time - O(1) memory
		assert(length);
		Node* cur = head->next;
		delete_node(head);
		head = cur;

		if (length <= 1)
			tail = head;

		debug_verify_data_integrity();
	}

	Node* get_nth(int n) {
		int cnt = 0;
		for (Node* cur = head; cur; cur = cur->next)
			if (++cnt == n)
				return cur;

		return nullptr;
	}

	Node* FromBack_get_nth(int n) {			// O(n) time - O(1) memory
		// If we know the length, we can compute its normal position
		if (length < n)
			return nullptr;
		return get_nth(length - n + 1);	// give it its 1-based index forward
	}
	bool is_same1(const LinkedList& other) {		// O(n) time - O(1) memory
		Node* h1 = head, * h2 = other.head;

		while (h1 && h2)
		{
			if (h1->data != h2->data)
				return false;
			h1 = h1->next, h2 = h2->next;
		}
		return !h1 && !h2;	// make sure both ends together
	}

	bool is_same(const LinkedList& other) {	// using length
		if (length != other.length)
			return false;

		Node* other_h = other.head;

		for (Node* cur_h = head; cur_h; cur_h = cur_h->next) {
			if (cur_h->data != other_h->data)
				return false;
			other_h = other_h->next;
		}
		return true;
	}

	int search(int value) {
		int idx = 0;
		for (Node* cur = head; cur; cur = cur->next, idx++)
			if (cur->data == value) // Common Mistake to use head
				return idx;
		return -1;
	}
	int search_improved(int value) {
		int idx = 0;
		Node* prv = nullptr;
		for (Node* cur = head; cur; cur = cur->next, idx++)
		{
			if (cur->data == value) {
				if (!prv)// first item in list
					return idx;
				swap(prv->data, cur->data);
				return idx - 1;
			}
			prv = cur;
		}
		return -1;
	}
	void delete_nth_node(int n) {
		if (n < 1 || n > length)
			cout << "Error. No such nth node\n";
		else if (n == 1)
			Delete_front();
		else
		{
			// Connect the node before nth with node after nth
			Node* before_nth = get_nth(n - 1);
			Node* nth = before_nth->next;// we can get it from getnth method          gen_nth(n)
			bool is_tail = nth == tail;
			// connect before node with after
			before_nth->next = nth->next;
			if (is_tail)
				tail = before_nth;

			delete_node(nth);

			debug_verify_data_integrity();
		}
	}


	void delete_node_with_key(int value) {
		// These checks in method delete nth node
		/*if (!length)
			cout << "Empty list!\n";
		else if (head->data == value)
			Delete_front();*/

		int target = search(value);// O(n)
		//	Node * selectedNode=get_nth(target+1);
		delete_nth_node(target + 1);



	}

	//void swap_pairs()
	//  {
	//	Node* cur = head;
	//	int counter = 0;
	//	Node* prev = NULL;

	//	for (cur = head; cur; cur = cur->next)
	//	{
	//		counter++;
	//		prev = cur;

	//		cur = cur->next;
	//		if (counter == 2)
	//		{
	//			swap(cur->data, prev->data);
	//			counter = 0;
	//		}
	//	}
	//}
	void swap_pairs() {		// O(n) time - O(1) memory
		// For each 2 consecutive, swap data and jump cur->next->next
		for (Node* cur = head; cur; cur = cur->next) {
			if (cur->next) {// not null
				swap(cur->data, cur->next->data);
				cur = cur->next;
			}
		}
	}








};






int main()
{
	LinkedList list;

	cout << "-------" << endl;
	list.insert_end(333);
	list.insert_end(3);
	list.insert_end(7);
	list.insert_end(2);

	list.print();
	cout << "___________________" << endl;
	list.swap_pairs();
	list.print();



}

