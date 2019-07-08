#include<bits/stdc++.h>
using namespace std;
/*class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};
*/
ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
{
    //WRITE YOUR CODE HERE
    if(!head1)
        return head2;
    ListNode<int> *newhead = NULL;
    ListNode<int> *temp = NULL;
    //temp = newhead = head1;
    map<int ,int> freq1;
    map<int , int> freq2;
    while(head1 != NULL)
    {

        freq1[head1->data]++;
        ListNode<int> *newNode = new ListNode<int>(head1->data);
        if(newhead == NULL)
        {
            newhead = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }

        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        freq2[head2->data]++;
        if(freq2[head2->data] > freq1[head2->data]){
            ListNode<int> *newNode = new ListNode<int>(head2->data);
            temp->next = newNode;
            temp = newNode;
        }
        head2 = head2->next;
    }
    return newhead;
}