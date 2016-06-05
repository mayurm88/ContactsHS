/* 
 * File:   trie.hpp
 * Author: mayur
 *
 * Created on 5 June, 2016, 2:53 PM
 */

#ifndef TRIE_HPP
#define	TRIE_HPP

#include "contacts.hpp"

#define NUMBER_CHILDREN 26

struct trie{
    char c;
    struct trie* child[NUMBER_CHILDREN];
    contact_t *contactNode;
    bool isLeafNode;
}typedef contactTrie;

#endif	/* TRIE_HPP */

