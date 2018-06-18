#include <iostream>
#include <vector>
#include <string>
#include <memory>

const int ALPHABET_SIZE = 128; // assume ascii alphabet

// trie node structure
struct node {
    node *children[ALPHABET_SIZE];
    bool end_of_word;
};

typedef node *node_ptr; // node pointer type

node_ptr new_node(); // initalise new node
void traverse_trie(node_ptr node, std::string str); // traverse tree depth and order first

class Trie {
public:
    Trie() {
        root = new_node();
    };

    node_ptr get_root(); // get root of trie
    void insert(std::string word); // insert word into trie
    bool search(std::string word); // search if trie contains word
    std::vector<std::string> stored_words(); // print stored words
    std::vector<std::string> with_prefix(std::string str); // print stored words having prefix

private:
    node_ptr root;
};
