//header files
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#define CLRSCR system("cls");
using namespace std;

//global variables
int c[50],i=0,c2[50];
static int needed=0;
string savename;

//class
class icecream_parlour {
		int code;
		char flavour[30];
		int amount;

	public:
		void input();
		void output();
		int getcode() {
			return code;
		}
		char *getflavour() {
			return flavour;
		}
		int getamount() {
			return amount;
		}
};

//member function definitions
void icecream_parlour::input() {
	char ch;
	cout<<"\nCode: ";
	cin>>code;
	cin.get(ch);
	cout<<"\nFlavour: ";
	cin.getline(flavour,30);
	cout<<"\nAmount: ";
	cin>>amount;
	cin.get(ch);
}

void icecream_parlour::output() {
	cout<<"\n\n\n\t\t\t|"<<setw(20)<<"Code |"<<setw(30)<<code<<" |";
	cout<<"\n\t\t\t|"<<setw(20)<<"Flavour |"<<setw(30)<<flavour<<" |";
	cout<<"\n\t\t\t|"<<setw(20)<<"Amount |"<<setw(30)<<amount<<" |";
}

//functions
string printrandomstring(int n) {
	char alphabet[26]= {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	string res="";
	for(int i=0; i<3; i++)
		res=res+alphabet[rand()%26];
	return res;
}

void makeownicecream() {
	CLRSCR;
	int ch;
	char c='y';
	cout<<"\n\n\n\t\t\t\t\t\t\tLet's get started";
label3:
	cout<<"\n\nEnter base icecream flavour:";
	cout<<"\n1.Vanilla";
	cout<<"\n2.Chocolate";
	cin>>ch;
	switch(ch) {
		case 1:
			cout<<"\nChoose toppings";
			while(c=='y'||c=='Y') {
				cout<<"\n1.Chocochips";
				cout<<"\n2.Chocolate sauce";
				cout<<"\n3.Dry fruits";
				cout<<"\n4.Fruit flavour sauce\n";
				cout<<"\n5.Not Needed";
				cin>>ch;
				cout<<"Want anything else(y/n)";
				cin>>c;
			}
			c='y';
			cout<<"\n Chocolates??";
			while(c=='y'||c=='Y') {
				cout<<"\n1.Ferrero";
				cout<<"\n2.5star";
				cout<<"\n3.Dairy Milk";
				cout<<"\n4.Not needed";
				cin>>ch;
				cout<<"\nWant anything else(y/n)";
				cin>>c;
			}
			c='y';
			cout<<"\nExtras";
			while(c=='y'||c=='Y') {
				cout<<"\n1.Brownie";
				cout<<"\n2.Hot chocolate";
				cout<<"\n3.Chocostick";
				cout<<"\n4.Not needed";
				cin>>ch;
				cout<<"\nWant anything else(y/n)";
				cin>>c;
			}
			break;
		case 2:
			cout<<"\nChoose toppings";
			while(c=='y'||c=='Y') {
				cout<<"\n1.Chocochips";
				cout<<"\n2.Chocolate sauce";
				cout<<"\n3.Dry fruits";
				cout<<"\n4.Fruit flavour sauce\n";
				cout<<"\n5.Not Needed";
				cin>>ch;
				cout<<"Want anything else(y/n)";
				cin>>c;
			}
			c='y';
			cout<<"\n Chocolates??";
			while(c=='y'||c=='Y') {
				cout<<"\n1.Ferrero";
				cout<<"\n2.5star";
				cout<<"\n3.Dairy Milk";
				cout<<"\n4.Not needed";
				cin>>ch;
				cout<<"\nWant anything else(y/n)";
				cin>>c;
			}
			c='y';
			cout<<"\nExtras";
			while(c=='y'||c=='Y') {
				cout<<"\n1.Brownie";
				cout<<"\n2.Hot chocolate";
				cout<<"\n3.Chocostick";
				cout<<"\n4.Not needed";
				cin>>ch;
				cout<<"\nWant anything else(y/n)";
				cin>>c;
			}
			break;

		default:
			cout<<"\nwrong choice...input again";
			goto label3;
	};
}

//function to edit data in file
void edit() {
	CLRSCR;
	char ed,cont='y';
	icecream_parlour b;
	while(cont=='y'||cont=='Y') {
		cout<<"\nDo you want to Add or Delete data(A/D) ? ";
		cin>>ed;
		//code to add data
		if(ed=='a'||ed=='A') {
			char ans='y';
			ofstream fout("Project.dat",ios::app|ios::binary);
			while(ans=='y'||ans=='Y') {
				CLRSCR;
				//writing data to file
				b.input();
				fout.write((char*)&b,sizeof(b));
				b.output();
				cout<<"\n\n\nDo you want to enter more data? (Y/N) ";
				cin>>ans;
			}
			fout.close();
		}
		//code to delete data
		else if(ed=='d'||ed=='D') {
			int del;
			char ans='y';
			while(ans=='y'||ans=='Y') {
				CLRSCR;
				cout<<"\nEnter the Code of icecream that you want to delete: ";
				cin>>del;
				ifstream fin("Project.dat",ios::binary);
				ofstream fout("Temp.dat",ios::app|ios::binary);
				while(fin.read((char*)&b,sizeof(b)));
				{
					if(del==b.getcode()) {
						b.output();
						cout<<"\ndelete? (Y/N)";
						char confirm;
						cin>>confirm;
						if(confirm=='n')
							fout.write((char*)&b,sizeof(b));
					} else
						fout.write((char*)&b,sizeof(b));
				}
				fout.close();
				fin.close();
				remove("Project.dat");
				rename("Temp.dat","Project.dat");
				cout<<"\nDo you want to delete more ? (Y/N) ";
				cin>>ans;
			}
		} else
			exit(0);
		cout<<"\nDo you want to continue editing or deleting? (Y/N) ";
		cin>>cont;
	}
}

// fn to show menu
void menu() {
	CLRSCR;
	icecream_parlour b;
	ifstream fin;
	fin.open("Project.dat",ios::binary);
	cout<<"\n\n\t\t\tHere is the Menu";
	cout<<"\n\n\n\t\t\t"<<"|"<<setw(13)<<"CODE|"<<setw(40)<<"FLAVOUR|"<<setw(24)<<"PRICE|";
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&b,sizeof(b))) {
		cout<<"\n\t\t\t"<<"|"<<setw(12)<<b.getcode()<<"|"<<setw(39)<<b.getflavour()<<"|"<<setw(23)<<b.getamount()<<"|";
	}
	srand(time(NULL));
	savename=printrandomstring(3);
	cout<<"\n\n\nToday's special discount for name starting with "<<savename;
	fin.close();
}

//fn to buy icecream
void buy() {
	char ch;
	icecream_parlour b;
label2:
	ifstream fin;
	fin.open("Project.dat",ios::binary);
	//displays the menu
	menu();
	int count=0;
	cout<<"\n\n\n\t\t\t\tEnter Code of Icecream you want: ";
	cin>>c[i];
	fin.seekg(0,ios::beg);
	while(fin.read((char *)&b,sizeof(b))) {
		if(c[i]==b.getcode()) {
			b.output();
			getch();
			if(c[i]==100)
				makeownicecream();
			count++;
		}
	}
	if(count==0) {
		cout<<"\n\n\t\t\tIncorrect code...";
		cout<<"\n\t\t\tTry Again ? (Y/N)";
		cin>>ch;
		if(ch=='y'||ch=='Y')
			goto label2;
		else
			exit(0);
	}
	cout<<"\n\n\t\t\t How many would you like to have ?";
	cin>>c2[i];
	i++;
	needed++;
	fin.close();
}

// fn to print bill
void bill() {
	icecream_parlour b;
	int sum=0,ch;
	string oname,oname2;
	CLRSCR;
	ifstream fin;
	fin.open("Project.dat",ios::binary);
	cout<<"\n\n\n\n\t\t\t\tBILL";
	cout<<"\n\n\n\n"<<"|"<<setw(13)<<"CODE |"<<setw(40)<<"FLAVOUR |"<<setw(24)<<"AMOUNT |"<<setw(20)<<"NO. OF ITEMS |"<<setw(20)<<"FINAL PRICE |";
	while(fin.read((char *)&b,sizeof(b))) {
		for(i=0; i<needed; i++) {
			if(c[i]==b.getcode()) {
				cout<<"\n"<<"|"<<setw(12)<<b.getcode()<<"|"<<setw(39)<<b.getflavour()<<"|"<<setw(23)<<b.getamount()<<"|"<<setw(19)<<c2[i]<<"|"<<setw(19)<<c2[i]*b.getamount()<<"|";
				sum=sum+c2[i]*b.getamount();
			}
		}
	}
	cout<<setw(95)<<"\n\n\t\t\t\t\t\t\t\t\t\t\t  GRAND TOTAL "<<sum;
	cout<<"\n\n\t\t\tEnter name";
	cin>>oname;
	oname2=oname.substr(0,3);
	if(savename==oname2) {
		cout<<"\n\n\t\t\tYou have got 10% discount! ";
		cout<<"\n\n\t\t\t\tGrand total now is "<<(sum*90)/100;
	}
	fin.close();
}

//start of main()
int main() {
	int ch,choice;
	char password[20],ignore,choose;
	icecream_parlour a;
	CLRSCR;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t";
	cout<<"WELCOME TO PRIYANSH'S ICECREAM PARLOUR!";
	getch();
	CLRSCR;
	cout<<"\n\nEnter 1.If you want to access private information";
	cout<<"\n\n      Customers press any other key(0-9   except 1) : ";
	cin>>ch;
	cin.get(ignore);
	switch(ch) {                       //switch case for customer/member
		case 1:
			CLRSCR;                             //for private info
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t\tEnter password: ";
			gets(password);
			if(strcmp(password,"password")==0) {
				CLRSCR;
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t\t";
				cout<<"\aACCESS GRANTED!";
				cout<<"\n\n\n\n\t\t\t\t\tEnter any key to continue.....";
				getch();
				edit();
			}                          //if ends
			else {
				cout<<"\n\n";
				cout<<"\t\t\t\t\t\t";
				cout<<"\aACCESS DENIED!\n\n\n\n\n";
				exit(0);
			}
			//code for private info ends
			break;              //case 1 ends

		default:
label:                             //for customer
			CLRSCR;
			int choice;
			cout<<"\n\n\n\n\t\t\t\t\t\tHELLO HOW MAY I HELP YOU? ";
			cout<<"\n\n\t\t\tWould you like to ..";       //where to eat
			cout<<"\n\n\t\t\t1. Home Delivery (Paytm only)";
			cout<<"\n\t\t\t2. Take Away";
			cout<<"\n\t\t\t3. Eat in the Parlour\n";
			cout<<"\n\t\t\t4.EXIT\n\t\t\t";
			cin>>choice;                         //choice for where to eat
			if(choice==4)
				exit(0);
			else if(choice==1||choice==2||choice==3) {
				CLRSCR;
				choose='y';
				while(choose=='y'||choose=='Y') {      //menu and buying
					CLRSCR;
					buy();
					cout<<"\n\n\t\t\t\tDo you want to buy more?(Y/N) ";
					cin>>choose;
				}
				if(choice==2||choice==3) {
					bill();
					cout<<"\n\n\n\n\n\n\n\n\t\t\tThankyou for visiting! Please come again!";                          // print bill
					cout<<"\n\n\n\t\t\tFollow us on instagram and facebook @priyanshicecreams.";
					cout<<"\n\t\t\tOur branches in Hyderabad|Jaipur|Jalandhar|Amritsar|Delhi|Chennai|Dehradun";
				}
				if(choice==1) {
					char address[50],name[30],ch;
					long phoneno;
					CLRSCR;
					cout<<"\n\n\n\t\t\tEnter your name (less than 30 chars): ";
					cin.get(ch);
					cin.getline(name,30);
					cout<<"\n\t\t\tEnter your address (less than 50 chars): ";
					cin.getline(address,50);
					cout<<"\n\t\t\tEnter phone number (Paytm): ";
					cin>>phoneno;
					cin.get(ch);
					CLRSCR;
					bill();
					cout<<"\n\n\t\t\tDelivery being made to...";
					cout<<"\n\t\t\tNAME: "<<name;
					cout<<"\n\t\t\tADDRESS: "<<address;
					cout<<"\n\t\t\tPHONE NO. :"<<phoneno;
					cout<<"\n\n\n\n\n\n\n\n\\t\t\t\tThankyou for visiting! Please come again!";
					cout<<"\n\n\n\n\t\t\t\tFollow us on instagram and facebook @priyanshicecreams.";
					cout<<"\n\t\t\tOur branches in Hyderabad|Jaipur|Jalandhar|Amritsar|Delhi|Chennai|Dehradun";
				}
			} else {
				cout<<"\nWrong Choice";
				cout<<"\nTry Again...";
				getch();
				goto label;
			}
			break;
	};
	return 0;
}
