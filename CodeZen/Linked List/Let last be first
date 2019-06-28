/*************
 Following is the Node structure already written.

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
 next = NULL;
 this->data = data;
	}
 
	~Node() {
 if (next != NULL) {
 delete next;
 }
	}
 };
 
*************/


Node<int>* moveToFront(Node<int> *head_ref) {
	// Write your code here
    if(!head_ref || head_ref->next==nullptr)
        return head_ref;
    Node<int>* tmp = head_ref;
    Node<int>* p = head_ref;
    while(p->next->next!=NULL)
        p = p->next;
    head_ref = p->next;
    p->next = nullptr;
    head_ref->next = tmp;
    return head_ref;
}
