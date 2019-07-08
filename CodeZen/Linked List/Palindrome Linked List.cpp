//head is the head of you linked list
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
node* reverseLL(node *head){
    node *prev = nullptr;
    node *curr = head;
    node *next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
bool isPalindrome(node *head, node* mid){
    while(mid){
        if(head->data != mid -> data)
            return false;
        head = head->next;
        mid = mid->next;
    }
    return true;
}
bool check_palindrome(node* head)
{
    //write your code here
    if(!head || head->next==nullptr)
        return head;
    
    node *slow = head, *fast = head -> next;
    while(1){
        if(!fast || fast -> next == nullptr)
            break;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    slow->next = reverseLL(slow->next);
    return isPalindrome(head,slow->next);
}
