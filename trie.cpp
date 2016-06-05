#include <assert.h>
#include<iostream>
#include "trie.hpp"
#include "contactSanity.hpp"

using namespace std;
void initTrie(contactTrie* trie){
    for(int i = 0; i < NUMBER_CHILDREN; i++)
        trie->child[i] = NULL;
    trie->fcontact = NULL;
    trie->lcontact = NULL;
    trie->isLeafNode = false;
}

contactTrie* getTrieNode(void){
    contactTrie* newNode = new contactTrie;
    if(newNode){
        newNode->isLeafNode = false;
        for(int i = 0; i < NUMBER_CHILDREN; i++)
            newNode->child[i] = NULL;
        newNode->fcontact = NULL;
        newNode->lcontact = NULL;
    }
    return newNode;
}


int addStringToTrie(contactTrie* root, string str, struct contact *contactToInsert, bool first_name){
    int err = 0, inx;
    contactTrie* cur = root;
    contact_t* contactNode;
    //cout<<"In addStringToTrie with firstname : "<<contactToInsert->firstName<<" lastname : "<<contactToInsert->lastName<<endl;
    for(int i = 0; i < str.length(); i++){
        inx = CHAR_TO_INX(str[i]);
        if(!cur->child[inx]){
            cur->child[inx] = getTrieNode();
            if(!cur->child[inx])
                return ERR_ALLOCATION;
            cur = cur->child[inx];
        }else
            cur = cur->child[inx];
    }
    cur->isLeafNode = true;
    if(cur->fcontact == NULL && first_name)
        cur->fcontact = contactToInsert;
    else if(cur->lcontact == NULL && !first_name)
        cur->lcontact = contactToInsert;
    else{
        if(first_name){
            contactNode = cur->fcontact;
            while(contactNode->fnext != NULL)
                contactNode = contactNode->fnext;
            contactNode->fnext = contactToInsert;
        }else{
            contactNode = cur->lcontact;
            while(contactNode->lnext != NULL)
                contactNode = contactNode->lnext;
            contactNode->lnext = contactToInsert;
        }
    }
    return err;
}


void traverseTrie(contactTrie* root, set<string>& results){
    struct contact* contactNode;
    assert(!(root->isLeafNode && root->fcontact == NULL && root->lcontact == NULL));
    if(root->isLeafNode){
        contactNode = root->fcontact;
        while(contactNode){
            results.insert(contactNode->firstName + " " + contactNode->lastName);
            contactNode = contactNode->fnext;
        }
        contactNode = root->lcontact;
        while(contactNode){
            results.insert(contactNode->firstName + " " + contactNode->lastName);
            contactNode = contactNode->lnext;
        }
    }
    for(int i = 0; i < NUMBER_CHILDREN; i++){
        if(root->child[i])
            traverseTrie(root->child[i], results);
    }
}

void searchTrie(contactTrie* root, string name, set<string>& results){
    int inx = 0;
    contactTrie* cur = root;
    for(int i = 0; i < name.length(); i++){
        inx = CHAR_TO_INX(name[i]);
        if(!cur->child[inx])
            return;
        else
            cur = cur->child[inx];
    }
    traverseTrie(cur, results);
}