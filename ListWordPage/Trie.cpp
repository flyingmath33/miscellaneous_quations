/*
 * Trie.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: fanwu
 */

#include "Trie.h"

using namespace std;

Trie::TrieNode::~TrieNode() {}

void Trie::TrieNode::cleanNode(const TrieNode *root)
{
	for(int i = 1; i < size; ++i)
	{
		if(root->next[i])
		{
			if(!root->next[i]->isTail())
				cleanNode(root->next[i]);

			delete root->next[i];
		}
	}
}

void Trie::addWord(const string &word, int page)
{
	TrieNode *cur = head;
	for(int i = 0; i < (int)word.size(); ++i)
	{
		int index = word[i] - 'a';
		if(cur->next[index] == NULL)
			cur->next[index] = new TrieNode();

		if(i == int(word.size()) - 1)
			cur->next[index]->pages.push_back(page);

		cur = cur->next[index];
	}
}

vector<int> Trie::getPageInfo(const string &word)
{
	vector<int> res;

	TrieNode *cur = head;
	for(int i = 0; i < (int)word.size(); ++i)
	{
		int index = word[i] - 'a';
		if(cur->next[index] == NULL)
			break;

		if(i == (int)word.size() - 1)
			res = cur->next[index]->pages;

		cur = cur->next[index];
	}

	return res;
}
