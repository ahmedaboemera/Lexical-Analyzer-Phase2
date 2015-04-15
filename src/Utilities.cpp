
#include "Utilities.h"


//map<string, vector<string> > Utilities::non_terminals_first;



Utilities::Utilities(Parser* p){
	parser = p;
}


vector<string> Utilities::get_first(string non_terminal){

	vector<string> firsts;
	if(non_terminals_first.find(non_terminal)!=non_terminals_first.end())
		return non_terminals_first[non_terminal];

	vector<vector<string> > sop = parser->get_def(non_terminal);

	for(vector<vector<string> >::iterator mul_terms=sop.begin(); mul_terms!=sop.end(); mul_terms++){

		vector<string>::iterator term_it = mul_terms->begin();
		for(; term_it!=mul_terms->end(); term_it++){
			if(!parser->is_non_terminal(*term_it) || term_it->compare("\\L") == 0){
				firsts.push_back(*term_it);
				break;
			}else{
				vector<string> term_first = get_first(*term_it);
				vector<string>::iterator it = vector_contains(&term_first, "\\L");

				if(it != term_first.end()){
					term_first.erase(it);
					firsts.insert(firsts.end(), term_first.begin(), term_first.end());
				}else{
					firsts.insert(firsts.end(), term_first.begin(), term_first.end());
					break;
				}
			}
		}
		if(term_it == mul_terms->end() && vector_contains(&firsts, "\\L")==firsts.end())
			firsts.push_back("\\L");
	}
	non_terminals_first[non_terminal] = firsts;
	return firsts;
}



vector<string>::iterator Utilities::vector_contains(vector<string>* vec, string str){
	for(vector<string>::iterator s=vec->begin(); s!=vec->end(); s++){
		if(s->compare(str) == 0)
			return s;
	}
	return vec->end();
}


void Utilities::print(vector<string> firsts){
	cout<<"============================\n";
	for(vector<string>::iterator s=firsts.begin(); s!=firsts.end(); s++)
		cout<<"\t"<<*s<<"\n";
	cout<<"----------------------------\n";
	cout<<"\n";
}

