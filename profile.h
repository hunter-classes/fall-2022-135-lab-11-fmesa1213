class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
  {
  username = usrn;
    displayname = dspn;
  }
  
  Profile();
  {
  username == " ";
    displayname == " ";
  }
    string getUsername();
  {
  return username;
  }
    string getFullName();
  {
  string s = displayname + "(@"+username+")";
    return s;
  }
    void setDisplayName(string dspn)
    {
    displayname = dspn;
    }
};
