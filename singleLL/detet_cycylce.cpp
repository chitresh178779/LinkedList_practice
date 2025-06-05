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
cout<<endl;
}
}

void createloop(Node* head,int data1){
    Node*temp=head;
    Node* mover=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    while(mover->data!=data1 && mover!=NULL){
        mover=mover->next;
    }
    temp->next=mover;
}

bool detect_cycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

int  startofcycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return slow->next->data;
    }
    return -1;
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size;i++){
        cout<<"enter the element "<<i<<": ";
        cin>>arr[i];
    }
    Node* head= convert2LL(arr,size);
    int data;
    cout<<"value where loop will be created: ";
    cin>>data;
    createloop(head,data);
    // Node* head = new Node(1);
    // Node* second = new Node(2);
    // Node* third = new Node(3);
    // Node* fourth = new Node(4);
    // Node* fifth = new Node(5);

    // head->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    //  // Create a loop
    // fifth->next = third;
    bool isloop=detect_cycle(head);
    if(isloop){
        int v=startofcycle(head);
        cout<<"yes loop is present at "<<v;
    }
    else cout<<"loop not present";
    return 0;
}