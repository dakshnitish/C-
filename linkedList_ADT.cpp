#include<iostream>
using namespace std;
class linkedListADT{
    private:
     struct node{
        int item;
        node *next;
     };
     node *start;
     node *search(int data){
         node *t;
         if(start == NULL){
            return NULL;
         }
         t = start;
         while(t!=NULL){
            if(t->item == data){
                return t;
            }
            t = t->next;
         }
         return NULL;
     }
    public: 
      linkedListADT(){
        start = NULL;
      } 
      ~linkedListADT(){
        while(start!=NULL){
            node *p = start;
            start=start->next ;
            delete p;  
        }
      }
    int countItems();
    void insertAtStart(int);  
    void insertAtLast(int); 
    void insertAfter(int , int);
    int deleteItemFromStart();
    int deleteItemFromLast();
    int deleteCurrentItem(int);
    void sortList();
    void editItem(int ,int);
    int getFirstItem();
    int getLastItem();
    void viewList();
    int SearchItem(int);
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
    node *t = search(currentData);
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
    node *t;
    t = start;
    while(t != NULL){
        counter++;
        t=t->next;
    }
    return counter;
}

int linkedListADT::deleteItemFromStart(){
    if(start==NULL){
        cout<<"\nunderflow";
        return 0;
    }
    node *t;
    t = start;
    start = start->next;
    delete t;
    return 1;
    
}

int linkedListADT::deleteItemFromLast(){
    if(start==NULL){
        cout<<"\nunderflow";
        return 0;
    }
    if(start->next == NULL){
        delete start;
        start = NULL;
        return 1;
    }
    else{
        node *t1;
        node *t2;
        t1 = t2 = start;
        while(t1->next != NULL){
            t2 = t1;
            t1=t1->next;
        }
        t2->next = NULL;
        delete t1;
        return 1;
    }
}
int linkedListADT::deleteCurrentItem(int currentItem){
     node *t = search(currentItem);
     if(t == NULL){
        cout<<"\nitem not found";
        return 0;
     }
     while((t->next) != NULL){
        t->item = t->next->item;
        t = t->next;
     }
     deleteItemFromLast();
     return 1;
}

void linkedListADT::editItem(int currentData , int newData){
    node *t = search(currentData);
    if(t == NULL){
        cout<<"\n item not found";
    }
    else{
        t->item = newData;
    }
}

int linkedListADT::getFirstItem(){
    if(start==NULL){
        cout<<"\nlist is empty";
        return -1;
    }
    return start->item;
}

int linkedListADT::getLastItem(){
    node *t;
    if(start == NULL){
        cout<<"\nlist is empty ";
        return -1;
    }
    t = start;
    while((t->next) != NULL){
        t = t->next;
    }
    return t->item;
}

void linkedListADT::viewList(){
    node *t;
    t = start;
    if(start==NULL){
        cout<<"\nlist is empty";
    }
    else{
      while(t->next != NULL){
        cout<<t->item<<" ";
        t = t->next;
      }
    }

}

int linkedListADT::SearchItem(int data){
    node *t;
    t = start;
    while(t != NULL){
        if(t->item == data){
             return 1;
        }
        t = t->next;
    }
    return 0;
}

void linkedListADT::sortList(){
    int n = countItems();
    node *t ;
    for(int r = 1;r<=n-1;r++){
        t = start;
        for(int i = 0;i<=n-1-r;i++){
           if(t->item>t->next->item){
             int temp;
             temp  = t->item;
             t->item = t->next->item;
             t->next->item = temp;
           }
           t = t->next;
        }
    }
}

int main(){
    linkedListADT l1;
    l1.insertAtStart(10);
    l1.insertAfter(10,34);
    l1.insertAfter(34,23);
    l1.insertAfter(23,11);
    l1.insertAfter(11,56);
    l1.insertAfter(56,22);
    l1.insertAtLast(24);
    cout<<l1.countItems();
    cout<<endl;
    cout<<l1.deleteCurrentItem(11);
    cout<<endl;
    cout<<l1.countItems();
    cout<<endl;
    l1.editItem(10,65);
    cout<<l1.getFirstItem();
    cout<<endl;
    cout<<l1.getLastItem();
    return 0;
}