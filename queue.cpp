#include "ds.h"

queue::queue(int value) : linked_list(value) {
	length++;
}
queue::~queue() {

}
int queue::pop() {
	length--;
	node* temp_node = head;
	return deletion(0);
}
int queue::push(int value) {
	length++;
	return insertion(value);
}