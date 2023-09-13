#pragma once
#include "Node_Tree.h"
#include <iostream>
#include <queue>
#include <math.h>
#include <winsock.h>

using namespace std;

///socket.LoadLibrary()



template <class T>
class Tree  {
private:
	Node_Tree<T>* _node;
	static int num_of_leafs;
public:
	Tree() {
		this->num_of_leafs++;
		_node = new Node_Tree<T>();
	}
	Tree(const Node_Tree<T>* p) {
		this->_node = new Node_Tree<T>(*p); this->num_of_leafs++; }
	~Tree() {
		delete this->_node;
		cout << "tree deleted"<<endl;
	}
	Node_Tree<T>* get_node() { return this->_node; }
	void set_node(const Node_Tree<T>* p) { this->_node = p; }
    int num_of_leafss() { return (this->num_of_leafs); }
	
	
	
	//
	void replace_in_head_tree_by_value(const T key) {
		if (this->_node == NULL) {
			this->_node = new Node_Tree<T>(key);
		}
		else {
			this->node->set_key(key);
		}
	}
	void replace_in_head_tree(Node_Tree<T>* p,const T key) {
		if (p == NULL) {
			p = new Node_Tree<T>(key);
		}
		else {
			p->set_key(key);
		}
	}
	void replace_in_head(Node_Tree<T>* p) {
		Node_Tree<T>* temp = p;
		p = this->_node;
		this->_node = temp;
	}
	
	
	//
	void insert(Node_Tree<T>* p ,const T key) {
		Node_Tree<T>* pointer = p;
		Node_Tree<T>* left = p->get_left();
		Node_Tree<T>* right = p->get_right();

		if (pointer->get_key() < key && pointer->get_right() == NULL) {
			right = new Node_Tree<T>(key);
			conect_2_nodes_(pointer, right);
			this->_node = this->balance_all_tree_recursive(right->get_parent());
			this->fix_hight_nodes_tree(this->_node);
			(this->num_of_leafs)++;
			return;
		}
		else if (pointer->get_key() >= key && pointer->get_left() == NULL) {
			left = new Node_Tree<T>(key);
			conect_2_nodes_(pointer, left);
			this->_node = this->balance_all_tree_recursive(left->get_parent());
			this->fix_hight_nodes_tree(this->_node);
			(this->num_of_leafs)++;
			return;
		}
		if (pointer->get_key() > key)
			insert(pointer->get_left(), key);
		else
			insert(pointer->get_right(), key);
	}
	void delete_node(T key) {
		Node_Tree<T>* first = this->search_by_key_return_node(this->_node, key);
		Node_Tree<T>* numfoll = NULL;
		Node_Tree<T>* father = NULL;
		Node_Tree<T>* left = NULL;
		Node_Tree<T>* right = NULL;
		if (first == NULL) {
			cout << "key not in tree" << endl;
			return;
		}
		Node_Tree<T>* pfn = NULL;
		pfn =first->get_parent();
		numfoll = this->following_number_and_delete_him(first);
		father = first->get_parent();
		left = first->get_left();
		right = first->get_right();
		if (numfoll == NULL) {
			if (right == NULL && left == NULL) {
				if (father->get_right() == first) {
					father->set_right(NULL);
				}
				else if (father->get_left() == first)
				{
					father->set_left(NULL);
				}
			}
			this->conect_2_nodes_(father, left);
			cout << "deleted" << endl;
			(this->num_of_leafs)--;
			this->_node = this->balance_all_tree_recursive(pfn->get_parent());
			this->fix_hight_nodes_tree(this->_node);
			return;
		}
		else {
			this->conect_2_nodes_(father, numfoll);
			this->conect_2_nodes_(numfoll, right);
			this->conect_2_nodes_(numfoll, left);
			cout << "deleted!!" << endl;
			(this->num_of_leafs)--;
			this->_node = this->balance_all_tree_recursive(pfn->get_parent());
			this->fix_hight_nodes_tree(this->_node);
			return;
		}
	}
	
	
	//
	void disconect_node(Node_Tree<T>* father, Node_Tree<T>* son) {
		if (father->get_key() >= son->get_key()) {
			father->set_left(NULL);
			son->set_parent(NULL);
		}
		else {
			father->set_right(NULL);
			son->set_parent(NULL);
		}
	}
	void conect_2_nodes_(Node_Tree<T>* dad, Node_Tree<T>* son) {
		
		if (son != NULL) {
			son->set_hight_node(dad->get_hight_node() + 1);
			son->set_parent(dad);
			if (dad->get_key() <= son->get_key()) {
				dad->set_right(son);
			}
			else {
				dad->set_left(son);
			}
		}
	}
	void print_inorder( Node_Tree<T>* p) {
		if (p == NULL) {
			return;
		}
		print_inorder(p->get_left());
		cout << *p;
		print_inorder(p->get_right());
	}


	///////////////////////////////////////
	void print_visual_tree(Node_Tree<T>* k) {
		if (p == NULL) { return; }
	

	}
	
	
	
	bool search_by_key(Node_Tree<T>* p,const T key) {
		Node_Tree<T>* p2 = p;
		if (p2->get_key() == key) {
			cout << "true" << endl;
			return true;
		}
		else if (p2->get_key() < key && p2->get_right() != NULL) {
			search_by_key(p2->get_right(), key);
		}
		else if (p2->get_key() > key && p2->get_left() != NULL) {
			search_by_key(p2->get_left(), key);
		}
		else {
			cout << "false" << endl;
			return false;
		}
	}
    Node_Tree<T>* search_by_key_return_node(Node_Tree<T>* p, T key) {
		Node_Tree<T>* p2 = p;
		if (p2 == NULL) {
			return NULL;
		}
		if (p2->get_key() == key) {
			return p2;
		}
		else if (p2->get_key() < key && p2->get_right() != NULL) {
			search_by_key_return_node(p2->get_right(), key);
		}
		else if (p2->get_key() > key && p2->get_left() != NULL) {
			search_by_key_return_node(p2->get_left(), key);
		}
	}
	//if no follwing num return null // change node to his follow num//
	Node_Tree<T>* following_number_and_delete_him(Node_Tree<T>* node) {
		Node_Tree<T>* p = node;
		int flag = 0;
		if (p->get_right() != NULL) {
			p = p->get_right();
			while (p->get_left() != NULL) {
				p = p->get_left();
				flag = 1;
			}
		}
		else {
			return NULL;
		}
		if (flag == 1) {
			Node_Tree<T>* z = p->get_parent();
			//delete z->get_left();
			z->set_left(NULL);
			cout << p->get_key() << endl;
			return p;
		}
		else {
			Node_Tree<T>* z = p->get_parent();
			//delete z->get_right();
			z->set_right(NULL);
			z->set_key(p->get_key());
			cout << p->get_key() << endl;
			return p;
		}
	} 	
	
	
	//
	void zero_head() {
		this->_node->set_hight_node(0);
	}
	void fix_recursive_the_hight(Node_Tree<T>*p){
		if (p == NULL) {
			return;
		}
		else if(p->get_parent()==NULL)
		{
			p->set_hight_node(0);
		}
		else {
			Node_Tree<T>* z = p->get_parent();
			p->set_hight_node(z->get_hight_node() + 1);
		}
		fix_recursive_the_hight(p->get_left());
		fix_recursive_the_hight(p->get_right());
	}
	void fix_hight_nodes_tree(Node_Tree<T>*p) {
		Node_Tree<T>* k = p;
		this->zero_head();
		this->fix_recursive_the_hight(k);
	}
	//
	int hight(Node_Tree<T>* node)
	{
		if (node == NULL)
			return 0;
    	return 1 + max(hight(node->get_left()), hight(node->get_right()));
	}
	bool isBalanced(Node_Tree<T>* root)
	{
		// for height of left subtree
		int lh;

		// for height of right subtree
		int rh;

		// If tree is empty then return true
		if (root == NULL)
			return 1;

		// Get the height of left and right sub trees
		lh = height(root->get_left());
		rh = height(root->get_right());

		if (abs(lh - rh) <= 1 && isBalanced(root->get_left())
			&& isBalanced(root->get_right()))
			return 1;

		// If we reach here then tree is not height-balanced
		return 0;
	}
	int getBalanceFactor(Node_Tree<T>* N) {
		if (N == NULL)
			return 0;
		return hight(N->get_left()) - hight(N->get_right());
	}
	
	
	// 
	Node_Tree<T>* balance_all_tree(Node_Tree<T>* node) 
	{
		Node_Tree<T>* node_p = node->get_parent();
		if (getBalanceFactor(node) > 1) {
			Node_Tree<T>* p = node->get_left();
			if (getBalanceFactor(p) >= 1)
			{
				 node=this->L_L_rotation(node);
			}
			else {
				node=this->L_R_rotation(node);
			}
		}
		else if (getBalanceFactor(node) < -1) {
			Node_Tree<T>* p = node->get_right();
			if (getBalanceFactor(p) >= 1)
			{
				node = this->R_L_rotation(node);
			}
			else {
				node = this->R_R_rotation(node);
			}
		}
		if (node_p != NULL) {
			conect_2_nodes_(node_p, node);
		}
		else {
			node->set_parent(NULL);
		}
		return node;
	}
	Node_Tree<T>* balance_all_tree_recursive(Node_Tree<T>* p) {
		Node_Tree<T>* z = p;
		if (z->get_parent() != NULL) {
			z = this->balance_all_tree(z);
			this->balance_all_tree_recursive(z->get_parent());
		}
		else {
			return this->balance_all_tree(z);
		}
	}
	//
	Node_Tree<T>* L_L_rotation(Node_Tree<T>* root) {
		Node_Tree<T>* child = root->get_left();
		Node_Tree<T>* grandchild = child->get_left();
		Node_Tree<T>* child_right = child->get_right();
		this->conect_2_nodes_(child, root);
		root->set_left(child_right);
		return child;
	}
	Node_Tree<T>* R_R_rotation(Node_Tree<T>* root) {
		Node_Tree<T>* child = root->get_right();
		Node_Tree<T>* grandchild = child->get_right();
		Node_Tree<T>* child_left = child->get_left();
		this->conect_2_nodes_(child, root);
		root->set_right(child_left);
		return child;
	}
	Node_Tree<T>* L_R_rotation(Node_Tree<T>* root) {
		Node_Tree<T>* child = root->get_left();
		Node_Tree<T>* grandchild = child->get_right();
		//for the end of algoritm
		Node_Tree<T>* forEndright = grandchild->get_right();
		Node_Tree<T>* forEndleft = grandchild->get_left();
		this->conect_2_nodes_(grandchild, child);
		this->conect_2_nodes_(grandchild, root);

		if (forEndleft != NULL) {
			this->conect_2_nodes_(child, forEndleft);
		}
		else {
			child->set_right(NULL);
		}
		if (forEndright != NULL) {
			this->conect_2_nodes_(root, forEndright);
		}
		else {
			root->set_left(NULL);
		}
		return grandchild;
	} 
	Node_Tree<T>* R_L_rotation(Node_Tree<T>* root) {
		Node_Tree<T>* child = root->get_right();
		Node_Tree<T>* grandchild = child->get_left();
		//for the end of algoritm
		Node_Tree<T>* forEndright = grandchild->get_right();
		Node_Tree<T>* forEndleft = grandchild->get_left();
		this->conect_2_nodes_(grandchild, child);
		this->conect_2_nodes_(grandchild, root);
		if (forEndleft != NULL) {
			this->conect_2_nodes_(root, forEndleft);
		}
		else {
			root->set_right(NULL);
		}
		if (forEndright != NULL) {
			this->conect_2_nodes_(child, forEndright);
		}
		else {
			child->set_left(NULL);
		}
		return grandchild;
	}

};
template<class T>
int Tree<T>::num_of_leafs = 0;