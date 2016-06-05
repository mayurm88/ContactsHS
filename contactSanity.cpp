#include<string>
#include<iostream>

#include "contactSanity.hpp"

using namespace std;

int checkFormat(string name){
    //Implement checking of input format
    size_t pos;
    pos = name.find_first_not_of("abcdefghijklmnopqrstuvwxyz \t");
    if(pos != string::npos)
        return ERR_NONALPHA;
    if (name.length() > 50)
        return ERR_TOOLONG;
    
    
    return 0;
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
    pos = name.find_first_not_of(" \t");
    size_t posEnd = name.find_last_not_of(" \t");
    string trimmedName = name.substr(pos, posEnd+1);
    
    pos = trimmedName.find_first_of(" \t");
    if(pos == string::npos){
        fName = name;
        lName = "";
        return;
    }
    fName = trimmedName.substr(0, pos);
    trimmedName.erase(0, pos+1);
    //cout<<"After first name erase trimmedName is : "<<trimmedName<<endl;
    pos = trimmedName.find_first_not_of(" \t");
    if(pos == string::npos)
        lName = "";
    else
        lName = trimmedName.substr(pos, trimmedName.length());
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