#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

class medicine{
	string type;
	string name;
	int produced_year=0;
public:
	medicine(){
		produced_year =0;
	}
	medicine(string new_name, string new_type, int new_produced_year)
	{
		name = new_name;
		type = new_type;
		produced_year = new_produced_year; 
	}

	string get_name() const{return name;}
	string get_type() const {return type;}
	int get_produced_year() const{return produced_year;}

	void set_name(string s){
		this->name  = s;
	}
	void set_type(string t){
		this->type = t;
	}
	void set_year(int y){
		this->produced_year = y;
	}

	~medicine(){ }

};

