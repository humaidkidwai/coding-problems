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


void AlternatingSplit(Node<int>* head) {
    // Write your code here
    Node<int>* a = NULL,*b = NULL,*p = head;
    bool f = 0;
    while(p){
        if(f==0){
            if(!a)
                a = p;
            else{
                Node<int>* tmp = a;
                a = p;
                a->next = tmp;
            }
        }
        else{
            if(!b)
                b = p;
            else{
                Node<int>* tmp = b;
                b = p;
                b->next = tmp;
            }
        }
        f = 1-f;
        p=p->next;
    }
    while(a){
        cout<<a->data<<" ";
        a = a->next;
    }
}
