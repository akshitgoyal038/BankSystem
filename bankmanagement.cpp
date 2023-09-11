#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class bank{
    char fname[50],lname[50],type;
    int account_number,moneydeposit;
    public:
    void create_Bank_Account();
    void Display_Account();
    void Updation();
    void deposit_money(int);
    void withdraw_money(int);
    int check();
    void report();
};
void bank :: report(){
	cout<<account_number<<setw(10)<<" "<<fname<<setw(10)<<" "<<type<<setw(6)<<moneydeposit<<endl;

}
int bank :: check(){
    return account_number;
}
void bank :: create_Bank_Account(){
    cout<<"Enter your bank account number"<<endl;
    cin>>account_number;
    cout<<"Enter your first name"<<endl;
    cin>>fname;
    cout<<"Enter your last name"<<endl;
    cin>>lname;
    cout<<"Enter the type of bank account (c/s)"<<endl;
    cin>>type;
    cout<<"Please enter the starting total money"<<endl;
    cin>>moneydeposit;
    cout<<"!!!! Your bank account is created succesfully"<<endl;
}
void bank :: Display_Account(){
    cout<<"Your bank account number is"<<" "<<account_number<<endl;
    cout<<"Your fname is"              <<" "<<fname<<endl;
    cout<<"Your lname is"              <<" "<<lname<<endl;
    cout<<"Bank account type is"       <<" "<<type<<endl;
    cout<<"Your account total money is"<<" "<<moneydeposit<<endl;
}
void bank :: Updation(){
    cout<<"Your bank account number is"<<" "<<account_number<<endl;
     cout<<"Enter your first name"<<endl;
    cin>>fname;
    cout<<"Enter your last name"<<endl;
    cin>>lname;
    cout<<"Enter the type of bank account (c/s)"<<endl;
    cin>>type;
    //cin>>moneydeposit;
    cout<<"!!!! Your bank account is created succesfully"<<endl;
}
void bank :: deposit_money(int x){
    moneydeposit+=x;
}
void bank :: withdraw_money(int x){
    moneydeposit-=x;
}
void write();
void deposit(int);
void withdraw(int);
void enquiry(int);
void updation(int);
void display_all();
int main(){
    char ch,k;
    int num;
    do
	{
	cout<<endl<<"!!!!!!!!!!!!!!!  BANK MANAGEMENT SYSTEM   !!!!!!!!!!!!!!!!!!!!";

		cout<<"::MAIN MENU::"<<endl;
		cout<<"1. NEW Bank_Account"<<endl;
		cout<<"2. Money_Deposit Total-Money"<<endl;
		cout<<"3. WITHDRAW Total-Money"<<endl;
		cout<<"4. BALANCE ENQUIRY"<<endl;
		cout<<"5. Updation AN Bank_Account"<<endl;
		cout<<"6. EXIT"<<endl;
		cout<<"Select Your Option (1-6): ";
		cin>>ch;
    
    switch(ch){
        case '1':     write();
        break;
        case '2':
        cout<<"Enter the account number for deposit"<<endl;
        cin>>num;
                      deposit(num);
        break;
        case '3':  
        cout<<"Enter the account number for withdraw"<<endl;
        cin>>num;
                      withdraw(num);
        break;
        case '4':
        cout<<"Enter the account number for enquiry"<<endl;
        cin>>num;
                     enquiry(num);
        break;
        case '5':
        cout<<"Enter the account number for updation"<<endl;
        cin>>num;
                     updation(num);
        break;
        case '6':   exit(0);
        default:cout<<"This is not exist try again"<<endl; 
    }
    cout<<endl<<"Do you want to select other option "<<endl;
    cout<<"If yes write 'y' otherwise write 'n'"<<endl;
    cin>>k;
    if(k=='n' || k=='N'){
        exit(0);
    }
    }
    while (k=='y' || k=='Y');
    return 0;
}
void write(){
    bank b1;
    ofstream outfile;
    outfile.open("bank1.dat",ios::binary|ios::app);
    b1.create_Bank_Account();
    outfile.write(reinterpret_cast<char *> (&b1), sizeof(bank));
    outfile.close();
}
void deposit(int num){
    bank b1;
    fstream file;
    int amount;
    bool found=false;
    file.open("bank1.dat", ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"File not open press enter key"<<endl;
        return;
    }
    while(!file.eof() && found==false){
        file.read(reinterpret_cast<char*>(&b1),sizeof(bank));
        if(b1.check()==num){
            b1.Display_Account();
            cout<<"Enter the money that you want to deposit"<<endl;
            cin>>amount;
            b1.deposit_money(amount);
            found=true;
            break;
        }
    }
             int pos=(-1)*static_cast<int>(sizeof(b1));
			file.seekp(pos,ios::cur);//fn1353
			file.write(reinterpret_cast<char *> (&b1), sizeof(bank));
			if(found==true) cout<<"\n\n\tRecord Updated";
            if(found==false){
            cout<<endl<<"Account number does not find"<<endl;
            }
            file.close();
}
void withdraw(int num){
    bank b1;
    fstream file;
    int amount;
    bool found=false;
    file.open("bank1.dat", ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"File not open press enter key"<<endl;
        return;
    }
    while(!file.eof() && found==false){
        file.read(reinterpret_cast<char*>(&b1),sizeof(bank));
        if(num==b1.check()){
            cout<<"Enter the money that you want to withdraw"<<endl;
            cin>>amount;
            b1.withdraw_money(amount);
            found==true;
            break;
        }
    }
                  int pos=(-1)*static_cast<int>(sizeof(b1));
			file.seekp(pos,ios::cur);//fn1353
			file.write(reinterpret_cast<char *> (&b1), sizeof(bank));
			cout<<"\n\n\tRecord Updated";
            file.close();
            if(found==true){
            cout<<endl<<"Account number does not find"<<endl;
            }
}
void updation(int num){
    bank b1;
    fstream file;
    int amount;
    bool found=false;
    file.open("bank1.dat", ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"File not open press enter key"<<endl;
        return;
    }
    while(!file.eof() && found==false){
        file.read(reinterpret_cast<char*>(&b1),sizeof(bank));
        if(num==b1.check()){
            cout<<"Enter new credentionals"<<endl;
            b1.Updation();
            found==true;
            break;
        }
    }
             int pos=(-1)*static_cast<int>(sizeof(b1));
			file.seekp(pos,ios::cur);//fn1353
			file.write(reinterpret_cast<char *> (&b1), sizeof(bank));
			cout<<"\n\n\tRecord Updated";
            file.close();
            if(found==true){
            cout<<endl<<"Account number does not find"<<endl;
            }
}
void enquiry(int num){
    bank b1;
    fstream file;
    int amount;
    bool found=false;
    file.open("bank1.dat", ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"File not open press enter key"<<endl;
        return;
    }
    while(!file.eof() && found==false){
        file.read(reinterpret_cast<char*>(&b1),sizeof(bank));
        if(num==b1.check()){
            b1.Display_Account();
            found==true;
            break;
        }
    }
            if(found==true){
            cout<<endl<<"Account number does not find"<<endl;
        }
        file.close();
}
void display_all()
{
	bank b1;
	ifstream file;
	file.open("bank1.dat",ios::binary);
	if(!file)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tBank_Account HOLDER LIST\n\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	while(file.read(reinterpret_cast<char *> (&b1), sizeof(bank)))
	{
		b1.report();
	}
	file.close();
}