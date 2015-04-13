
#include "Parser.h"

string trim(string s) {
	string ans = "";
	for (unsigned int i = 0; i < strlen(&s[0]); i++) {
		if (s[i] != ' ') {
			ans += s[i];
		}
	}
	return ans;
}

string get_nonterminal(string s) {
	string x;
	for (unsigned int i = 2; s[i] != ' '; i++) {
		x += s[i];
	}
	return x;
}

vector<string>* get_terminals(string s) {
	vector<string>* x = new vector<string>();
	string to_add;
	bool add = 0;
	for (unsigned int i = 0; i < strlen(&s[0]); i++) {

		if (!add) {
			if ((int) s[i] == -104) {
				add = 1;
			}
		} else {
			if ((int) s[i] == -103 | (int) s[i] == -104) {
				add = false;
				x->push_back(trim(to_add));
				to_add = "";
			} else {
				if (s[i] == -104) {
					to_add += '‘';
				} else {
					to_add += ((int) s[i] < 0 ? ' ' : s[i]);
				}
			}
		}
	}
	x->push_back(trim(to_add));
	return x;
}


int get_eq(string s){
	int i =0;
	for (; s[i] != '='; i++);
	return i;
}

vector<string> split(string s, int start, char regex){
	int begin = start, end = start;
	vector<string> vec;

	for (int i = start; i < (strlen(&s[0])); i++) {
		if(s[i] == regex){
			end = i;
			string x = s.substr(start, end-start);
			vec.push_back(x);
			start = end+1;
			end =start;
		}
	}
	vec.push_back(s.substr(start, strlen(&s[0])-start));

	return vec;
}

void finalize(vector<vector<string> > non_t_defs){
	for(int i = 0; i < non_t_defs.size(); i++){
		vector<vector<string> > x;
		for(int j = 0; j < non_t_defs.at(i).size(); j++){
			x.push_back(split(non_t_defs.at(i).at(j), 0,' '));
		}
		non_terminal_defs.push_back(x);
	}
}

void fill_map(vector<string>* lines){
	vector<vector<string> > non_t_defs;
	for(vector<string>::iterator it = lines->begin(); it != lines->end(); it++){
		int equal = get_eq(*it);
		vector<string> returned = split(*it,equal+1,'|');
		non_t_defs.push_back(returned);
	}
	finalize(non_t_defs);
}

void get_terminals_and_nonterminals(vector<string>* lines) {
	for (vector<string>::iterator it = lines->begin(); it != lines->end();
			it++) {
		string x = get_nonterminal(*it);
		non_terminals.push_back(x);
		vector<string>* y = get_terminals(*it);
		for (vector<string>::iterator it = y->begin(); it != y->end(); it++) {
			non_terminals.push_back((*it));
		}
	}

	fill_map(lines);
}

