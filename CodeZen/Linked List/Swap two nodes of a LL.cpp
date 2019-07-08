//head is head of your linked list, i and j are indexes to be swapped
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
node* swap_nodes(node *head,int i,int j)
{
    //write your code here
    node *iNode=nullptr,*iNodePrev=nullptr,*jNode=nullptr,*jNodePrev=nullptr;
    node *p = head, *prev = nullptr;
    for(int k = 0; k <= max(j,i); k++){
        if(iNode && jNode)
            break;
        if(k == i){
            iNode = p;
            iNodePrev = prev;
        }
        if(k == j){
            jNode = p;
            jNodePrev = prev;
        }
        prev = p;
        p = p -> next;
    }
    if(i < j){

        if(iNodePrev)
            iNodePrev -> next = jNode;
        else
            head = jNode;

        jNodePrev -> next = iNode;
        node *tmp = jNode->next;
        jNode -> next = iNode -> next;
        iNode -> next = tmp;
    }
    else{
        if(jNodePrev)
            jNodePrev -> next = iNode;
        else
            head = iNode;
        iNodePrev -> next = jNode;
        node *tmp = iNode->next;
        iNode -> next = jNode -> next;
        jNode -> next = tmp;

    }
    return head;
}
