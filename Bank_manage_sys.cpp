#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
// SSKAMNCIDK
class Bank{
   private:
     int pin;
     int id;
     float balance;
     string pass;
     string f_name;
     string name;
     string ph_No;
   public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void deposite();
    void withdrawn();
    void transfer();
    void payment();
    void search();
    void editUser();
    void delUser();
    void allRecord();
    void showPayments();
};
void Bank::menu(){
    start:
    int choice;
    int pin;
    string email;
    string password;
    cout<<"--control panel--"<<endl<<endl;
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
                cout<<"your e-mail or pin or password is wrong"<<endl<<endl;
                goto start;
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
    start:
    int choice;
    cout<<endl<<"_____BANK management system_____"<<endl<<endl;
    cout<<"1.New User"<<endl;
    cout<<"2.Already user"<<endl;
    cout<<"3.Deposite"<<endl;
    cout<<"4.Withdrawn"<<endl;
    cout<<"5.Transfer"<<endl;
    cout<<"6.Payment option"<<endl;
    cout<<"7.Search user record"<<endl;
    cout<<"8.Edit user record"<<endl;
    cout<<"9.Delete user record"<<endl;
    cout<<"10.Show all record"<<endl;
    cout<<"11.Payment all record"<<endl;
    cout<<"12.Go back"<<endl<<endl;
    cout<<"enter your choice : ";
    cin>>choice;   
    switch(choice){
        case 1:{
            new_user();
            break;
        }
        case 2:{
            already_user();
            break;
        }
        case 3:{
            deposite();
            break;
        }
        case 4:{
            withdrawn();
            break;
        }
        case 5:{
            transfer();
            break;
        }
        case 6:{
            payment();
            break;
        }
        case 7:{
            search();
            break;
        }
        case 8:{
            editUser();
            break;
        }
        case 9:{
            delUser();
            break;
        }
        case 10:{
            allRecord();
            break;
        }
        case 11:{
            showPayments();
            break;
        }
        case 12:{
            menu();
        }
        default:{
            cout<<"you entered invalid value ! please try again .";
        }
    }
    goto start;
}

void Bank::atm_management(){
    start:
    int choice;
    cout<<"_____ATM management system_____"<<endl<<endl;
    cout<<"1.User login & check balance"<<endl;
    cout<<"2.Withdraw amount"<<endl;
    cout<<"3.Account details"<<endl;
    cout<<"4.Go back"<<endl;
    cout<<"enter your choice : ";
    cin>>choice;   
    switch(choice){
        case 1:{
            break;
        }
        case 2:{
            break;
        }
        case 3:{
            break;
        }
        case 4:{
            menu();
        }
        default:{
            cout<<"you entered invalid value ! please try again .";
        }
    }
    goto start;
} 
void Bank::new_user(){
    start:
    cout<<endl<<"-----Add New User----"<<endl<<endl;
    fstream file;
    int p,i;
    string n,f_n,pa,ph;
    float b;
    cout<<"enter the user_id : ";
    cin>>id;
    cout<<"enter the name :";
    cin>>name;
    cout<<"enter father name :";
    cin>>f_name;
    cout<<"enter the pin code : ";
    cin>>pin;
    cout<<"enter the password : ";
    cin>>pass;
    cout<<"enter the phone no : ";
    cin>>ph_No;
    cout<<"enter the balance : ";
    cin>>balance;
    file.open("bank.txt",ios::in);
    if(!file){
        file.open("bank.txt",ios::app|ios::out);
        file<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
        file.close();
    }
    else{
        file>>i>>n>>f_n>>p>>pa>>ph>>b;
        while(!file.eof()){
            if(i==id){
                cout<<endl<<"user_id already exists";
                goto start;
            }
            file>>i>>n>>f_n>>p>>pa>>ph>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
        file.close();
    }
    cout<<endl<<"new user created successfully"<<endl;
}
void Bank::deposite(){
    fstream file,file1;
    int t_id;
    int found = 0;
    float dep;
    cout<<endl<<endl<<"-----deposite amount option-----"<<endl<<endl;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        cout<<"enter user id : ";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        while(!file.eof()){
            if(t_id==id){
                cout<<endl<<endl<<"enter the amount for deposite: ";
                cin>>dep;
                balance+=dep;
                file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
                found++;
                cout<<endl<<endl<<"your amount "<<dep<<" successfully deposite..";
            }
            else{
                file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0){
            cout<<endl<<"User id can not found"<<endl;
        }
    }
}
void Bank::already_user(){
    fstream file;
    int t_id;
    int found = 0;
    cout<<endl<<endl<<"-----Already User Account-----"<<endl<<endl;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<endl<<"file opening error";
    }
    else{
        cout<<endl<<"enter user id : ";
        cin>>t_id;
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        while(!file.eof()){
            if(t_id ==id){
                cout<<endl<<"Already Exist"<<endl;
                cout<<endl<<"User_id : "<<id<<endl;
                cout<<endl<<"pin : "<<pin<<endl;
                cout<<endl<<"pass : "<<pass<<endl;
                found++;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        }
        file.close();
        if(found==0){
            cout<<endl<<"User id can not found"<<endl;
        }
    }
}
void Bank::withdrawn(){
    fstream file,file1;
    int t_id;
    int found = 0;
    float deb;
    cout<<endl<<"-----Withdraw Amount-----"<<endl<<endl;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        cout<<"enter user id : ";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        while(!file.eof()){
            if(t_id==id){
                cout<<endl<<endl<<"enter the amount for withdraw : ";
                cin>>deb;
                if(deb<=balance){
                    balance-=deb;
                    file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
                    cout<<endl<<endl<<"your amount "<<deb<<" successfully withdrawn......";
                }
                else{
                    cout<<endl<<endl<<"invalid amount and your balance is : "<<balance<<endl;
                    file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
                }
                found++; 
            }
            else{
                file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0){
            cout<<endl<<"User id can not found"<<endl;
        }
    }
}
void Bank::transfer(){
    fstream file,file1;
    int s_id , r_id;
    int found = 0;
    float amount;
    cout<<endl<<endl<<"payment transfer options...."<<endl;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        cout<<endl<<"enter Sender_user id for transaction : ";
        cin>>s_id;
        cout<<endl<<"enter Receiver_user_id for transaction : ";
        cin>>r_id;
        cout<<endl<<"enter transaction amount : ";
        cin>>amount;
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        while(!file.eof()){
            if(s_id == id && amount <= balance){
                found++;
            }
            else if(r_id == id){
                found++;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        } 
        file.close();
        if(found==2){
            file.open("bank.txt",ios::in);
            file1.open("bank1.txt",ios::app|ios::ate);
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
            while(!file.eof()){
                if(s_id == id ){
                    balance -= amount;
                    file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
                }
                else if(r_id == id){
                    balance +=amount;
                    file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
                }
                file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            cout<<"money transferred successfully";
        }
        else{
            cout<<endl<<"invalid credentials"<<endl;
            file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
        }
    }
}

void Bank::payment(){
    fstream file,file1;
    int t_id;
    string b_name;
    float amount;
    int found = 0;
    time_t currentTime = time(nullptr);
    string timeString = ctime(&currentTime);

    cout<<endl<<endl<<"----Bills payment option----"<<endl<<endl;     
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
       cout<<endl<<"enter user_id : ";
       cin>>t_id;
       cout<<endl<<"Bill name : ";
       cin>>b_name;
       cout<<endl<<"enter the amount : ";
       cin>>amount;
       file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
       file1.open("bank1.txt",ios::out|ios::app);
       while(!file.eof()){
            if(t_id==id && amount<=balance){
                balance -= amount;
                file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
                found++;
            }
            else{
                file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
       }
       file.close();
       file1.close();
       remove("bank.txt");
       rename("bank1.txt","bank.txt");
       if(found==1){
          file.open("bill.txt",ios::app|ios::out);
          file<<endl<<t_id<<" "<<b_name<<" "<<amount<<" "<<timeString;
          file.close();
          cout<<endl<<endl<<b_name<<" bill payment successfully "<<endl;
       }
       else{
          cout<<endl<<"user_id or amount is invalid"<<endl;
       }
    }
}

void Bank::search(){
    cout<<endl<<endl<<"-----search user record-----"<<endl<<endl;
    fstream file;
    int t_id;
    int found = 0;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        cout<<endl<<"enter the user id : ";
        cin>>t_id; 
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        while(!file.eof()){
            if(t_id==id){
                cout<<endl<<"user record found ......"<<endl;
                cout<<endl<<"user_id : "<<id<<endl<<"name : "<<name<<endl<<"f_name : "<<f_name<<endl;
                cout<<"Password : "<<pass<<endl<<"Balance : "<<balance<<endl;
                found++;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        }
        file.close();
        if(found==0){
            cout<<endl<<"user does not found"<<endl;
        }
    }
}
void Bank::editUser(){
    cout<<endl<<endl<<"-----edit user record-----"<<endl<<endl;
    fstream file , file1;
    int t_id;
    int found = 0;
    string na,f_n,pa,ph,ba;
    int pi;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        cout<<endl<<"enter the user id : ";
        cin>>t_id; 
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        file1.open("bank1.txt",ios::out|ios::app);
        while(!file.eof()){
            if(t_id==id){
                cout<<"enter the name :";
                cin>>na;
                cout<<"enter father name :";
                cin>>f_n;
                cout<<"enter the pin code : ";
                cin>>pi;
                cout<<"enter the password : ";
                cin>>pa;
                cout<<"enter the phone no : ";
                cin>>ph;
                file1<<endl<<" "<<id<<" "<<na<<" "<<f_n<<" "<<pi<<" "<<pa<<" "<<ph<<" "<<balance<<endl;
                cout<<endl<<endl<<"Record successfully deleted"<<endl<<endl;
                found++;
            }
            else{
               file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0){
            cout<<endl<<"user does not found"<<endl;
        }
    }

}
void Bank::delUser(){
    cout<<endl<<endl<<"-----delete user record-----"<<endl<<endl;
    fstream file , file1;
    int t_id;
    int found = 0;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        cout<<endl<<"enter the user id : ";
        cin>>t_id; 
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        file1.open("bank1.txt",ios::out|ios::app);
        while(!file.eof()){
            if(t_id==id){
                cout<<endl<<endl<<"Record successfully updated"<<endl<<endl;
                found++;
            }
            else{
               file1<<endl<<" "<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
            }
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0){
            cout<<endl<<"user does not found"<<endl;
        }
    }

}
void Bank::allRecord(){
    fstream file;
    int found = 0;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
        while(!file.eof()){
            cout<<endl<<id<<" "<<name<<" "<<f_name<<" "<<pin<<" "<<pass<<" "<<ph_No<<" "<<balance<<endl;
            file>>id>>name>>f_name>>pin>>pass>>ph_No>>balance;
            found++;
        }
        file.close();
        if(found==0){
           cout<<endl<<"no record found because file is empty"<<endl;
        }
        else{
            cout<<endl<<"data fetched successfully"<<endl;
        }
    }
}
void Bank::showPayments(){
    fstream file;
    int found = 0;
    float amount;
    string time ;
    file.open("bill.txt",ios::in);
    if(!file){
        cout<<endl<<"file opening error"<<endl;
    }
    else{
        file>>id>>name>>amount>>time;
        while(!file.eof()){
            cout<<endl<<id<<" "<<name<<" "<<amount<<" "<<time<<endl;
            file>>id>>name>>amount>>time;
            found++;
        }
        file.close();
        if(found==0){
           cout<<endl<<"no record found because file is empty"<<endl;
        }
        else{
            cout<<endl<<"data fetched successfully"<<endl;
        }
    }
}
int main(){
    Bank obj;
    obj.menu();
    return 0;
}