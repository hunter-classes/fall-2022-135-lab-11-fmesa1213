include "profile.h"

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
