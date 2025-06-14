#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *child;
    Node()
    {
        data=0;
        next=NULL;
        child=NULL;
    }
    Node(int data1)
    {
        data=data1;
        next=NULL;
        child=NULL;
    }
    Node(int data1, Node *next1, Node* next2)
    {
        data = data1;
        next = next1;
        child = next1;
    }
};

Node* convert2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* N2=new Node(arr[i]);
        mover->child=N2;
        mover=N2;
    }
    return head;
}

void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data;
    temp=temp->child;
    cout<<"->";
}
    cout<<"NULL"<<endl;
}

vector<int>flattenLinkedList(Node* head) {
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL){
        Node* t2=temp;
        while(t2!=NULL){
            arr.push_back(t2->data);
            t2=t2->child;
        }
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    return arr;
}


int main(){
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    

    vector<int>flattened = flattenLinkedList(head);
    Node*head2=convert2LL(flattened);
    cout << "\nFlattened linked list: ";
    printLL(head2);
    return 0;
}
