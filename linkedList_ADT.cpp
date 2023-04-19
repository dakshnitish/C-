#include<iostream>
using namespace std;
class linkedListADT{
    private:
     struct node{
        int item;
        node *next;
     }
     node *start;
     node *Search(int data){
         node *t;
         if(start == NULL){
            return NULL;
         }
         t = start;
         while(t!==NULL){
            if(t->item == data){
                return t;
            }
            t = t->next;
         }
         return NULL;
     }
    public: 
      linkedListADT(){
        NULL;
      } 
      ~linkedListADT(){
        while(start!=NULL){

        }
      }
    int countItems();
    void insertAtStart(int);  
    void insertAtLast(int); 
    void insertAfter(int , int);
};

void linkedListADT::insertAtStart(int data){
    node *n = new node;
    n->next = start;
    n->item = data;
    start = n; 
}

void linkedListADT::insertAtLast(int data){
    node *t;
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if(start == NULL){
        start = n;
    }
    else{
       t = start;
       while(t->next!=NULL){
         t = t->next;
       }
       t->next = n;
    }
}

void linkedListADT::insertAfter(int currentData, int data){
    node *t = Search(currentData);
    if(t==NULL){
        cout<<"\nno such value exists";
    }
    else{
        node *n = new node;
        n->item = data;
        n->next  = t->next;
        t->next = n;
    }
} 

int linkedListADT::countItems(){
    int counter = 0;
    int *t;
    t = start;
    if(t->next==NULL){
        cout<<"no items available";
        return 0;
    }
    while(t->next != NULL){
        counter++;
        t=t->next;
    }
    return counter;
}



