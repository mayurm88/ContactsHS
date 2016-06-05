#include<string>
#include<iostream>

#include "contactSanity.hpp"

using namespace std;

int doInputSanity(string name){
    //Implement checking of input format
    size_t pos;
    pos = name.find_first_not_of("abcdefghijklmnopqrstuvwxyz \t");
    if(pos != string::npos)
        return ERR_NONALPHA;
    if (name.length() > 50)
        return ERR_TOOLONG;
    return 0;
}

string trimWhiteSpaces(string name){
    size_t pos;
    pos = name.find_first_not_of(" \t");
    size_t posEnd = name.find_last_not_of(" \t");
    return name.substr(pos, posEnd+1);
}

 string convertToOurFormat(string name){
     string trimmedName = trimWhiteSpaces(name);
     size_t pos = trimmedName.find_first_of(" \t");
     if(pos == string::npos)
         return trimmedName;
     string firstName = trimmedName.substr(0, pos);
     trimmedName.erase(0, pos+1);
     pos = trimmedName.find_first_not_of(" \t");
     trimmedName.erase(0, pos);
     /* Searching for the third word if there is one.
      */
     pos = trimmedName.find_first_of(" \t");
     if(pos == string::npos)
         return firstName + " " + trimmedName;
     string lastName = trimmedName.substr(0, pos);
     return firstName + " " + lastName;
 }


void splitName(string name, string& fName, string& lName){
    
    /*
     * Assumes name is made of only one/two words separated by a space or a tab.
     * Copies the first word of name in fName and second word of name in lName.
     * 
     * If name is only one word, last name is set to empty string
     * and first name is set to name.
     */
    size_t pos;
    pos = name.find_first_of(" \t");
    if(pos == string::npos){
        fName = name;
        lName = "";
        return;
    }
    fName = name.substr(0, pos);
    lName = name.substr(pos + 1, name.length() - (pos+1));
    return;
}

void reportErr(int err){
    //Implement error reporting.
    switch(err){
        case ERR_NONALPHA:
            cerr<<"Only Alphabets and spaces allowed. Please try again."<<endl;
            break;
        case ERR_TOOLONG:
            cerr<<"Name too long. Only 50 character names allowed. Please try again."<<endl;
            break;
    }
}

string capitalize(string name){
    name[0] = toupper(name[0]);
    return name;
}