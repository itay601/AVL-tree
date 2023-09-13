#pragma once
#include <iostream>
#include <queue>

using namespace std;

template <class T>
class Node_Tree
{
private:
	T _key;
	Node_Tree<T>* _parent;
	Node_Tree<T>* _left;
	Node_Tree<T>* _right;
	int hight;
public:
	//defult and constructor//
	Node_Tree(const T key=0) :_key(0), _parent(NULL), _left(NULL), _right(NULL) {
		this->_key = key;
		this->hight = 0;
	}
	//copy constructor//
	Node_Tree(const Node_Tree<T>& node) {
		this->_key = node._key;
		this->_parent = NULL;
		this->_left = NULL;
		this->_right = NULL;
		this->hight = node.hight;
	}
	Node_Tree(const Node_Tree<T>* node) {
		this->_key = node->_key;
		this->_parent = NULL;
		this->_left = NULL;
		this->_right = NULL;
		this->hight = node->hight;
	}
	void set_node( Node_Tree<T>* node) {
		this->set_key(node->get_key());
		this->set_left(node->get_left());
		this->set_right(node->get_right());
		this->set_parent(node->get_parent());
		this->set_hight_node(node->get_hight_node());
	}
	
	void set_hight_node(int h) { this->hight = h; }
	void set_key(const T key) { this->_key = key; }
	void set_parent(Node_Tree<T>* parent) { this->_parent = parent; }
	void set_left(Node_Tree<T>* left) { this->_left = left; }
	void set_right(Node_Tree<T>* right) { this->_right = right; }
	int get_hight_node() {  return this->hight;  }
	
	T get_key() { return this->_key; }
	Node_Tree<T>* get_parent() { return this->_parent; }
	Node_Tree<T>* get_left() { return this->_left; }
	Node_Tree<T>* get_right() { return this->_right; }

	friend ostream& operator<<(ostream& out,  Node_Tree<T>& node) {
		out << "<< key: " << node.get_key()<<" hight: "<< node.get_hight_node();
		return out;
	}
	Node_Tree<T>& operator=(Node_Tree<T>* z) {
		this->set_key(z->get_key()) ;
		this->set_left(z->get_left());
		this->set_right(z->get_right());
		this->set_parent(z->get_parent());
		return this;
	 }
	~Node_Tree() {

		delete _left;
		delete _right;
		cout << "deleted"<<endl;
	}
};

