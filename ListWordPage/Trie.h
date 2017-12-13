/*
 * Tire.h
 *
 *  Created on: Dec 12, 2017
 *      Author: fanwu
 */

#ifndef TRIE_H_
#define TRIE_H_

#include <string>
#include <vector>

using namespace std;

class Trie
{
public:
	Trie() : head(new TrieNode()) {}

	~Trie() { delete head; }

	void addWord(const string &word, int page);

	vector<int> getPageInfo(const string &word);
private:
	struct TrieNode
	{
		TrieNode() { size = 26; next = vector<TrieNode *>(size, NULL); }
		~TrieNode();

		bool isTail() { return !pages.empty(); }

		void cleanNode(const TrieNode *root);

		vector<TrieNode *> next;
		vector<int> pages;
		int size;
	};

	TrieNode *head;
};


#endif /* TRIE_H_ */
