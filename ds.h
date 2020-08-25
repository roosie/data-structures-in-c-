#include <iostream>
#include <functional>

#ifndef ds
#define ds

using namespace std;

int init_hello();


class linked_list {
protected: 
	struct node* head;
	struct node* tail;
public: 
	linked_list(int val);
	~linked_list();
	int access(int index);
	int search(int value);
	int insertion(int value);
	int deletion(int index);
	void print();

};

class stack : public linked_list {
private: 
	int length;
public:
	stack(int value);
	~stack();
	int pop();
	int push(int value);
};

class queue : private linked_list {
private:
	int length;
public:
	queue(int value);
	~queue();
	int pop();
	int push(int value);
};

typedef struct node {
	struct node* child;
	int value;
};

class bst {
private: 
	struct leaf* root;
	leaf** deletion_recursion(leaf** current, int value);
	leaf** get_leftest_leaf(leaf** current);
	leaf** get_rightest_leaf(leaf** current);
	int print_inorder(leaf* current);
	int print_postorder(leaf* current);
	int print_preorder(leaf* current);
public: 
	bst();
	~bst();
	int insert(int value);
	int access(int index);
	int deletion(int value);
	int search(int value);
	void print();
};

typedef struct leaf {
	struct leaf* left;
	struct leaf* right;
	int value;
};
#endif