/* 
 * File:   trie.hpp
 * Author: mayur
 *
 * Created on 5 June, 2016, 2:53 PM
 */

#ifndef TRIE_HPP
#define	TRIE_HPP

#include <string>
#include "contacts.hpp"

using namespace std;
#define NUMBER_CHILDREN 26

struct trie{
    struct trie* child[NUMBER_CHILDREN];
    contact_t *contactNode;
    bool isLeafNode;
}typedef contactTrie;

int addStringToTrie(string str, struct contact *contactToInsert, bool first_name);
void initTrie(contactTrie*);

#endif	/* TRIE_HPP */

