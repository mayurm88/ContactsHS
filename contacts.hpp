/* 
 * File:   contacts.hpp
 * Author: mayur
 *
 * Created on 4 June, 2016, 7:32 PM
 */

#ifndef CONTACTS_HPP
#define	CONTACTS_HPP

using namespace std;

int addName(string name);
string searchName(string name);


struct contact{
    string firstName;
    string lastName;
    int visited;
    struct contact *next;
}typedef contact_t;

struct contactHead{
    struct contact *first;
}typedef contacthead_t;

#endif	/* CONTACTS_HPP */

