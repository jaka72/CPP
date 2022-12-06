
#include  <iostream>
# include <fstream>
# include <stdlib.h>	// for exit()
//#include  <bits/stdc++.h>
  
using namespace std;
  
//macro definitions
#define MAX_NAME_LEN 60  // Maximum len of your name can't be more than 60
#define MAX_ADDRESS_LEN 120  // Maximum len of your address can't be more than 120
#define MAX_ABOUT_LEN 250 // Maximum len of your profession can't be more than 250
  



// int main () {
//   char y_name[MAX_NAME_LEN];
//   char y_address[MAX_ADDRESS_LEN];
//   char about_y[MAX_ABOUT_LEN];
  
//   cout << "Enter your name: ";
//   std::cin.getline (y_name, MAX_NAME_LEN);
  
//   cout << "Enter your City: ";
//   cin.getline (y_address, MAX_ADDRESS_LEN, 'x');    // will not read after 'x'
  
//   cout << "Enter your profession (then press 0 to complete): ";
//   cin.getline (about_y, MAX_ABOUT_LEN, '0');    //$ is a delimiter 
  
//   cout << "\nEntered details are:\n"<<'\n';
//   cout << "Name: " << y_name << endl;
//   cout << "Address: " << y_address << endl;
//   cout << "Profession is: " << about_y << endl;
// }






int main()
{
    // string name;
    // int id;
  
    // // Taking id as input
    // cout << "Please enter your id: \n";
    // cin >> id;
  
    // // Takes the empty character as input
    // cout << "Please enter your name: \n";
    // getline(cin, name);
  
    // // Prints id
    // cout << "Your id : " << id << "\n";
  
    // // Prints nothing in name field
    // // as "\n" is considered a valid string
    // cout << "Hello, " << name
    //      << " welcome to GfG !\n";
  
    // // Again Taking string as input
    // getline(cin, name);
  
    // // This actually prints the name
    // cout << "Hello, " << name
    //      << " welcome to GfG !\n";
  




    ifstream inFile;
    string name;
    string temp;
    int age;

    inFile.open("infile");

    getline(inFile, name, ' '); // use ' ' as separator, default is '\n' (newline). Now name is "John".
    name.append(1,' ');
    cout << name;;
    getline(inFile, name, ' '); // use ' ' as separator, default is '\n' (newline). Now name is "John".
    name.append(1,' ');
    cout << name;

    getline(inFile, name, ' '); // use ' ' as separator, default is '\n' (newline). Now name is "John".
    name.append(1,' ');
    cout << name;
    //cout << age << endl;  

    inFile.close(); 


    return 0;
}