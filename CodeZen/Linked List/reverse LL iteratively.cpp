// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here
    node* cur = head,*prev = nullptr;
    while(cur){
        node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

