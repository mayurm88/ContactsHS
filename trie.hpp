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
#define CHAR_TO_INX(ch) ((int)(ch) - (int)'a')


struct trie{
    struct trie* child[NUMBER_CHILDREN];
    struct contact *fcontact;
    struct contact *lcontact;
    bool isLeafNode;
}typedef contactTrie;

int addStringToTrie(contactTrie* root, string str, struct contact *contactToInsert, bool first_name);
void initTrieNode(contactTrie*);
void traverseTrie(contactTrie* root, set<string>& results);
void searchTrie(contactTrie* root, string name, set<string>& results);

#endif	/* TRIE_HPP */

