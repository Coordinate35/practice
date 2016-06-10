#include <stdio.h>
#include <stdlib.h>

struct tree_node {
	int val;
	struct tree_node *left;
	struct tree_node *right;
};

void show(struct tree_node* root) {
	if (NULL != root->left) {
		show(root->left);
	}

	printf("%d ", root->val);

	if (NULL != root->right) {
		show(root->right);
	}
}

void insert(struct tree_node *root, int element) {
	struct tree_node *current, *last;
	current = root;
	while (NULL != current) {
		if (element <= current->val) {
			last = current;
			current = current->left;
		} else {
			last = current;
			current = current->right;
		}
	}
	current = (struct tree_node*)malloc(sizeof(struct tree_node));
	if (element <= last->val) {
		last->left = current;
	} else {
		last->right = current;
	}
	current->val = element;
}

struct tree_node* find_max(struct tree_node *root) {
	while (NULL != root->right) {
		root = root->right;
	}
	return root;
}

struct tree_node* find_sub_max(struct tree_node *root) {
	struct tree_node* last;
	while (NULL != root->right) {
		last = root;
		root = root->right;
	}
	return last;
}

struct tree_node* delete_node(struct tree_node *target, struct tree_node *father) {
	struct tree_node *replace_node, *left_max, *left_max_father;
	if ((NULL == target->left) && (NULL == target->right)) {
		if (NULL != father) {
			if (target == father->left) {
				father->left = NULL;
			} else {
				father->right = NULL;
			}
		}
		free(target);
		return NULL;
	} else if ((NULL != target->left) && (NULL != target->right)) {
		left_max = find_max(target->left);
		if (left_max == target->left) {
			left_max_father = target;
		} else {
			left_max_father = find_sub_max(target->left);
		}
		replace_node = (struct tree_node*)malloc(sizeof(struct tree_node));
		replace_node->val = left_max->val;
		delete_node(left_max, left_max_father);
		if (NULL != father) {
			if (target == father->left) {
				father->left = replace_node;
			} else {
				father->right = replace_node;
			}
		}
		replace_node->left = target->left;
		replace_node->right = target->right;
		free(target);
		return replace_node;
	} else {
		if (NULL == target->left) {
			if (NULL != father) {
				if (father->left == target) {
					father->left = target->right;
				} else {
					father->right = target->right;
				}
			}
			replace_node = target->right;
		} else {
			if (NULL != father) {
				if (father->left == target) {
					father->left = target->left;
				} else {
					father->right = target->left;
				}
			}
			replace_node = target->left;
		}
		free(target);
		return replace_node;
	}
}

struct tree_node* delete(struct tree_node *current, struct tree_node *father, int value) {
	struct tree_node *left_max, *root;
	root = current;
	while ((NULL != current) && (value != current->val)) {
		if (value <= current->val) {
			father = current;
			current = current->left;
		} else {
			father = current;
			current = current->right;
		}
	}

	if (NULL == current) {
		return root;
	}

	if (NULL == father) {
		current = delete_node(current, father);
		current = delete(current, father, value);
		root = current;
	} else {
		current = delete_node(current, father);
		current = delete(current, father, value);
	}
	
	return root;
}

struct tree_node* form_tree(int n, int* numbers) {
	int i;
	struct tree_node* root;
	root = (struct tree_node*)malloc(sizeof(struct tree_node));
	root->val = numbers[0];
	for (i = 1; i < n; i++) {
		insert(root, numbers[i]);
	}
	return root;
}

int main() {
	int n = 6;
	int numbers[] = {6, 6, 3, 9, 4, 5};
	struct tree_node *root;
	root = form_tree(n, numbers);
	show(root);
	printf("\n");
	root = delete(root, NULL, 6);
	show(root);
	return 0;
}