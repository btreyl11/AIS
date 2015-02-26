#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const string mainFile = "Directory.txt";

struct Account
{
	string ID;
	string username;
	string password;
};
vector <Account> list;
int cntLine()
{
	ifstream inFile("Directory.txt");
	int n = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
	return n;
}
void accOutput(string ID);
void initPIS();
void accInput(Account user);
void viewAll();
void HelpMenu();
bool accExists(string ID);
void accChange(string ID);
void accDelete(string ID);
void updatePIS();
int passGet();
void creatPin();
void executePIS();

int main()
{
	bool grantaccess = false;
	int corPin = passGet();
	int pin;
	while (grantaccess == false)
	{
		corPin = passGet();
		cout<<"Please input your 4-digit PIN: ";
		cin>> pin;
		if (pin == corPin){
			executePIS();
			grantaccess = true;
		}
		else{
			cout<<"PIN incorrect! ";
		}
	}	
}
int passGet()
{
	int p;
	ifstream passFile("pass.txt");
	passFile >> p;
	return p;
}
void creatPin(){
	cout<<"Please insert a 4-digit number as a PIN number: ";
	string p;
	cin >> p;
	if (p.length() == 4){
	ofstream inFile("pass.txt");
	inFile << p;
	cout<<"NEW PIN MADE!"<< endl;
	}
	else{
		cout<<"The PIN must be 4-digits! ";
	 	creatPin();
	}
}
void executePIS()
{
	char x;
	initPIS();
	Account me;
	bool done = false;
	cout<<"Welcome to the Password Information Storage(PIS)  BETA terminal! What would you like  to do today?"<<endl;
    while (done == false){
	    cin>>x;
	    //HELP
	    if (x == 'h'){
        HelpMenu();
    }
	    //INPUT INFORMATION
	    else if (x == 'i'){
        cout<<"Please input the name of the account you would like to create: ";
        cin >> me.ID;
        	//checking for the account account
            if (!accExists(me.ID)){
                cout<<"Input a Username: ";
                cin>> me.username;
                cout<<"\nInput a Password: ";
                cin>>me.password;
				//create account
                accInput(me);
                cout<<"Account info stored! Would you like to read it?(Y or N)\n";
                cin>> x;
                if (x == 'Y'|| x=='y'){
                    accOutput(me.ID);
                }
            }
            //account already exists
            else{
				cout<<"Account info already exists in storage! Would you like to read it?(Y or N)\n";
                cin>> x;
                if (x == 'Y'|| x=='y'){
                    accOutput(me.ID);
                }
            }
    }
	    //OUTPUT INFORMATION
	    else if (x == 'o'){
        cout<< "Please input an account name: ";
        cin>>me.ID;

        //checking for
        if (accExists(me.ID))
        {
            cout << "\n Your Account information for "<<me.ID<<": \n";
            accOutput(me.ID);
            cout<<"Anything else?";

        }
        //if account is false create it
        else{

            cout<<"Account does not exist! Would you like to create "<<me.ID<<"?(Y or N)";
            cin>> x;
             if (x == 'Y'||x == 'y'){
               cout<< "\nPlease insert a Username: ";
               cin>> me.username;
               cout<< "\nPlease insert a Password: ";
               cin>> me.password;
               accInput(me);
               cout<<"DONE!\nAnything else?";
             }
        }
    }
	    else if (x == 'd'){
	        cout<<"Insert the name of the account you want to delete: ";
	        cin>>me.ID;
	        if (!accExists(me.ID))
	        {
	            cout<<"I'm sorry but, this account does not exist.\n \nMain Menu\n";
	        }
	        else{
	            cout<<"Do you want to read this account before you DELETE it?(Y or N)"<<endl;
	            cin>>x;
	            if (x == 'n' || x == 'N')
	            {
	                cout<<endl<< "Are you sure you want to DELETE this account?(Y or N)"<<endl;
	                cin>>x;
	                if (x == 'y'||x=='Y')
	                {
	                    accDelete(me.ID);
	                }
	            }
	            else if (x == 'y' || x == 'Y')
	            {
	            	accOutput(me.ID);
	            	cout<<endl<< "Are you sure you want to DELETE this account?(Y or N)"<<endl;
	                cin>>x;
	                if (x == 'y'||x=='Y')
	                {
	                    accDelete(me.ID);
	                }	
	            }
	        }
	    }
	    else if(x == 'c'){
	    	cout<<"Account ID: ";
	    	cin>>me.ID;
	    	if(accExists(me.ID)){
	    		cout<<"Old Information"<<endl;
	    		accOutput(me.ID);
	    		accChange(me.ID);
	    	}
	    }
	    else if (x == 'q'){
	        cout<< "Are you sure?(Y or N)";
	        cin>> x;
	            if (x == 'y' ||x == 'Y') {
	                done = true;
	            }
	            else{
	                cout<<"OK";
	            }
	    }
	    else if (x == 'a'){
	    	cout<< "\nAll Accounts: \n\n";
	    	viewAll();
	    }
	    else if(x == 'p'){
	    	creatPin();
	    }
	    else{
	        cout<<"Not a valid command";
	    }
	}
}
void accOutput(string ID)
{
	for (int i = 0; i < list.size(); i++)
	{
		if(list[i].ID == ID){
			cout<<"ID: "<< list[i].ID<< endl;
			cout<<"Username: "<< list[i].username<< endl;
			cout<<"Password: "<< list[i].password << endl;
			break;
		}
	}
}
void accInput(Account user)
{
	list.push_back(user);
	updatePIS();
}
bool accExists(string ID)
{
	for (int i = 0; i < list.size(); i++)
	{
		if(list[i].ID == ID){
			return true;
		}
	}
	return false;	
}
void viewAll()
{
	for (int i = 0; i < list.size(); i++)
	{
		cout<<"ID: "<< list[i].ID<< endl;
		cout<<"Username: "<< list[i].username<< endl;
		cout<<"Password: "<< list[i].password << endl;
		cout<< endl;
	}
}
void HelpMenu()
{
	cout<<"----\n";
    cout<<"i..................INPUT ACCOUNT INFORMATION\n";
    cout<<"o.................OUTPUT ACCOUNT INFORMATION\n";
    cout<<"d.................DELETE ACCOUNT INFORMATION\n";
    cout<<"h......................TO VIEW THE HELP MENU\n";
    cout<<"a.............OUTPUT ALL ACCOUNT INFORMATION\n";
    cout<<"p....................CHANGE YOUR 4-DIGIT PIN\n";
    cout<<"q........................TO QUIT THE PROGRAM\n";
    cout<<"----\n";
}
void accDelete(string ID)
{
	for (int i = 0; i < list.size(); i++)
	{
		if(list[i].ID == ID){
			for (int j = i + 1; j < list.size(); j++){
			 list[j-1] = list[j];	
			}
			list.pop_back();
			updatePIS();
			break;
			
		}
	}
}
void accChange(string ID){
	accDelete(ID);
	Account a;
	cout<<"New Username: ";
	cin>>a.username;
	cout<<"New Password: ";
	cin>>a.password;
	a.ID = ID;
	accInput(a);
}
void initPIS()
{
	ifstream inFile ("Directory.txt");
	Account user;
	for (int i = 0; i< cntLine(); i++)
	{
		inFile>>user.ID;
		inFile>>user.username;
		inFile>>user.password;
		list.push_back(user);
		
	}
	inFile.close();
}
void updatePIS()
{
	ofstream inFile ("Directory.txt");
	for (int i = 0; i < list.size(); i++){
	inFile<<list[i].ID<<" "<<list[i].username<<" "<<list[i].password<<endl;
	}
	inFile.close();
}

