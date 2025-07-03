#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
    data=data1;
    next=next1;
    }
    Node(int data1){
    data=data1;
    next=nullptr;
    }
};
Node* convert2LL(int arr[],int n){
    Node*head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover=temp;
    }
    return head;
}
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data;
    temp=temp->next;
    cout<<"->";
    }
    cout<<"NULL";
}

int findlengthofloop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
                int length=1;
                fast=slow->next;
                while(fast!=slow){
                    length++;
                    fast=fast->next;
                }
                return length; 
        }
        
        
    }
    
    
}


int main(){
    Node* head= new Node(1);
    Node* two= new Node(2);
    Node* three= new Node(3);
    Node* four= new Node(4);
    Node* five= new Node(5);
    Node* six= new Node(6);
    Node* seven= new Node(7);
    Node* eight= new Node(8);

    head->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=six;
    six->next=seven;
    seven->next=eight;
    eight->next=three;

    int length=findlengthofloop(head);
    cout<<"length of loop is : "<<length;
    return 0;
}