#include <iostream>
#include "account.h"
using namespace std;

void Account::setID(const string ID)
{
	m_ID = ID;
}
void Account::setPass(const string password)
{
	m_password = password;
}
void Account::setUser(const string username)
{
	m_username = username;
}
string Account::getID(){
	return m_id;
} 
string Account::getUser(){
	return m_username;
}
string Account::getPass(){
	return m_password;
}
void Account::accOutput(){
	cout<< m_ID<<": "<<endl;
	cout<<"Username: "<< m_username<<endl;
	cout<<"Password: "<< m_password<<endl; 
}
void Account::accInput(string id, string user, string pass){
	setID(id);
	setPass(pass);
	setUser(user);
}
