#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    int a ,i=0;
    string text ,old,password1,password2,pass,name,password0,age,user,word,word1;
    string cred[2] ,cp[2];
    cout<<"     security system"<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"|       1. Register         |"<<endl;
    cout<<"|       2. Login            |"<<endl;
    cout<<"|       3. Change password  |"<<endl;
    cout<<"|_______4. End program______|"<<endl;
    do{
      cout<<endl<<endl;
      cout<<"enter your choice : ";
      cin>>a;
      switch(a){
        case 1:{
          cout<<"|------Register------|"<<endl<<endl;
          cout<<"enter your name : ";
          cin>>name;
          cout<<"enter your age : ";
          cin>>age;
          cout<<"enter your password : ";
          cin>>password0;

          ofstream of1;
          of1.open("my_project.txt");
          if(of1.is_open()){
            of1<<name<<endl<<password0;
            cout<<"registration successfull"<<endl;
          }
          break;
        }
        case 2:{
          i = 0;
          cout<<"|------Login------|"<<endl<<endl;
          ifstream if1;
          if1.open("my_project.txt");
          cout<<"enter the user name : ";
          cin>>user;
          cout<<"enter the password : ";
          cin>>pass;

          if(if1.is_open()){
            while(!if1.eof()){
              while(getline(if1 , text)){
                istringstream iss(text);
                iss>>word;
                cred[i] = word;
                i++;
              }
              if(user==cred[0] && pass == cred[1]){
                cout<<"login successfull"<<endl<<endl;
                cout<<"details...."<<endl;
                cout<<"username: "<<name<<endl;
                cout<<"password: "<<pass<<endl;
                cout<<"Age: "<<age<<endl;
              }
              else{
                cout<<endl<<endl;
                cout<<"incorrect credentials ......"<<endl;
                cout<<"press 2 to login "<<endl;
                cout<<"press 3 to change password"<<endl;
                break;
              }
            }
          }
          break;
        }
        case 3:{ 
          i = 0;
          cout<<"|------change password------|"<<endl<<endl;
          ifstream if2;
          if2.open("my_project.txt");
          cout<<"enter the old password : ";
          cin>>old;
          if(if2.is_open()){
            while(!if2.eof()){
              while(getline(if2,text)){
                istringstream iss(text);
                 iss>>word1;
                 cp[i]=word1;
                 i++;
              }
              if(old==cp[1]){
                if2.close();
                ofstream of1;
                of1.open("my_project.txt");
                if(of1.is_open()){
                  cout<<"enter your new password : ";
                  cin>>password1;
                  cout<<"enter your password again : ";
                  cin>>password2;
                  if(password1==password2){
                    of1<<cp[0]<<endl;
                    of1<<password1;
                    cout<<"password change successfully"<<endl;
                  }
                  else{
                    of1<<cp[0]<<endl;
                    of1<<old;
                    cout<<"password does not match ";
                  }
                }
              }
                else{
                cout<<"please enter the valid password"<<endl;
                break;
              }
            }
          }
          break;
        }
        case 4:{
          cout<<"______thankyou_______";
          break;
        }
        default:{
          cout<<"enter a valid choice";
        }
      }
    }while(a!=4);
  return 0;
}
