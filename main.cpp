#include "ds.h"
#include "sorting.h"

int main(int argc, char* argv[]) {
	/*
	linked_list *x = new linked_list(1);
	x->insertion(2);
	x->insertion(3);
	x->insertion(4);
	x->insertion(5);
	x->insertion(6);
	x->insertion(7);

	x->deletion(2);
	int index = x->search(7);
	int value = x->access(5);

	stack* y = new stack(1);
	y->push(2);
	y->push(3);
	y->push(4);
	y->push(5);
	int popped = y->pop();
	int popped2 = y->pop();

	queue* z = new queue(1);
	z->push(2);
	z->push(3);
	z->push(4);
	z->push(5);
	int got = z->pop();
	int got2 = z->pop();

	bst* tree = new bst();
	tree->insert(10);
	tree->insert(20);
	tree->insert(25);
	tree->insert(15);
	tree->insert(17);
	tree->insert(5);
	tree->insert(3);
	tree->insert(8);
	tree->print();
	tree->deletion(10);
	tree->print();
	tree->insert(1);
	tree->insert(2);
	tree->deletion(5);
	tree->print();
	*/

	int arr[12] = {1, 2, 3, 6, 7, 8, 4, 3, 1, 3, 4, 5};

	int* arr2 = quicksort(arr, 0, 11);

	while (*arr2) {
		cout << *arr2++ << endl;;
	}
	return 0;
}