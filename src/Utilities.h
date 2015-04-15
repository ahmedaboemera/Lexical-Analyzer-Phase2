
#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <vector>
#include <map>
#include "Parser.h"

using namespace std;


class Utilities{
	public:
		Utilities(Parser* p);
		map<string, vector<string> > compute_first(vector<string> non_terminal);
		map<string, vector<string> > compute_follow(vector<vector<vector<string> > > non_terminal_defs);
		vector<string> get_first(string non_terminal);
		void print(vector<string> firsts);

	private:
		Parser *parser;
		map<string, vector<string> > non_terminals_first;
		vector<string>::iterator vector_contains(vector<string>* vec, string str);
};


#endif UTILITIES_H_
