#include "trie.hpp"


void initTrie(contactTrie* trie){
    for(int i = 0; i < NUMBER_CHILDREN; i++)
        trie->child[i] = NULL;
    trie->contactNode = NULL;
    trie->isLeafNode = false;
}


int addStringToTrie(string str, struct contact *contactToInsert, bool first_name){
    int err = 0;
    
    return err;
}
