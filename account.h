using namespace std;

class Account{
	private:
		string m_ID;
		string m_username;
		string m_password;
	public:
		~Account();
		
		void setID(const string ID);
		void setUser(const string username);
		void setPass(const string password);
		
		string getID() const;
		string getPass() const;
		string getUser() const;
		
		void accOutput();
		void accChange(string pass, string user);
		
};
