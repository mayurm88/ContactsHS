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


int checkFormat(string name);
void reportErr(int err);
void splitName(string name, string& fName, string& lName);

#endif	/* CONTACTSANITY_HPP */

