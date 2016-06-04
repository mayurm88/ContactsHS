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
#include "contacts.hpp"
#include "contactSanity.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int choice = 0;
    int err;
    char inp[51];
    string name;
    string results;
    while(choice != 3){
        cout<<"1) Add contact 2) Search 3) Exit"<<endl;
        cin>>choice;
        cin.ignore(256, '\n');
        switch(choice){
            case 1:
                cout<<"Enter name : ";
                cin.getline(inp, 50);
                name = inp;
                err = checkFormat(name);
                if(err != 0){
                    reportErr(err);
                    break;
                }
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                //cout<<"Lower name is : "<<name<<endl;
                err = addName(name);
                break;
            case 2:
                cout<<"Enter name : ";
                cin.getline(inp, 50);
                name = inp;
                results = searchName(name);
                break;
            default:
                break;
        }
    }
    return 0;
}

