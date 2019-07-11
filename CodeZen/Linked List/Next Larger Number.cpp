/**********
 * Following is the Node class that is already written.

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

*********/
void reverse(Node* &head){
    Node* prev = nullptr;
    while(head){
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(!head)
        return head;
    reverse(head);
    Node* p = head;
    int carry = 1;
    while(p->next && carry){
        p->data = p->data + carry;
        carry = (p->data) / 10;
        p->data = p->data % 10;

        p = p->next;
    }
    p->data = p->data + carry;
    carry = (p->data) / 10;
    p->data = p->data % 10;

    if(carry){
        p->next = new Node(carry);
        p = p->next;
    }
    reverse(head);
    return head;
}


