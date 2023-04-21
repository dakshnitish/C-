#include<iostream>
using namespace std;
class Queue{
    private: 
     struct node{
        int item;
        node *next;
     };
     node *front;
     node *rear;
    public:
     Queue(){
        front = NULL;
        rear = NULL;
     }
     ~Queue(){
        while(isempty() !=1){
            remove();
        }
     }

     int countitems(){
        int counter = 1;
        if(front == NULL){
            return 0;
        }
        else{
            node *t;
            t = front;
            while(t != rear){
                t = t->next;
                counter++;
            }
            return counter;
        }
     }
     
     int isempty(){
        if(front == NULL){
            return 1;
        }
        return 0;
     }

     int getfirst(){
        if(front==NULL){
            return -1;
        }
        else{
            return front->item;
        }
     }

     int remove(){
        if(front==NULL){
            return 0;
        }
        if(front==rear){
            delete front;
            front = rear = NULL;
            return 1; 
        }
        else{
            node *r;
            r = front;
            front = front->next;
            delete r;
            return 1;
        }
     }

     void insert(int value){
        node *n = new node;
        n->item = value;
        n->next = NULL;
        if(front==NULL){
            front =rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
     }

     void displayQueue(){
        if(front == NULL){
            cout<<"\nlist is empty";
        }
        else{
            node *t;
            t = front;
            while(t !=NULL){
                cout<<" "<<t->item;
                t = t->next;
            }
        }
     }
};

int main(){
    Queue list;
    list.insert(10);
    // list.insert(20);
    // list.insert(12);
    // list.insert(8);
    // list.insert(22);
    // list.displayQueue();
    // cout<<"\n";
    // cout<<list.remove();
    // cout<<"\n";
    // list.displayQueue();
    // list.insert(28);
    // cout<<"\n";
    // list.displayQueue();
    // cout<<"\n";
    cout<<list.countitems();
    return 0;
}

