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
node* findMidOfLL(node *head)
{
    node* fast=head, *slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node *head1, node *head2) {
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    node* p1 = head1, *p2 = head2,*resHead=nullptr,*resTail=nullptr;
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
node* mergeSort(node *head) {
    //write your code here
    if(!head || !(head->next))
        return head;
    node* mid = findMidOfLL(head);
    node* secondHalf = mid->next;
    mid -> next = nullptr;

    head = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

    return merge(head,secondHalf);
}
