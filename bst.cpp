#include "ds.h"

bst::bst() {
	root = NULL;
}
bst::~bst() {

}
int bst::insert(int value){
	leaf* new_leaf = new leaf();
	
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	new_leaf->value = value;
	
	if (root == NULL) {
		root = new_leaf;
		return 1;
	}
	leaf** temp = &root;
	std::function < leaf** (leaf**, int)> find_spot;
	find_spot = [temp, value, &find_spot](leaf** curr_leaf, int val) -> leaf **{
		if (*curr_leaf == NULL) {
			return curr_leaf;
		}
		else if ((*curr_leaf)->value < val) {
			return find_spot(&((*curr_leaf)->right), val);
		}
		else if ((*curr_leaf)->value > val) {
			return find_spot(&((*curr_leaf)->left), val);
		}
		return curr_leaf;
	};

	leaf** new_spot = find_spot(temp, value);
	(*new_spot) = new_leaf;
	return 0;

}
int bst::access(int index){
	return 0;
}
leaf** bst::deletion_recursion(leaf** current, int value) {
	if (!(*current)) {
		return current;
	}
	else if ((*current)->value > value) {
		return deletion_recursion(&((*current)->left), value);
	}
	else if ((*current)->value < value) {
		return deletion_recursion(&((*current)->right), value);
	}
	return current;
}
leaf** bst::get_leftest_leaf(leaf** current) {
	if ((*current)->left == NULL) {
		return current;
	}
	return get_leftest_leaf(&(*current)->left);
}
int bst::deletion(int value) {
	leaf** reference_pointer = deletion_recursion(&root, value);
	leaf* memory_pointer = (*reference_pointer);
	leaf** replacement_value;
	if (!(*reference_pointer)) {
		return -1;
	}
	if ((*reference_pointer)->left == NULL && (*reference_pointer)->right == NULL) {
		(*reference_pointer) = NULL;
	}
	else if ((*reference_pointer)->left == NULL) {
		memory_pointer = (*reference_pointer)->right;
		(*reference_pointer)->value = (*reference_pointer)->right->value;
		(*reference_pointer)->left = (*reference_pointer)->right->left;
		(*reference_pointer)->right = (*reference_pointer)->right->right;

	}
	else if ((*reference_pointer)->right == NULL) {
		memory_pointer = (*reference_pointer)->left;
		(*reference_pointer)->value = (*reference_pointer)->left->value;
		(*reference_pointer)->right = (*reference_pointer)->left->right;
		(*reference_pointer)->left = (*reference_pointer)->left->left;
		
	}
	else {
		replacement_value = get_leftest_leaf(&(*reference_pointer)->right);
		(*reference_pointer)->value = (*replacement_value)->value;

		if ((*replacement_value)->right) {
			memory_pointer = (*replacement_value)->right;
			(*replacement_value)->value = (*replacement_value)->right->value;
			(*replacement_value)->left = (*replacement_value)->right->left;
			(*replacement_value)->right = (*replacement_value)->right->right;
			
			
		}
		else {
			memory_pointer = (*replacement_value);
			(*replacement_value) = NULL;
			
		}

	}
	int x = 0;
	delete memory_pointer;
	return 0;
}
int bst::search(int value){
	return 0;
}
void bst::print() {
	cout << "inorder: ";
	print_inorder(root);
	cout << endl;

	cout << "postorder: ";
	print_postorder(root);
	cout << endl;

	cout << "preorder: ";
	print_preorder(root);
	cout << endl;
}
int bst::print_inorder(leaf* current) {
	if (current == NULL) {
		return 0;
	}
	print_inorder(current->left);
	cout << current->value << " ";
	print_inorder(current->right);
	return 0;
}
int bst::print_postorder(leaf* current) {
	if (current == NULL) {
		return 0;
	}
	print_postorder(current->left);
	print_postorder(current->right);
	cout << current->value << " ";
	return 0;
}
int bst::print_preorder(leaf* current) {
	if (current == NULL) {
		return 0;
	}
	cout << current->value << " ";
	print_preorder(current->left);
	print_preorder(current->right);
	return 0;
}