#include "ds.h"

int init_hello() {
	cout << "hello data structures";
	return 0;
}

linked_list::linked_list(int val) {
	node* new_node = new node();
	head = new_node;
	tail = new_node;
	new_node->child = NULL;
	new_node->value = val;
}
linked_list::~linked_list() {
	
}
int linked_list::access(int index) {
	node* current = head;
	for (int i = 0; current; i++) {
		if (index == i) {
			return current->value;
		}
		current = current->child;
	}
	return -1;
}
int linked_list::search(int value) {
	node* current = head;
	for (int i = 0; current; i++) {
		if (value == current->value) {
			return i;
		}
		current = current->child;
	}
	return -1;
}
int linked_list::insertion(int value) {
	node *new_node = new node();
	new_node->value = value;
	new_node->child = NULL;
	tail->child = new_node;
	tail = new_node;
	if (head == NULL) {
		head = new_node;
	}
	return 0;
}
int linked_list::deletion(int index) {
	node* current = head;
	node* parent_temp = NULL;
	node* temp;
	int value = 0;
	if (index == 0) {
		value = head->value;
		head = head->child;
		delete current;
		return value;
	}
	for (int i = 0; current; i++) {
		value = current->value;
		if (i == index) {
			if (current->child) {
				node* temp = current->child;
				current->child = temp->child;
				current->value = temp->value;
				delete temp;
				return value;
			}
			else {
				delete parent_temp->child;
				parent_temp->child = NULL;
				tail = parent_temp;
				return value;
			}
		}
		parent_temp = current;
		current = current->child;
	}
	return -1;
}
void linked_list::print() {
	node* temp = head;
	while (temp) {
		cout << temp->value;
		temp = temp->child;
	}
}