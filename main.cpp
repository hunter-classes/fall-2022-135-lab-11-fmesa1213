#include<iostream>
#include "profile.h"
#include <profile.cpp>
#include "network.h"
#include <network.cpp>
using namespace std;

int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}

int main()
{
Network nw;
nw.addUser("mario", "Mario");
nw.addUser("luigi", "Luigi");
nw.addUser("yoshi", "Yoshi");

nw.follow("mario", "luigi");
nw.follow("mario", "yoshi");
nw.follow("luigi", "mario");
nw.follow("luigi", "yoshi");
nw.follow("yoshi", "mario");
nw.follow("yoshi", "luigi");

nw.addUser("wario", "Wario");

for (int i = 2; i < 6; i++) {
string usrn = "mario" + to_string(i);
string dspn = "Mario " + to_string(i);
nw.addUser(usrn, dspn);
nw.follow(usrn, "mario");
}
nw.follow("mario2", "luigi");

nw.printDot();
}
