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

Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    Node* p1 = head1, *p2 = head2,*resHead=nullptr,*resTail=nullptr;
    while(p1 && p2){
        if(p1->data<p2->data){
            if(!resHead){
                resHead = p1;
                resTail = resHead;
                p1 = p1->next;
            }
            else{
                resTail -> next = p1;
                resTail = resTail->next;
                p1=p1->next;
            }
        }
        else {
            if(!resHead){
                resHead = p2;
                resTail = resHead;
                p2 = p2->next;
            }
            else{
                resTail -> next = p2;
                resTail = resTail->next;
                p2=p2->next;
            }
        }
    }
    while(p1){
        resTail->next = p1;
        resTail = resTail->next;
        p1 = p1->next;
    }
    while(p2){
        resTail->next = p2;
        resTail = resTail->next;
        p2 = p2->next;
    }
    return resHead;
}


