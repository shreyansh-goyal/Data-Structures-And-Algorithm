#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
/**
PRINT THE CIRCULAR LINKED LIST
*/
void printCircularLinkedList(Node* head){
    if(head==NULL){
        return;
    }
    else{
        Node* temp =head;
        while(temp->next!=head){
            cout<<temp->data<<endl;
            temp= temp->next;
        }
       cout<<temp->data;
    }
}
/**
INSERT THE NODE AT THE BEGINING OF THE LINKED LIST
*/
Node* insertTheNodeAtTheBeginingOfList(Node* head,int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head=newNode;
        head->next= head;
    }else{

        newNode->next = head;
        Node* temp = head;
        while(temp->next !=head){
            temp = temp->next;
        }
        temp->next=newNode;
        head=newNode;
        return head;
    }
}
/**
INSERT AT THE END OF THE LINKED LIST
*/
Node* insertAtTheendOfTheLinkedList(Node* head,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        newNode->next=newNode;
        return newNode;
    }
    else{
        Node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next= temp->next;
        temp->next=newNode;
        return head;
    }
}
/**
DELETE THE NODE FROM THE BEGINING OF THE LIST
*/
Node* deleteNodeFromBegining(Node* lastPointer){
    if(lastPointer==NULL){
        return NULL;
    }
    else{
        Node* temp = lastPointer->next;;
        lastPointer->next=lastPointer->next->next;
        delete temp;
        return lastPointer->next;
    }
}
/**
DELETE THE KTH OF THE LINKED LIST
*/
Node* deleteKthNode(Node* head,int pos){
    if(head==NULL){
        return NULL;
    }
    else{
        if(pos==0){
            if(head->next==head)return NULL;
            Node* temp1 =head;
            Node* temp2=head;
            while(temp2->next!=head){
                temp2=temp2->next;
            }
            temp2->next= head->next;
            head= temp2->next;
            delete temp1;
            return head;
        }
        else{
            Node* temp1 =head;
            Node* temp2=head;
            while(temp2->next!=head&&pos!=1){
                temp2=temp2->next;
                pos--;
            }
            temp1= temp2->next;
            temp2->next= temp1->next;
            delete temp1;
            return head;
        }
    }
}
int main()
{
    Node* head = new Node(10);
    Node* temp1= new Node(20);
    Node* temp2= new Node(30);
    head->next=temp1;
    temp1->next= temp2;
    temp2->next= head;
    head=insertTheNodeAtTheBeginingOfList(head,0);
    head=insertTheNodeAtTheBeginingOfList(head,100);
    head= insertAtTheendOfTheLinkedList(head,40);
    cout<<endl<<"without deleting the element"<<endl;
    printCircularLinkedList(head);
    cout<<endl<<"delete 0"<<endl;
    head=deleteKthNode(head,0);
    printCircularLinkedList(head);
    cout<<endl<<"delete 1"<<endl;
    head=deleteKthNode(head,1);
    printCircularLinkedList(head);
    cout<<endl<<"delete 2"<<endl;
    head=deleteKthNode(head,2);
    printCircularLinkedList(head);
    head=deleteKthNode(head,0);
    head=deleteKthNode(head,0);
        head=deleteKthNode(head,0);
    //head = deleteNodeFromBegining(temp2);

    printCircularLinkedList(head);
    return 0;
}
