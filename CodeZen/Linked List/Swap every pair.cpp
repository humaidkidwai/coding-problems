// Following is the node structure
/**************
class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
***************/
Node* reverse(Node* head,Node* prev)
{
    //write your iterative code here
    Node* cur = head;
    while(cur){
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
Node* helper(Node* head,Node* prev){
    if(!head || head->next == nullptr)
        return head;

    Node* tail = head;
    Node* tmp = tail->next->next;
    tail->next->next = nullptr;
    head = reverse(head,prev);
    prev = tail;
    tail->next = helper(tmp,prev);

    return head;
}
Node* swapEveryPair(Node *head) {
    //write your code here
    return helper(head,nullptr);
}
