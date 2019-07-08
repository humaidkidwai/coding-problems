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
void deleteNextN(node* &p, int N){
    int count = 0;
    node* Nrunner = p;
    while(count <= N && Nrunner){
        count++;
        Nrunner = Nrunner ->next;
    }
    p->next = Nrunner;
}
node* skipMdeleteN(node  *head, int M, int N) {
    // Write your code here
    node *p = head;
    int count = 0;
    while(p){
        count++;
        if(count % M == 0)
            deleteNextN(p,N);
        p = p -> next;
    }
    return head;
}
