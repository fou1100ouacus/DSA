
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data) : data(data) {};
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

	string debug_to_string()
	{
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
		if (length == 0)
		{
			assert(head == nullptr);
			assert(tail == nullptr);
		}
		else
		{
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

	void print()
	{
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

	void insert_end(int value)
	{
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else
			tail->next = item, tail = item;
	}

	void insert_front(int value) {
		Node* item = new Node(value);
		add_node(item);

		item->next = head;
		head = item;

		if (length == 1)
			tail = head;
	}
	void delete_front() {
		assert(length);
		Node* cur = head->next;
		delete_node(head);
		head = cur;
	}
	////////////////////////////////////////////////////////////

	void delete_first()
	{
		if (head) {
			//Move to next in the list
			// and remove current
			Node* cur = head;
			head = head->next;
			delete_node(cur);

			if (!head)	// data integrity!
				tail = nullptr;
			debug_verify_data_integrity();
		}
	}

	Node* get_nth(int n) {
		int cnt = 0;
		for (Node* cur = head; cur; cur = cur->next)
			if (++cnt == n)
				return cur;

		return nullptr;
	}

	void delete_last() {
		if (length <= 1) {
			delete_first();
			return;
		}
		// Get the node before tail: its order is length-1 node
		Node* previous = get_nth(length - 1);

		delete_node(tail);
		tail = previous;
		tail->next = nullptr;

		debug_verify_data_integrity();
	}

	void delete_nth_node(int n) {
		if (n < 1 || n > length)
			cout << "Error. No such nth node\n";
		else if (n == 1)
			delete_first();
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



	//----------------------------------------------------



	void PrintIteration(Node* head) {
		while (head != nullptr) {
			cout << head->data << " -> ";
			head = head->next;
		}
		cout << "\n";
	}
	void printRecursively(Node* head) {
		if (head == nullptr) {
			cout << "\n";
			return;
		}
		cout << head->data << " -> ";
		printRecursively(head->next);
	}
	void printReversed(Node* head) {
		if (head == nullptr) {
			return;
		}
		printReversed(head->next);
		cout << head->data << " <- ";
	}

	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}
	void print() {
		// DON'T change head itself.
		// 		You will lose it
		Node* temp_head = head;
		while (temp_head != nullptr) {
			cout << temp_head->data << " -> ";
			temp_head = temp_head->next;
		}
		cout << "\n";
	}
	Node* getNode(int n)
	{
		int counter = 0;
		for ( Node*current = head; current ; current=current->next)
		{
			if (n==++counter)
			{
				return current;
			}
		}
		return NULL;

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
	int search_improved_v2(int value) {
		int idx = 0;

		for (Node* cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next) {
			if (cur->data == value) {
				if (!prv)
					return idx;
				swap(prv->data, cur->data);
				return idx - 1;
			}
			++idx;
		}
		return -1;
	}




};
int main()
{
	LinkedList list;

	cout << "-------" << endl;
 //  list.printRecursively(node1);
	list.insert_end(333);
	list.insert_end(3);
	list.insert_end(7);
	list.insert_end(2);

	list.print();
	cout << "___________________" << endl;
	list.swap_pairs();
	list.print();





}

