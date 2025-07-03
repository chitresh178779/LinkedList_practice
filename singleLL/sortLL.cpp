#include<iostream>
#include<vector>
#include<algorithm>
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
Node* convert2LLarr(int arr[],int n){
    Node*head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover=temp;
    }
    return head;
}
Node* convert2LLvec(vector<int> v,int size){
    Node*head=new Node(v[0]);
    Node* mover=head;
    for(int i=1;i<size;i++){
    Node* temp=new Node(v[i]);
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
cout<<"NULL"<<endl;
}
Node* sortLL(Node* head){
    vector<int> v;
    Node* temp=head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    Node* newhead=convert2LLvec(v,v.size());
    return newhead;
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
    Node* head=convert2LLarr(arr,size);
    cout<<"----------before sorting:-------------------"<<endl;;
    printLL(head);
    cout<<"----------after sorting:-------------------"<<endl;
    Node* head2=sortLL(head);
    printLL(head2);

    return 0;
}