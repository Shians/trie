CC := g++
OPTS := -std=c++11 -g

.PHONY: example

prog: main.cpp trie.cpp
	$(CC) $(OPTS) -o $@ $^

example:
	./prog
