#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "database.h"
using namespace std;

int main(int argc, char *argv[])
{
  
  const string mainFile = ".directoryAIS";
  Database ais(mainFile);
	char x;
	Account me;
	bool done = false;
	cout<<"Welcome to the Account  Information Storage(AIS)  BETA terminal! What would you like  to do today?"<<endl;
    while (done == false){
	    cin>>x;
	    //HELP
	    if (x == 'h'){
       cout<< ais.HelpMenu();
    }
	    //INPUT INFORMATION
	    else if (x == 'i'){
        cout<< "Please input the name of the account you would like to create: ";
        cin >> me.ID;
        	//checking for the account account
            if (!ais.accExists(me.ID)){
                cout<<"Input a Username: ";
                cin>> me.username;
                cout<<"\nInput a Password: ";
                cin>>me.password;
				//create account
                ais.accInput(me);
                cout<<"Account info stored! Would you like to read it?(Y or N)\n";
                cin>> x;
                if (x == 'Y'|| x=='y'){
                   cout<<  ais.accOutput(me.ID);
                }
            }
            //account already exists
            else{
				cout<<"Account info already exists in storage! Would you like to read it?(Y or N)\n";
                cin>> x;
                if (x == 'Y'|| x=='y'){
                   cout <<  ais.accOutput(me.ID);
                }
            }
    }
	    //OUTPUT INFORMATION
	    else if (x == 'o'){
        cout<< "Please input an account name: ";
        cin>>me.ID;

        //checking for
        if (ais.accExists(me.ID))
        {
            cout << "\n Your Account information for "<<me.ID<<": \n";
            cout<< ais.accOutput(me.ID);
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
               ais.accInput(me);
               cout<<"DONE!\nAnything else?";
             }
        }
    }
	    else if (x == 'd'){
	        cout<<"Insert the name of the account you want to delete: ";
	        cin>>me.ID;
	        if (!ais.accExists(me.ID))
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
	                    ais.accDelete(me.ID);
	                }
	            }
	            else if (x == 'y' || x == 'Y')
	            {
	            cout<< 	ais.accOutput(me.ID);
	            	cout<<endl<< "Are you sure you want to DELETE this account?(Y or N)"<<endl;
	                cin>>x;
	                if (x == 'y'||x=='Y')
	                {
	                    ais.accDelete(me.ID);
	                }
	            }
	        }
	    }
	    else if(x == 'c'){
	    	cout<<"Account ID: ";
	    	cin>>me.ID;
	    	if(ais.accExists(me.ID)){
	    		cout<<"Old Information"<<endl;
	    	cout << 	ais.accOutput(me.ID);
	    		ais.accChange(me.ID);
	    	}
	    }
	    else if (x == 'q'){
	                done = true;
	    }
	    else if (x == 'a'){
	    	cout<< "\nAll Accounts: \n\n";
	    	cout<< ais.viewAll();
	    }
	    else{
	        cerr<<"Not a valid command";
	    }
	}
}


