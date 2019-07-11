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
node* helper(node* head, node* prev){
    if(!head)
        return prev;

    node* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
    return helper(head,prev);
}
node *reverse_linked_list_rec(node *head)
{
    //write your recursive code here
    return helper(head,nullptr);
}

