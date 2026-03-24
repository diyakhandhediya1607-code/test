#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class dynamicMemory{
    public:
    Node*head;
    dynamicMemory(){
        head=NULL;
    }

       void display(){
        if(head==NULL){
            cout<<" List is empty";
            return;
        }
          Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<< " NULL ";
    };
    void insert_at_beginning(int val){
        Node* newNode = new Node(val);
        newNode->next=head;
        head=newNode;
    }


    void search(int val){
        Node*searchele=new Node(val);
        int position=1;
        Node*temp= head;
        while(temp!=NULL){
            if(temp->data==val){
                cout<<"Element found at position:"<<position<<endl;
                return;
            }
            temp=temp->next;
            position++;
        }
        cout<<"Element not found"<<endl;
    }

    void delete_node(int val){
        Node*temp=head;
        Node*pre=NULL;

        while(temp!=NULL){
            if(temp->data==val){
                if(pre==NULL){
                    head=temp->next;
                }
                else{
                    pre->next=temp->next;
                }
                cout<<"Node deleted\n";
                return;
            }
            pre=temp;
            temp=temp->next;
        }
        cout<<"value Not founf\n";
        }


        void reverse(){
        if(head==NULL || head->next == NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* pre = NULL;
        Node* cur = head;
        Node* next = NULL;

        while(cur != NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        head=pre;

    }
    };



int main(){
    dynamicMemory d;
    d.insert_at_beginning(10);
    d.insert_at_beginning(20);
    d.insert_at_beginning(30);
    d.insert_at_beginning(40);
    
    d.search(30);
    d.delete_node(20);
    d.reverse();
    d.display();
}