/*
 * Parser.h
 *
 *  Created on: 12 Apr 2015
 *      Author: ahmedaboemera
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

static vector<string> terminals;
static vector<string> non_terminals;
static vector<vector<vector<string> > >non_terminal_defs;

void get_terminals_and_nonterminals(vector<string>* lines);



#endif /* PARSER_H_ */
