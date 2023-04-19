#include<iostream>
using namespace std;
class arrayADT{
    private:
     int capacity;
     int lastIndex;
     int *ptr;
    public:
     arrayADT(){
        capacity = 0;
        lastIndex = -1;
        ptr = NULL;
     } 
     void createArray(int);
     void setItem(int , int);
     int getItem(int);
     void editItem(int , int);
     int countItem();
     void removeItem(int);
     int searchItem(int);
     void sortArray();
     friend ostream& operator<<(ostream& , arrayADT);
     ~arrayADT(){
        delete []ptr;
     }
    arrayADT(arrayADT &b){
      capacity = b.capacity;
      lastIndex = b.lastIndex;
      ptr  = new int[capacity];
      for(int i  = 0;i<=b.lastIndex;i++){
        ptr[i]=b.ptr[i];
      }
    }
};

void arrayADT::setItem(int index,int value){
    int i;
    if(lastIndex==capacity-1){
      cout<<"\noverflow"<< " it is in 1st if";
    }
    else if(index>(capacity-1) || index<0){
      cout<<"\ninvalid index"<<" it is in 2nd if";
    }
    else if(index>lastIndex+1){
      cout<<"\ninvalid index"<<" it is in 3rd if"; 
    }
    else if(index<=lastIndex+1){
      lastIndex++;
      i = lastIndex;
      while(i!=index){
        ptr[i]=ptr[i-1];
        i--;
      }
      ptr[index]=value;
    }
    else if(index = lastIndex+1){
      cout<<"\nyou are in 5th";
      lastIndex++;
      ptr[index]=value;
    }
}

int arrayADT::getItem(int index){
       if(lastIndex == -1){
         cout<<"\nlist is empty";
         return -1;
       }
       if(index>lastIndex || index<0){
         cout<<"\ninvalid index";
         return -1;
       }
       return ptr[index];
}
void arrayADT::createArray(int c){
       capacity = c;  //we can also use this->capacity if we will pass the argument in this function with the same name
       lastIndex = -1;            
       ptr = new int[capacity];
       cout<<"\nyes create array function is executed";         
}

void arrayADT::sortArray(){
  int r,temp, i;
  for(r = 1;r<countItem();r++){
    for(i =0;i<countItem()-r;i++){
      if(ptr[i]>ptr[i+1]){
        temp = (ptr[i]);
        (ptr[i]) = (ptr[i+1]);
        (ptr[i+1]) = temp;
      }
    }
  }
}

int arrayADT::searchItem(int value){
  if(lastIndex==-1){
    cout<<"\nlist is empty";
    return -1;
  }
  int i;
  for(i = 0;i<lastIndex;i++){
    if(ptr[i]==value){
      return (i);
    }
  }
  return (-1);
}

void arrayADT::removeItem(int index){
  int i;
     if(index<0 || index>lastIndex){
      cout<<"\neither invalid index or underflow";
     }
     else if(index<lastIndex){
       i = index;
       while(i!=lastIndex){
          ptr[i] = ptr[i+1];
          i++;
       }
      lastIndex--;
     }
     else if(lastIndex==index){
      lastIndex--;
     }
}

int arrayADT::countItem(){
  return (lastIndex+1) ;
}

ostream& operator<<(ostream &dout , arrayADT a){
  if(a.lastIndex  == -1){
    cout<<"\nlist is empty";
  }
  cout<<"\n";
  for(int i = 0 ;i < a.countItem() ;i++){
    cout<<" "<<a.getItem(i);
  }
  cout<<"\n";
  return dout;
}

void arrayADT::editItem(int index,int value){
  if(index<0 || index>lastIndex){
    cout<<"\ninvalid index";
  }
  else{
    ptr[index]=value;
  }
}

int main(){
    arrayADT l1;
    l1.createArray(5);
    l1.setItem(0,10);
    l1.setItem(1,30);
    l1.setItem(2,20);
    l1.setItem(3,15);
    l1.setItem(4,22);
    l1.sortArray();
    cout<<l1;
    cout<<"total number of elements are : "<<l1.countItem();
    l1.~arrayADT();
    return 0;
}