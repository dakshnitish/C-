#include<iostream>
#include<fstream>
using namespace std;
class Bank{
   public:
    void menu();
    void bank_management();
    void atm_management();

};
void Bank::menu(){
    start:
    int choice;
    int pin;
    string email;
    string password;
    cout<<"control panel"<<endl<<endl;
    cout<<"1.Bank management"<<endl;
    cout<<"2.Atm management"<<endl;
    cout<<"3.Exit"<<endl<<endl;
    cout<<"enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            cout<<"____login account____"<<endl<<endl;
            cout<<"enter your email : ";
            cin>>email;
            cout<<"enter your pin : ";
            cin>>pin;
            cout<<"enter your password : ";
            cin>>password;
            if(email=="nitish@gmail.com" && pin == 244712 && password == "nitish@1234"){
                   bank_management();
            }
            else{
                cout<<"your e-mail or pin or password is wrong"<<endl;
            }
            break;
        }
        case 2:{
            atm_management();
            break;
        }
        case 3:{
            exit(0);
        }
        default:{
            cout<<"you entered invalid value ! please try again .";
        }
        goto start;
    }
}

void Bank::bank_management(){

}

void Bank::atm_management(){

}
int main(){
    Bank obj;
    obj.menu();
    return 0;
}