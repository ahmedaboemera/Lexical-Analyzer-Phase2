/*
 * Eliminator.cpp
 *
 *  Created on: 12 Apr 2015
 *      Author: ahmedaboemera
 */
#include "Parser.h"


int find_index(string s){
	for(int i = 0 ;i < non_terminals.size(); i++){
		if(s.compare(non_terminals.at(i)) == 0 ){
			return i;
		}
	}
	return (1<<31-1);
}

vector<vector<string > > replace(int i){

	vector<vector<string> > updated;

	for(int j = 0 ; j < non_terminal_defs.at(i).size(); j++){
		if(non_terminal_defs.at(i).at(j).at(0).compare(non_terminals.at(i))!=0){
			int index = find_index(non_terminal_defs.at(i).at(j).at(0));
			if(index < i){
				for(int k = 0; k <non_terminal_defs.at(index).size() ;k++){
					vector<string> vec2;
//					vec.push_back(non_terminal_defs.at(index).at(k));
					for(int z = 0; z < non_terminal_defs.at(index).at(k).size(); z++){
						vec2.push_back(non_terminal_defs.at(index).at(k).at(z));
					}

					for(int z = 0 ; z < non_terminal_defs.at(i).at(j).size(); z++){
						vec2.push_back(non_terminal_defs.at(i).at(j).at(z));
					}
					updated.push_back(vec2);
				}

			}else{
				updated.push_back(non_terminal_defs.at(i).at(j));
			}
		}else{
			updated.push_back(non_terminal_defs.at(i).at(j));
		}
	}

	return updated;
}

void eliminate_LF() {

}

void eliminate_from_updated(vector<vector<string> > replaced, int i){

}

void eliminate_LR() {


	for(int i = 0; i < non_terminals.size(); i++){
		vector<vector <string> > updated = replace(i);
		eliminate_from_updated(updated, i);
	}

}

