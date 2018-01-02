#include "trie.h"

using std::vector;
using std::string;

// initialise new trie node
node_ptr new_node() {
    node_ptr node{new struct node};
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = nullptr;
    }

    node->end_of_word = false;

    return node;
}

// traverse trie in alphabetical order
// print any full words encountered
void traverse_trie(node_ptr node, string str, vector<string> &words) {
    if (node->end_of_word) {
        words.push_back(str);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != nullptr) {
            char chr = i;
            traverse_trie(node->children[i], str + chr, words);
        }
    }
}

// get root of trie
node_ptr Trie::get_root() {
    return root;
}

// insert word into trie
void Trie::insert(std::string word) {
    node_ptr current = root;
    for (char c : word) {
        if (current->children[c] == nullptr) {
            current->children[c] = new_node();
        }
        current = current->children[c];
    }
    current->end_of_word = true;
}

// search if word in trie
bool Trie::search(std::string word) {
    node_ptr current = root;
    for (char c : word) {
        if (current->children[c] == nullptr) {
            return false;
        }
        current = current->children[c];
    }
    return current->end_of_word;
}

// print all stored words in alphabetical order
vector<string> Trie::stored_words() {
    vector<string> words;
    traverse_trie(root, "", words);
    return words;
}

// print all stored words with specified prefix
vector<string> Trie::with_prefix(std::string str) {
    node_ptr node = root;
    for (char c : str) {
        node = node->children[c];
    }
    vector<string> words;
    traverse_trie(node, str, words);
    return words;
}
