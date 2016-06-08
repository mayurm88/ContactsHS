#include<string>
#include<set>
#include <iostream>
#include "contacts.hpp"
#include "trie.hpp"
#include "contactSanity.hpp"
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
    /* If input name is empty, traverse the entire trie.
     * else
     * Search for the name in the trie.
     */
    if(name.empty()){
        results.clear();
        traverseTrie(root, results);
        return;
    }
    searchTrie(root, name, results);
}

string getLastNameFromString(string name){
    /* Given a string containing one/two words separated by a single tab or space,
     * this function returns the second word if there is any or else returns 
     * empty string.
     */
    size_t pos;
    pos = name.find_first_of(" \t");
    if(pos == string::npos)
        return "";
    string lastName = name.substr(pos+1, name.length() - pos);
    return lastName;
}

void removeNonLastNames(set<string>& results, string lastName){
    /* Remove all names from the result set whose last name does not start with
     * the input lastName parameter.
     */
    set<string>::iterator it;
    string fullLastName;
    for(it=results.begin(); it != results.end();){
        fullLastName = getLastNameFromString(*it);
        if(fullLastName.empty()){
            results.erase(it++);
            continue;
        }
        if(fullLastName.compare(0, lastName.size(), capitalize(lastName))){
            results.erase(it++);
            continue;
        }
        ++it;
    }
}