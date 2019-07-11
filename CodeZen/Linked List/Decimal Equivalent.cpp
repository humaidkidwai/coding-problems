/*************
 Following is the Node<int> structure already written.

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
        next = NULL;
        this->data = data;
	}

	~Node() {
        if (next != NULL) {
            delete next;
        }
	}
 };

*************/
#include<bits/stdc++.h>
using namespace std;
int decimal(Node<int> *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(!head)
        return 0;
    int len = -1,res= 0;
    Node<int> *p = head;
    while(p){
        len++;
        p=p->next;
    }
    p = head;
    for(int i = len; i>= 0;i--){
        res += p->data * pow(2,i);
        p = p->next;
    }
    return res;
}
