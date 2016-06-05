#include<string>
#include<set>

#include "contacts.hpp"
#include "trie.hpp"
using namespace std;

contact_t* addContact(string firstName, string lastName){
    contact_t *contactToInsert = new contact_t;
    contactToInsert->firstName = firstName;
    contactToInsert->lastName = lastName;
    contactToInsert->fnext = NULL;
    contactToInsert->lnext = NULL;
    return contactToInsert;
}

void searchName(contactTrie* root, string name, set<string>& results){
    if(name.empty()){
        results.clear();
        traverseTrie(root, results);
    }
    searchTrie(root, name, results);
}

string getLastNameFromString(string name){
    size_t pos;
    pos = name.find_first_of(" \t");
    string lastName = name.substr(pos+1, name.length() - pos);
    return lastName;
}

void removeNonLastNames(set<string>& results, string lastName){
    set<string>::iterator it;
    string fullLastName;
    for(it=results.begin(); it != results.end(); ++it){
        fullLastName = getLastNameFromString(*it);
        if(fullLastName.compare(0, lastName.size(), lastName))
            results.erase(it);
    }
}