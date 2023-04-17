#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Book{
    private:
     int book_id;
     string title;
     float price;
    public:
     Book(){
        book_id = 0;
        title = "no_title";
        price = 0;
     }
     void setBookData(){
        cout<<"enter book id , price and title of a book :";    
        cin>>book_id;
        cin.ignore();
        getline(cin,title);  
        cin>>price;
    }
     void showBookData(){
        cout<<endl<<book_id<<" "<<title<<" "<<price;
     }
     int storeBookData();
     void viewAllBookData();
     void searchBookData(string);
     void deleteBookData(string);
     void updateBookData(string);
};
int Book::storeBookData(){
    if(book_id==0 && price ==0 ){
        cout<<endl<<"book data not initialized";
        return 0;
    }
    else{
        ofstream fout;
        fout.open("file_obj.txt",ios::app);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return 1;
    }
}
void Book::viewAllBookData(){
    ifstream fin;
    fin.open("file_obj.txt",ios::in);
        if(!fin){
            cout<<"file does not exist";
        }
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                showBookData();
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
        }    
}
void Book::searchBookData(string p){
      ifstream fin;
      int counter = 0;
      fin.open("file_obj.txt",ios::in);
      if(!fin){
        cout<<"file not found";
      }
      else{
         fin.read((char*)this, sizeof(*this));
         while(!fin.eof()){
            if(!p.compare(title)){
               cout<<"\nyes data is matched...";
               showBookData();
               counter++;
            }   
            fin.read((char*)this, sizeof(*this)); 
            
         }
         if(counter==0){
            cout<<endl<<"record not found";
         }
         fin.close();
      }
}
void Book::deleteBookData(string t){
    ifstream fin;
    ofstream fout;
    fin.open("file_obj.txt",ios::in);
    if(!fin){
        fout<<"file not found";
    }
    else{
        fout.open("temp.txt",ios::out);
        fin.read((char*)this , sizeof(*this));
        while(!fin.eof()){
            if(title.compare(t)){
                fout.write((char*)this,sizeof(*this));
            }
            fin.read((char*)this , sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("file_obj.txt");
        rename("temp.txt","file_obj.txt");
    }
}
void Book::updateBookData(string t){
    fstream file;
    int counter  = 0;
    file.open("file_obj.txt",ios::in|ios::ate|ios::out);
    file.seekg(0);
    file.read((char*)this , sizeof(*this));
    while(!file.eof()){
        if(!title.compare(t)){
            setBookData(); 
            file.seekg(file.tellp() - sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this , sizeof(*this));
    }
    file.close();
}
int menu(){
    int choice;
    cout<<endl<<"Book management ......";
    cout<<endl<<"press 1 for insert book record";
    cout<<endl<<"press 2 for view all book record";
    cout<<endl<<"press 3 for search book record";
    cout<<endl<<"press 4 for delete book record";
    cout<<endl<<"press 5 for update book record";
    cout<<endl<<"press 6 for exit";
    cout<<endl<<"enter your choice : ";
    cin>>choice;
    return choice;
}
int main(){
    Book b;
    string t;
    while(1){
      switch(menu()){
        case 1: 
          b.setBookData();
          b.storeBookData();
          cout<<"record inserted";
          break;
        case 2:
          b.viewAllBookData();
          break;
        case 3:
          cout<<endl<<"enter the book title you want to search : ";
          cin.ignore();
          getline(cin,t);
          b.searchBookData(t);
          break;
        case 4:
          cout<<endl<<"enter the title of the book which you want to delete : ";
          cin.ignore();
          getline(cin,t);
          b.deleteBookData(t);
          break;
        case 5:
          cout<<"enter book title for update the record : ";
          cin.ignore();
          getline(cin,t);
          b.updateBookData(t);
          break;
        case 6:
          cout<<"thanx for using book management system ....";
          exit(0);
        default:
          cout<<"invalid input";
      }
    }

    return 0;
}
