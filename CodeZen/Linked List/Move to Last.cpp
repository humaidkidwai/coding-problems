/*************
 Following is the Node<int> structure already written.

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

Node<int>* func(Node<int> *head,int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int count = 0;
    Node<int>* p = head,*prev = nullptr;
    while(p && p->next && p->data == n){
        head = p->next;
        count++;
        p = p->next;
    }
    while(p->next){
        if(p->data == n){
            count++;
            prev->next = p->next;
            p = p->next;
        }
        else{
            prev = p;
            p = p->next;
        }
    }
    while(count--){
        p->next = new Node<int>(n);
        p = p->next;
    }
    if(p)
        p->next = nullptr;
    return head;
}
