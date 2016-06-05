/* 
 * File:   main.cpp
 * Author: mayur
 *
 * Created on 4 June, 2016, 6:31 PM
 */

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include "trie.hpp"
#include "contacts.hpp"
#include "contactSanity.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int choice = 0;
    int err;
    char inp[100];
    string name, firstName, lastName;
    set<string> results;
    set<string>::iterator it;
    contactTrie* rootTrie = new contactTrie;
    contact_t* contactNode;
    initTrie(rootTrie);
    while(choice != 3){
        cout<<"1) Add contact 2) Search 3) Exit"<<endl;
        cin>>choice;
        cin.ignore(1024, '\n');
        switch(choice){
            case 1:
                cout<<"Enter name : ";
                cin.getline(inp, 100);
                name = inp;
                if(name.empty())
                    continue;
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                err = checkFormat(name);
                if(err != 0){
                    reportErr(err);
                    break;
                }
                splitName(name, firstName, lastName);
                contactNode = addContact(firstName, lastName);
                err = addStringToTrie(rootTrie, firstName, contactNode, true);
                if(!lastName.empty())
                    err = addStringToTrie(rootTrie, lastName, contactNode, false);
                break;
            case 2:
                cout<<"Enter name : ";
                cin.getline(inp, 100);
                name = inp;
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                err = checkFormat(name);
                splitName(name, firstName, lastName);
                results.clear();
                if(lastName.empty())
                    searchName(rootTrie, firstName, results);
                else{
                    searchName(rootTrie, firstName, results);
                    removeNonLastNames(results, lastName);
                }
                for(it=results.begin(); it != results.end(); ++it)
                    cout<<*it<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

