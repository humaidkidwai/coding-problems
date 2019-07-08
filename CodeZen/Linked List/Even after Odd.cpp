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
#include<iostream>
using namespace std;
node* arrange_LinkedList(node* head)
{
    //write your code here
    node *odds=nullptr,*evens=nullptr,*p=head;
    node* p1 = odds,*p2 = evens;
    while(p){
        node *tmp = new node(p->data);
        if((p->data)%2==1){
            if(!p1){
                p1 = tmp;
                odds = p1;
            }
            else{
                p1->next = tmp;
                p1=p1->next;
            }
        }
        else{
            if(!p2){
                p2 = tmp;
                evens = p2;
            }
            else{
                p2->next = tmp;
                p2=p2->next;
            }
        }
        p=p->next;
    }
    p2 = evens;
    if(odds){
        p1->next = evens;
        p1 = odds;
        return p1;
    }
    return p2;
}
