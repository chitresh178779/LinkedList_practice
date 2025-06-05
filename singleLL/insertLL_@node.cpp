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
Node* insertB(Node* head,int data,int atnode){
    Node* temp=head;
    Node* n=new Node(data);
    if(atnode==1){
        n->next=head;
        return n;
    }
    int i=1;
    while(temp!=nullptr && i<(atnode-1)){
        temp=temp->next;
        i++;
    }
    if(temp==nullptr){
        cout<<"Insertion is Out Of Bounds!!!!"<<endl;
        delete n;
        return head;
    }
    n->next=temp->next;
    temp->next=n;
    return head;
}

int main(){
    int size;
    cout<<"enter the size of array :";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"enter the element "<<i<<" :";
        cin>>arr[i];
    }
    Node* head=convert2LL(arr,size);
    int data,atnode;
    cout<<"enter the data to insert: ";
    cin>>data;
    cout<<"enter the position of the node: ";
    cin>>atnode;
    Node* head2=insertB(head,data,atnode);
    printLL(head2);
    return 0;
}