#include <iostream>
#include "main.h"

using namespace std;

void print_string_vector(vector<string> strings) {
    for (string str : strings) {
        cout << str << "\n";
    }
}

int main(int argc, char *argv[]) {
    Trie trie;

    // insert some words
    trie.insert("argonaut");
    trie.insert("argues");
    trie.insert("delete");
    trie.insert("delta");
    trie.insert("hall");
    trie.insert("hallway");
    trie.insert("hellion");
    trie.insert("hello");

    // print words containing prefix h
    cout << "words beginning with h:" << "\n";
    print_string_vector(trie.with_prefix("h"));
    cout << "\n";

    // print words containing prefix he
    cout << "words beginning with he:" << "\n";
    print_string_vector(trie.with_prefix("he"));
    cout << "\n";

    // print words containing prefix bleh
    cout << "words beginning with bleh:" << "\n";
    print_string_vector(trie.with_prefix("bleh"));
    cout << "\n";

    // print all words
    cout << "all stored words:" << "\n";
    print_string_vector(trie.stored_words());
    cout << "\n";

    // search for strings
    cout << "search for strings:" << "\n";
    cout << "argonaut: " << (trie.search("argonaut") ? "found" : "not found") << "\n";
    cout << "anaconda: " << (trie.search("anaconda") ? "found" : "not found") << "\n";

    return 0;
}
