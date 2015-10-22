
#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
using namespace std;

struct Account
{
	string ID;
	string username;
	string password;
};

class Database
{
  private:
  vector<Account> list;
  string mFile;
  public:
  Database();
  Database(string file_name);

  string accOutput(string ID);
  string viewAll();
  string HelpMenu();

  bool accExists(string ID);
  bool accDelete(string ID);

  void accInput(Account user);
  void accChange(string ID);
  void updatePIS();



};
#endif
