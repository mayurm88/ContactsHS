/* 
 * File:   contactSanity.hpp
 * Author: mayur
 *
 * Created on 4 June, 2016, 9:45 PM
 */

#ifndef CONTACTSANITY_HPP
#define	CONTACTSANITY_HPP

#include <string>
using namespace std;

#define ERR_NONALPHA 1
#define ERR_TOOLONG 2
#define ERR_ALLOCATION 3


int doInputSanity(string name);
void reportErr(int err);
void splitName(string name, string& fName, string& lName);
string convertToOurFormat(string name);
string trimWhiteSpaces(string name);
string capitalize(string name);
#endif	/* CONTACTSANITY_HPP */

