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
Node* deleteB(Node* head,int atnode){
    Node* temp=head;
    if(atnode==1){
         head=temp->next;
         delete temp;
         return head;
    }
    int i=1;
    Node* prev=NULL;
    while(temp!=NULL && i<atnode){
        prev=temp;
        temp=temp->next;
        i++;
    }

    if(temp==nullptr){
        cout<<"Deletion is Out Of Bounds"<<endl;
        return head;
    }
    prev->next=temp->next;
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
    int atnode;
    cout<<"enter the node to delete: ";
    cin>>atnode;
    Node* head2=deleteB(head,atnode);
    printLL(head2);
    return 0;
}