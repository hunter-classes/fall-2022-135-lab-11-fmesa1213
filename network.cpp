#include <iostream>
#include "network.h"
using namespace std;

class Profile
{
//Declare two private variables
private:
string username;
string displayname;

public:
// Profile constructor for a user (initializing
// private variables username=usrn, displayname=dspn)
Profile(string usrn, string dspn)
{
username = usrn;
displayname = dspn;
}
// Default Profile constructor (username="", displayname="")
Profile()
{
username = "";
displayname = "";
}
//geeters
// Return username
string getUsername()
{
return username;
}
// Return name in the format: "displayname (@username)"
string getFullName()
{
return displayname + " (@" + username + ")";
}
// Change display name
void setDisplayName(string dspn)
{
displayname = dspn;
}
};

//Implementation of the class Network
class Network
{
//Declare the private variables
private:
//max number of user profiles
static const int MAX_USERS = 20;
//number of registered users
int numUsers;
//user profiles array
Profile profiles[MAX_USERS];

int findID(string usrn);

public:
Network();


bool addUser(string usrn, string dspn);
};

int Network::findID(string usrn)
{

for (int i = 0; i <= numUsers; i++)
{
//Return the ID of the username, if the
//username of the profiles is equal to the usrn
if (profiles[i].getUsername() == usrn)
{
return i;
}
}
//If it is not mathced then return -1
return -1;
}

// Default constructor
Network::Network()
{
//set number of users is equal to zero
numUsers = 0;
}

//Definition of the function addUser
//This function allows adding new users
bool Network::addUser(string usrn, string dspn)
{

if (numUsers < MAX_USERS && findID(usrn) == -1)
{
//Use a for loop, to repeat the loop until and unless
// the array profiles is not full
for (int i = 0; i < usrn.length(); i++)
{
//Check the username usrn must be a
//non-empty alphanumberic string
if (!isdigit(usrn[i]) && !isalpha(usrn[i]))
{
return false;
}
}
//Check the above conditions are satisified
//the new user should be added to the array
Profile pFinal(usrn, dspn);
profiles[numUsers] = pFinal;
numUsers++;
//The function should return treu
return true;
}
//otherwise do not add the user and return false
else
{
return false;
}
}

//main function
int main()
{
//Create an object
Network nw;
//call the function addUser and it returns true(1)
cout << nw.addUser("mario", "Mario") << endl;
//call the function addUser and it returns true(1)
cout << nw.addUser("luigi", "Luigi") << endl;

//call the function addUser and it returns false(0)
cout << nw.addUser("mario", "Mario2") << endl;
//call the function addUser and it returns false(0)
cout << nw.addUser("mario 2", "Mario2") << endl;
//call the function addUser and it returns false(0)
cout << nw.addUser("mario-2", "Mario2") << endl;


for (int i = 2; i < 20; i++)
{
//call the function addUser and it returns true(1)
cout << nw.addUser("mario" + to_string(i), "Mario" + to_string(i))
<< endl;
//call the function addUser and it returns false(0)
cout << nw.addUser("yoshi", "Yoshi") << endl;
}

return 0;
}
