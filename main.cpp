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
    string name, firstName, lastName, formatName;
    set<string> results;
    set<string>::iterator it;
    contactTrie* rootTrie = new contactTrie;
    contact_t* contactNode;
    initTrie(rootTrie);
    while(choice != 3){
        cout<<"1) Add contact 2) Search 3) Exit"<<endl;
        if(cin>>choice){
            cin.ignore(1024, '\n');
            switch(choice){
                case 1:
                    cout<<"Enter name : ";
                    cin.getline(inp, 100);
                    name = inp;
                    if(name.empty())
                        continue;
                    transform(name.begin(), name.end(), name.begin(), ::tolower);
                    err = doInputSanity(name);
                    if(err != 0){
                        reportErr(err);
                        break;
                    }
                    formatName = convertToOurFormat(name);
                    splitName(formatName, firstName, lastName);
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
                    if(name.empty()){
                        searchName(rootTrie, name, results);
                        break;
                    }
                    err = doInputSanity(name);
                    if(err != 0){
                        reportErr(err);
                        break;
                    }
                    formatName = convertToOurFormat(name);
                    splitName(formatName, firstName, lastName);
                    results.clear();
                    if(lastName.empty())
                        searchName(rootTrie, firstName, results);
                    else{
                        searchName(rootTrie, firstName, results);
                        removeNonLastNames(results, lastName);
                    }
                    if(results.empty())
                        cout<<"No matching results found."<<endl;
                    else
                        for(it=results.begin(); it != results.end(); ++it)
                            cout<<*it<<endl;
                    break;
                default:
                    break;
            }
        }else if(cin.bad()){
            cerr<<"Exiting.. Bad input."<<endl;
            cin.clear();
            exit(1);
        }else if(cin.eof()){
            cerr<<"Exiting.. Reached eof."<<endl;
            cin.clear();
            exit(1);
        }else{
            cerr<<"Exiting.. Format error."<<endl;
            cin.clear();
            exit(1);
        }
    }
    return 0;
}

