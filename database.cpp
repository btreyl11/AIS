#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "database.h"

using namespace std;
Database::Database()
{
  mFile = "Directory.dat";
}
Database::Database(string file_name)
{
  mFile = file_name;
  Account user;
  ifstream inFile(mFile.c_str()); 
  while(!inFile.eof())	
	{
		inFile>>user.ID;
		inFile>>user.username;
		inFile>>user.password;
		list.push_back(user);

	}
	inFile.close();
}
string Database::accOutput(string ID)
{
  ostringstream sout;

	for (Account i : list)
	{
		if(i.ID == ID){
			sout<<"ID: "<< i.ID<< endl;
			sout<<"Username: "<< i.username<< endl;
			sout<<"Password: "<< i.password << endl;
			break;
		}
	}
  return sout.str();
}

void Database::accInput(Account user)
{
	list.push_back(user);
	updatePIS();
}
bool Database::accExists(string ID)
{
	for (Account i : list)
	{
		if(i.ID == ID){
			return true;
		}
	}
	return false;
}
string Database::viewAll()
{
  
  ostringstream sout;
	for (Account i: list)
  	sout<<accOutput(i)<< endl;

  return sout.str();
}
string Database::HelpMenu()
{
	string ans = "----\ni..................INPUT ACCOUNT INFORMATION\no.................OUTPUT ACCOUNT INFORMATION\nd.................DELETE ACCOUNT INFORMATION\nh......................TO VIEW THE HELP MENU\na.............OUTPUT ALL ACCOUNT INFORMATION\np....................CHANGE YOUR 4-DIGIT PIN\nq........................TO QUIT THE PROGRAM\n----\n";
  return ans;
}
bool Database::accDelete(string ID)
{
	for (Account i : list)
	{
		if(i.ID == ID){



			list.pop_back();
			updatePIS();
      return true;
		}
	}
  return false;
}
void Database::accChange(string ID){
	accDelete(ID);
	Account a;
	cout<<"New Username: ";
	cin>>a.username;
	cout<<"New Password: ";
	cin>>a.password;
	a.ID = ID;
	accInput(a);
}
void Database::updatePIS()
{
	ofstream inFile(mFile.c_str());
	for (Account i  : list){
	inFile<<i.ID<<" "<<i.username<<" "<<i.password<<endl;
	}
	inFile.close();
}
