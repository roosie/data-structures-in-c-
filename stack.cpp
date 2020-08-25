#include "ds.h"

stack::stack(int value) : linked_list(value) {
	length++;
}
stack::~stack() {

}
int stack::pop() {
	length--;
	node* temp_node = head;
	return deletion(length);
}
int stack::push(int value) {
	length++;
	return insertion(value);
}