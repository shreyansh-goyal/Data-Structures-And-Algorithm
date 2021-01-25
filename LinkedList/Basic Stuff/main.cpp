#include <bits/stdc++.h>
using namespace std;

/**
Definition of the node in the linked list
*/
struct Node{
    int data;
    Node* next;
    Node(int x){
    data = x;
    next=NULL;
    }
};
/**
Helps to print all the nodes in the linked list
*/
void printList(Node* head){
    if(head==NULL)return;
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
/**
Helps to the print the list recursively
*/
void printListRecursive(Node* head){
    if(head==NULL){
        cout<<endl;
        return;
    }
    else{
        cout<<head->data<<" ";
        printListRecursive(head->next);
    }
}

/**
Helps to insert the node at the begining of the list
*/
Node* insertAtBegining(int data,Node* head){
    Node* newNode = new Node(data);
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    return head;
}

/**
Helps to insert at the end of the singly linked list
*/

Node* insertAtEnding(Node* head,int data){
    Node* newNode= new Node(data);
    if(head==NULL){
        head=newNode;
        return head;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL)temp=temp->next;
        temp->next=newNode;
        newNode->next=NULL;
        return head;
    }
}
/**
Helps to delete first Node of the linked list
*/

Node* deleteFirstNode(Node* head){
    if(head==NULL){
        return head;
    }
    else{
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
}
/**
Delete lat node from the singly linked list
*/

Node* deleteLastNode(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node* temp1=head;
    while(head->next!=NULL){
        if(head->next->next==NULL){
            Node* temp=head->next;
            head->next=NULL;
            delete temp;
            break;
        }
        head=head->next;
    }
    return temp1;
}

/**
Insert at specific position in the linked list
*/
Node* insertAtSpecificPosition(Node* head,int data,int pos){
    Node* newNode= new Node(data);
    int curr_pos=0;
    Node* temp=head;
    if(head==NULL){
        return NULL;
    }
    if(pos==0){
        newNode->next=head;
        head=newNode;
    }
    while(pos-1!=curr_pos){
        if(temp==NULL)return head;
        temp=temp->next;
        curr_pos++;
    }
    newNode->next=temp->next;
    temp->next= newNode;
    return head;
}

/**
Search in LinkedList iteratively
*/
int searchInList(Node* head,int data){
    Node* temp=head;
    int pos=0;
    if(head==NULL){
        return NULL;
    }
    while(temp!=NULL){
        if(temp->data==data){
            return pos;
        }
        temp=temp->next;
        pos++;
    }
}
int recursiveSearchInList(Node* head,int data,int pos){
    if(head==NULL)return -1;
    else{
        if(head->data==data) return pos;
        else return recursiveSearchInList(head->next,data,pos+1);
    }
}
int main()
{
    Node* head= new Node(10);
    head->next=new Node(20);
    head->next->next= new Node(30);
    head=insertAtBegining(0,head);
    head=insertAtEnding(head,40);
    head=deleteFirstNode(head);
    head=insertAtSpecificPosition(head,35,0);
    deleteLastNode(head);
    printList(head);
    printListRecursive(head);
    cout<<searchInList(head,20)<<endl;
    cout<<recursiveSearchInList(head,51,0);
    return 0;
}
