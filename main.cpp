/* 
 * File:   main.cpp
 * Author: mayur
 * 
 * About: 
 *  A simple add and search contact application.
 *  A contact is defined as <firstname lastname> and has maximum length 50.
 *  You can add any contact with the above format and it will be searchable in the application.
 * 
 * Assumptions:
 *  1) If you add/search a name which has more than two words, only the first two words will be taken into
 *     consideration.
 *  2) The application is case insensitive. No matter what case you add your contacts in,
 *     search will always display names in Proper Case.
 *  For erratic inputs, the program will exit.
 *  For special characters in the name, program will throw an error.
 *  
 *
 * Created on 4 June, 2016, 6:31 PM
 */

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include "trie.hpp"
#include "contacts.hpp"
#include "contactSanity.hpp"

using namespace std;

/*
 * 
 */

contactTrie* rootTrie;

void addContact(string name){
    int err = 0;
    string formatName, firstName, lastName;
    contact_t* contactNode;
    if(name.empty())
        return;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    err = doInputSanity(name);
    if (err != 0) {
        reportErr(err);
        return;
    }
    formatName = convertToOurFormat(name);
    splitName(formatName, firstName, lastName);
    contactNode = addContact(firstName, lastName);
    err = addStringToTrie(rootTrie, firstName, contactNode, true);
    if (!lastName.empty())
        err = addStringToTrie(rootTrie, lastName, contactNode, false);

}

void searchAndDisplay(string name){
    int err = 0;
    set<string> results;
    set<string>::iterator it;
    string firstName, lastName, formatName;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (name.empty()) {
        searchName(rootTrie, name, results);
        return;
    }
    err = doInputSanity(name);
    if (err != 0) {
        reportErr(err);
        return;
    }
    formatName = convertToOurFormat(name);
    splitName(formatName, firstName, lastName);
    results.clear();
    if (lastName.empty())
        searchName(rootTrie, firstName, results);
    else {
        searchName(rootTrie, firstName, results);
        removeNonLastNames(results, lastName);
    }
    if (results.empty())
        cout << "No matching results found." << endl;
    else
        for (it = results.begin(); it != results.end(); ++it)
            cout << *it << endl;
    
}


void runInputLoop(){
    int choice = 0;
    char inp[100];
    string name;
    rootTrie = new contactTrie;
    initTrieNode(rootTrie);
    
    while(choice != 3){
        cout<<"1) Add contact 2) Search 3) Exit"<<endl;
        if(cin>>choice){
            cin.ignore(1024, '\n');
            switch(choice){
                case 1:
                    cout<<"Enter name : ";
                    cin.getline(inp, 100);
                    if(cin.good()){
                        name = inp;
                        addContact(name);
                    }else{
                        cerr<<"Bad input. Please try again."<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    break;
                case 2:
                    cout<<"Enter name : ";
                    cin.getline(inp, 100);
                    if(cin.good()){
                        name = inp;
                        searchAndDisplay(name);
                    }else{
                        cerr<<"Bad input. Please try again."<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    break;
                default:
                    break;
            }
        }else if(cin.bad()){
            cerr<<"Bad input. Please try again"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }else if(cin.eof()){
            cerr<<"Got EOF. Exiting."<<endl;
            exit(0);
        }else{
            cerr<<"Format error. Please try again."<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

int main(int argc, char** argv) {    
    runInputLoop();
    return 0;
}

