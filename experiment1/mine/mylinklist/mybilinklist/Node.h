#include<iostream>
using namespace std;
class Node{
	public:
		int element;
		Node* prev;
		Node* next;
		Node(){
			element=0;
			prev=NULL;
			next=NULL;
		}
		Node(const int &it,Node *pprev,Node *pnext){
			element=it;
			prev=pprev;
			next=pnext;
		}
		Node(Node *pprev,Node *pnext){
			prev=pprev;
			next=pnext;
		}
		~Node(){}
		Node* getPrev();
		Node* getNext();
		int getvalue();
}; 
//���prevָ�� 
Node* Node::getPrev() {
	return prev;
}
//���nextָ�� 
Node*Node::getNext() {
	return next;
}
//���Ԫ��ֵ 
int Node::getvalue() {
	return element;
}
