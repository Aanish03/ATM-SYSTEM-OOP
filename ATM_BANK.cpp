#include<iostream>
#include<stdlib.h>
using namespace std;

class ATM{
	private:
		int accounts[10] ={101,102,103,104};
		float bal[10] ={100200,10500,6000,140500};
		int account_number[10]={1224,1292,5463,9783};
		int pin[10]={546,968,957,747};
		int admin_pin = 8135;
		int ac_holdings = 3;

	public: 
	void display(void);
	void add_new_ac();
	int find_account(int id);
	int  check_bal(int ac , int pin);
	void check_sufficient_bal(float amount);
	int withdraw( int amount , int pin , int ac);
	int admin_auth(int p);
    void  change_admin_pin(int a);
	
	
}a;
//class finction section
ATM :: find_account(int a){
	int flag=0;
	int i; 
	for(i=0; i<=ac_holdings; i++){
		if(a == accounts[i]){
			flag = 1;
		}
	}
	if(flag == 0){
		cout<<"the account is not available in the bank";
	}
	
	return flag;
}
ATM :: admin_auth(int p){
	if(p == a.admin_pin){
		return 1;
		
	}
	else{
		return 0;
	}
}
void ATM::display(){

	
		cout<<"details for all users\n";
		for(int j=0; j<=3; j++ ){
		
		cout<<"id : "<<a.accounts[j]<<"\n";
		cout<<"pin : "<<"xxxx"<<"\n";
		cout<<"balance : "<<a.bal[j]<<"\n";

	cout<<"\n";
	}
	};
 ATM::change_admin_pin(int ac ,int pin){

 	
	admin_pin = a;
	cout<<"the pin was successfully changed to "<<a<<"\n";
};
ATM::withdraw(int amount,int pin,int ac){
	int i;
	int account_found = 0; 
	int ac_index;
	
	for(i=0; i<=a.ac_holdings; i++){
		if(ac==a.account_number[i]){
			account_found =1;
			ac_index=i;
		}
	}
	if(account_found == 0){
		cout<<"the account dose not exist in the bank \n\n";
		
	}
	else{
		cout<<"accont found in the database \n\n";
		cout<<"testing your pin \n";
		
		if(pin == a.pin[ac_index]){
			if(a.bal[ac_index] < amount ){
				cout<<"insufficient balance \n";
				exit(0);
			}
			a.bal[ac_index] = a.bal[ac_index]-amount;
			return a.bal[ac_index]; 
			
		}
		else{
			cout<<"sorry !! enterd pin was incorrect \n\n";
			
		}
		
	}
	
	
}
void ATM::check_bal()
// simple function section
void print_star(){
	cout<<"******************************************************* \n";
} 
int select_option(){
	int op;
	cout<<"what you want to do !! \n\n";
	cout<<"\n 1] admin panel ";
	cout<<"\n 2] withdraw ";
	cout<<"\n 3] check balance ";
	cout<<"\n 4] exit \n";
	cin>>op;
	
	return op;
};


int admin_auth_local(){
	int x;
	cout<<"enter the admin pin \n";
	cin>>x;
	int auth = a.admin_auth(x);
	if(auth == 1){
		return 1;
	}
	else{
		return 0;
	}
}
int admin_page(){
	int option;
	int pin;
	int check_auth = admin_auth_local();
if(check_auth == 1){
		print_star();
	cout<<"\t\twelcome to the admin page \n\n";
	print_star();
	cout<<"hello dear admin \n";
	print_star();
	cout<<"choose option \n\n";
	cout<<"1] display all user details \n";
	cout<<"2] chnge the admin pin \n";
	cout<<"3] exit \n";
	print_star();
	cin>>option;
	switch(option){
		case 1:
			a.display();
			break;
		case 2:
			cout<<"enter a new pin \n";
			cin>>pin;
			a.change_admin_pin(pin);
			break;
		case 3:
			exit(0);
	}
	
	
}
else{
	cout<<"sorry you are not a admin \n";
}

};

// withdraw function 

int withdraw(){
	float amount;
	int ac;
	int pin; 
	int avai_bal;
	print_star();
	cout<<"welcome to the withdraw portal \n";
	print_star(); 
	cout<<"enter the account number \n";
	cin>>ac;
	cout<<"enter the amount to withdraw \n";
	cin>>amount;
	cout<<"enter the pin for account \n";
	cin>>pin;
	
	
	avai_bal = a.withdraw(amount,pin,ac);
	cout<<"the amount "<<amount<<" was withdraw the balance in your AC : "<<avai_bal;
}

int main(){
	ATM a;
	int c;
	int account_avi;
	int option;
	print_star();
	cout<<"wellcome to the Aanish's ATM \n";
	print_star();
	option = select_option();
	print_star();
	
	switch(option){
		case 1:
			admin_page();
			break;
		case 2:
			withdraw();
			break;
			
		case 3:
			check_bal();
		default:
			cout<<"war";
			
	}

	
	return 0;
}
