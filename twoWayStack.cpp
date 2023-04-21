#include<iostream>
using namespace std;
class TwoWayStack{
    private:
      int capacity;
      int top_left = -1;
      int top_right = capacity;
      int *ptr;
    public:
      TwoWayStack(int cap){
         this->capacity = cap;
         this->top_left = -1;
         this->top_right = capacity;
         this->ptr = new int[capacity];
      } 
      ~TwoWayStack(){
        delete []ptr;
      }
      void pushleft(int);
      void pushright(int);
      int popleft();
      int popright();
      int peekleft();
      int peekright();
      int isemptyleft();
      int isemptyright();
      int isfull();
};

void TwoWayStack::pushright(int value){
      if(isfull()==1){
        cout<<"\n stack overflow";
      }
      else{
        top_right --;
        ptr[top_right] = value;
      }
}

void TwoWayStack::pushleft(int value){
      if(isfull()==1){
        cout<<"\n stack overflow";
      }
      else{
        top_left ++;
        ptr[top_left] = value;
      }
}

int TwoWayStack::peekright(){
    if(isemptyright()==1){
        cout<<"\nit is empty";
        return -1;
    }
    else{
        return ptr[top_right];
    }
}

int TwoWayStack::peekleft(){
    if(isemptyleft()==1){
        cout<<"\nit is empty";
        return -1;
    }
    else{
        return ptr[top_left];
    }
}

int TwoWayStack::popright(){
    int val;
    if(isemptyright()==1){
        cout<<"\nit is empty";
        return -1;
    }
    else{
        val = ptr[top_right];
        top_right++;
        return val;
    }
}

int TwoWayStack::popleft(){
    int val;
    if(isemptyleft()==1){
        cout<<"\nit is empty";
        return -1;
    }
    else{
        val = ptr[top_left];
        top_left--;
        return val;
    }
}


int TwoWayStack::isfull(){
    if(top_left + 1 == top_right){
        return 1;
    }
    else{
        return 0;
    }
}

int TwoWayStack::isemptyright(){
    if(top_right == capacity){
        return 1;
    }
    else{
        return 0;
    }
}

int TwoWayStack::isemptyleft(){
    if(top_left == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    TwoWayStack s(11);
    s.pushright(50);
    s.pushleft(10);
    s.pushleft(20);
    s.pushleft(30);
    s.pushright(21);
    cout<<"\npeek from stack 1 "<<s.peekleft();
    cout<<"\npeek from stack 2 "<<s.peekright();
    return 0;
}