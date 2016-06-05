/* 
 * File:   contacts.hpp
 * Author: mayur
 *
 * Created on 4 June, 2016, 7:32 PM
 */

#ifndef CONTACTS_HPP
#define	CONTACTS_HPP

#include<set>

#include "trie.hpp"
using namespace std;


struct contact{
    string firstName;
    string lastName;
    struct contact *fnext;
    struct contact *lnext;
}typedef contact_t;

struct contactHead{
    struct contact *first;
}typedef contacthead_t;

contact_t* addContact(string firstName, string lastName);
void searchName(struct trie* root, string name, set<string>& results);

#endif	/* CONTACTS_HPP */

