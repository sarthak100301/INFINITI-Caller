#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;
struct node
{
string firstName; 
string lastName; 
string phone; 
char gender; 
string mail; 
node *next;
};
class Register{
  public:
    string username, password;
};

class Login{
  public:
    string inpUsername, inpPassword;
};
class List
{
private:
node *head, *tail; public:
List()
{
head = NULL; tail = NULL;
}
void create_contact(string first,string last,string phone,char gender,string mail)
{
node *temp = new node; temp->firstName = first; temp->lastName = last; temp->phone=phone; temp->gender=gender; temp->mail=mail;
temp->next = NULL; if (head == NULL)
{
head = temp; tail = temp; temp = NULL;
}
else
{
tail->next = temp; tail = temp;
}
}
void display_all()
{
int contactNum = 1; node *temp = new node; temp = head;
while (temp != NULL)
{
cout << "\nContact Number: " << contactNum << endl;
cout << "First Name: " << temp->firstName << endl; cout << "Last Name: " << temp->lastName << endl; cout<<"phone number: "<<temp->phone<<endl; cout<<"gender: "<<temp->gender<<endl; cout<<"mail id: "<<temp->mail<<endl;
++contactNum; temp = temp->next;
}
}
int search(string x)
{
int position=0;
node* current = head;
while (current->firstName != x)
{
current=current->next;
}
cout<<"Contact found\n "; return 1;
}
void updatefirst(string x,string fn)
{
int t=search(x); if(t==1)
{
cout<<"First name of the contact updated."<<endl; node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->firstName=fn;
}
}
void updatelast(string x,string fn)
{
int t=search(x); if(t==1)
{
cout<<"Last name of the contact updated."<<endl; node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->lastName=fn;
}
}
void updatenum(string x,string fn)
{
int t=search(x); if(t==1)
{
cout<<"Phone number of the contact updated."<<endl; node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->phone=fn;
}
}
void updategender(string x,char fn)
{
int t=search(x); if(t==1)
{
cout<<"Gender of the contact updated."<<endl; node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->gender=fn;
}
}
void updatemail(string x,string fn)
{
int t=search(x); if(t==1)
{
cout<<"Mail id of the contact updated."<<endl; node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->mail=fn;
}
}
string modifiedsearch(string x)
{
string t="No match found."; node*ptr=head;
int s=x.length();
while(ptr!=NULL)
{
if(x.substr(0,x.length())==ptr->firstName.substr(0,x.length()))
{
cout << "First Name: " << ptr->firstName << endl; cout << "Last Name: " << ptr->lastName << endl; cout<<"phone number: "<<ptr->phone<<endl; cout<<"gender: "<<ptr->gender<<endl; cout<<"mail id: "<<ptr->mail<<endl;
ptr=ptr->next;
}
else
{
ptr=ptr->next;
}
}
}
void delete_n(string x)
{
node *prevptr=head; node *temp=NULL;
node *currentptr=head->next; int m=search(x);
if(m==1)
{
if(prevptr->firstName==x)
{
prevptr=prevptr->next; head=prevptr;
}
else
{
while(currentptr!=NULL)
{
if(currentptr->firstName==x)
{
}
else
{
}
temp=currentptr; currentptr=NULL;
prevptr=prevptr->next; currentptr=currentptr->next;
}
}
if(temp!=NULL)
{
}
else
{
prevptr->next=temp->next; cout<<"Contact deleted..."<<endl;
cout<<"Contact doesn't exist... "<<endl;
}
}
}
};
int main()
{
system("Color 8F");
ofstream SavePass;
ofstream MyProfile; ofstream MyContacts;
List Contacts;
int choice, position; string firstName,m; string lastName; string phone ;
char gender; string mail; string t; string fname; string lname; long long int mynumber; char gen; int ag; string hon; string bgroup; int User;
int count=0; string username; string password; int cnt=1; int c;
cout<<"           "<<" ____ ____ ____ ____ ____ ____ ____ ____ _______________ ____ ____ ____ ____ ____ ____ "<<endl;
cout<<"WELCOME TO "<<"||I |||N |||F |||I |||N |||I |||T |||I |||             |||C |||A |||L |||L |||E |||R ||"<<endl;
cout<<"           "<<"||__|||__|||__|||__|||__|||__|||__|||__|||_____________|||__|||__|||__|||__|||__|||__||"<<endl;
login:
cout<<"\nPlease enter "<<endl<<"1 for New User"<<endl<<"2 for Existing User"<<endl;
cout<<"->";
cin>>User;
Register newUser;
Login newLogin;
switch(User)
{
case 1:
cout << "Welcome please register your account ";
cout << "\nEnter your desired username: ";
cin >> newUser.username;
cout << "Enter your desired password: ";
cin >> newUser.password;
cout << "\nSuccessfully Registered your account, Please login below.";
cout << "\nUsername: ";
cin >> newLogin.inpUsername;
cout << "\nPassword: ";
cin >> newLogin.inpPassword;
if(newLogin.inpUsername == newUser.username && newLogin.inpPassword == newUser.password){
cout << "\nSuccessfully logged in, loading your dashboard...";
SavePass.open("passwords.txt");
SavePass << cnt << endl;
SavePass << newUser.username << endl;
SavePass << newUser.password << endl;
cnt=cnt+1;
SavePass.close();
cout<< "Password saved on password.txt"<<endl;
break;}
else {
cout << "Login Failed Please try again later!";
goto login;
}
case 2:
string userName;
string userPassword;
int loginAttempt = 0;
while (loginAttempt < 5)
{
cout << "Please enter your user name: ";
cin >> userName;
cout << "Please enter your user password: ";
cin >> userPassword;
if (userName == "Dev" && userPassword == "8700439145")
{
cout << "Welcome Dev!\n";
break;
}
else if (userName == "Ayush" && userPassword == "7043172152")
{
cout << "Welcome Ayush!\n";
break;
}
else if (userName == "Sarthak" && userPassword == "9790101066")
{
cout << "Welcome Sarthak!\n";
break;
}
else if (userName == "Kauser" && userPassword == "9942992332")
{
cout << "Welcome Kauser!\n";
break;
}
else
{
cout << "Invalid login attempt. Please try again.\n" << '\n';
loginAttempt++;
}
}
if (loginAttempt == 5)
{
cout << "Too many login attempts! The program will now terminate.";
return 0;
}
cout << "Thank you for logging in.\n";
}
PD:
cout<<endl<<"Enter your first name: ";
cin >> fname;
cout<<"Enter your last name: ";
cin >> lname;
cout<<"Enter your contact number: ";
cin >> mynumber;
cout<<"Enter your Age: ";
cin >> ag;
cout<<"Enter blood group: ";
cin >> bgroup;
genderselect:
cout<<"Enter your gender[M-Male F-Female O-Other]: ";
cin >> gen;
switch(gen)
{
case 'M':
hon="Mr.";
break;
case 'F':
hon="Ms.";
break;
case'O':
hon="Mx.";
break;
default:
cout<<"Enter valid Gender.";
goto genderselect;
}
if(fname.size()>0){
cout<<endl<<"Hello "<<hon<<" "<<fname<<". ";
menu:
start:
cout << "What would you like to do?: " << endl; 
cout<<"0. Show My Profile "<<endl;
cout << "1. Show All Contacts " << endl;
cout << "2. Add A Contact " << endl; 
cout << "3. Remove A Contact " << endl; 
cout << "4. Search Contacts " << endl; 
cout<< "5. Update contact "<<endl;
cout<<"6. Show total number of contacts"<<endl;
cout << "7. Exit The Program " << endl; 
cout<<endl<<"Enter your choice: ";
cin >> choice; char hh;
node *temp = new node;
switch (choice)
{
case 0:
cout<<endl<<"                                          My profile"<<endl;
cout<<"Name: "<<hon<<" "<<fname<<" "<<lname<<endl;
cout<<"Age: "<<ag<<endl;
cout<<"Contact number: "<<mynumber<<endl;
cout<<"Blood group: "<<bgroup<<endl;
cout<<endl;
MyProfile.open("myprofile.txt");
MyProfile<<fname<<endl<<lname<<endl;
MyProfile<<ag<<endl;
MyProfile<<mynumber<<endl;
MyProfile<<bgroup<<endl;
MyProfile.close();
goto menu;
break;
case 1:
if(count>0){
cout << endl; Contacts.display_all(); cout << endl;
goto menu;
}
else{
cout<<"The contact list is empty. First add a contact"<<endl<<endl;
goto menu;
}
break; 
case 2:
cout <<endl<< "Enter first name: "; cin >> firstName;
cout << "Enter last name: "; cin >> lastName;
cout<<"Enter the phone number: "; cin>>phone;
cout<<"Enter the gender[M-Male F-Female O-Other]: "; cin>>gender;
cout<<"Enter mail id: "; cin>>mail;
Contacts.create_contact(firstName, lastName,phone,gender,mail); cout << endl;
count=count+1;
cout<<"Contact added"<<endl;
MyContacts.open("mycontacts.txt");
for(c=0;c<count;c++){
MyContacts << cnt<<endl;
MyContacts << firstName<<endl;
MyContacts << lastName<<endl;
MyContacts << phone<<endl;
MyContacts << gender<<endl;
MyContacts << mail<<endl;
cnt=cnt+1;
MyContacts.close();
}
goto menu;
break; 
case 3:
cout << "Enter the name of the contact you would like to remove: "; cin>>firstName;
Contacts.delete_n(firstName);
goto menu;
break;
case 4:
cout<<"Enter the initials of name you want to search for:"<<endl; cin>>t;
Contacts.modifiedsearch(t); 
goto menu;
break;
case 5:
int choice;
cout<<" Enter 1 to change first name\n Enter 2 to change last name\n Enter 3 to change phone number\n Enter 4 to change gender\n Enter 5 to change mail id"<<endl;
cin>>choice;
if(choice==1){
cout<<"Enter first name to be changed"<<endl; cin>>firstName;
cout<<"Enter new first name"<<endl; cin>>m; Contacts.updatefirst(firstName,m);
goto menu;
}
else if(choice==2){
cout<<"Enter first name to be changed"<<endl; cin>>firstName;
cout<<"Enter new last name"<<endl; cin>>m;
Contacts.updatelast(firstName,m);
goto menu;
}
else if(choice==3){
cout<<"Enter first name of the contact who's number you want to change"<<endl;
cin>>firstName;
cout<<"Enter new number"<<endl; cin>>m; Contacts.updatenum(firstName,m);
goto menu;
}
else if(choice==4){
cout<<"Enter first name of the contact who's gender you want to change'"<<endl;
cin>>firstName;
cout<<"Enter new gender"<<endl; cin>>hh; Contacts.updategender(firstName,hh);
goto menu;
}
else if(choice==5){
cout<<"Enter first name of the contact who's mail id you want to change"<<endl;
cin>>firstName;
cout<<"Enter new mail id"<<endl; 
cin>>m; 
Contacts.updatemail(firstName,m);
goto menu;
}
else
cout<<"Enter a valid option";
goto menu;
break; 
case 6:
cout<<"Total number of contacts are "<<count<<endl;
goto menu;
break;
case 7: 
exit(1);
default:
cout << "Please select a valid option." << endl;
break;
}
}
}
