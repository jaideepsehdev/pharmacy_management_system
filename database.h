#include "code.h"

class database{
	int size_ ;
	int cap;
	medicine* data;
public:
	~database(){
		delete[] data;
	}
	//constructor for initilasing values and making array of type medicine
	database(){
		size_ = 0;
		cap =10;
		data = new medicine[cap];
	}
	//copy constructor in case we need it
	database(const database& other){
		size_ = other.size_;
		cap = other.cap;

		medicine* newarr = new medicine[other.cap];
		for(int i=0;i<other.cap;i++){
			newarr[i] = other.data[i];
		}

		data = newarr;
	}

	string get (int i) const{
		
		return data[i].get_name();
	}

	
	//append function
	void append(const medicine& med){
		if (size_>=cap){
			cap *= 2;
			medicine* newarr = new medicine[cap];
			for (int i=0;i<size_;i++){
				newarr[i] = data[i];
			} 
			delete[] data;
			data = newarr;
			data[size_++] = med;
		}
		else
			data[size_++] = med;
	}
	//ALL THE SEARCH FUNCTIONS
	void search_byname(string name){
		for(int i=0;i<name.size();i++){
			name[i] = tolower(name[i]);
		}

		int found =0;
		for(int i=0;i<size_;i++){
			if(data[i].get_name() == name){
				cout << "Medicine found: \n";
				cout << data[i].get_name()<<" "<<data[i].get_type()<<" "<<data[i].get_produced_year();
				cout <<endl;
				found++;
			}
		}
		if(found == 0){
			cout << "No medicine found by the name of "<< name<<endl;
		}
	}

	void search_bytype(string type){
		for(int i=0;i<type.size();i++){
			type[i] = tolower(type[i]);
		}

		int found =0;
		for(int i=0;i<size_;i++){
			if(data[i].get_type() == type){
				cout << "Medicine found: \n";
				cout << data[i].get_name()<<" "<<data[i].get_type()<<" "<<data[i].get_produced_year();
				cout <<endl;
				found++;
			}
		}
		if(found == 0){
			cout << "No medicine found by the type "<< type<<endl;
		}
	}

	void search_byyear(string year){
		for(int i=0;i<year.length();i++){
			while(!(isdigit(year[i])) ||
					stoi(year)<0 ||
					stoi(year) > 2021)
				{
					cout <<"Enter the year again"<<endl;
					cout << "\nEnter the production year: ";
					if(cin.peek()=='\n')cin.ignore();
					getline(cin,year);
				}
		}
		int found =0;
		for(int i=0;i<size_;i++){
			if(data[i].get_produced_year() == stoi(year)){
				cout << "Medicine found: \n";
				cout << data[i].get_name()<<" "<<data[i].get_type()<<" "<<data[i].get_produced_year();
				cout <<endl;
				found++;
			}	
		}
		if(found ==0){
			cout <<"No medicine found by the year " << stoi(year) <<endl;
		}
	}


	int get_index_for_yr (int year){
		for(int i=0;i<size_;i++){
			if(data[i].get_produced_year()==year){
				return i;
			}
		}
		return 0;
	}
	


	void search_by_range_yr(string min_yr, string max_yr){
		int ind=get_index_for_yr(stoi(min_yr));
		sort_year();
		for(int i=0;i<size_;i++){
			if(data[ind].get_produced_year()==stoi(min_yr)){
				while (data[ind].get_produced_year()<=stoi(max_yr)){
					cout << data[ind].get_name()<<" "<<data[ind].get_type()<<" "<<data[ind].get_produced_year();
					cout <<endl;
					ind++;
				}
			}

		}
	
	}




	//SORT FUNCTIONS
	void sort_name(){
		for (int i=1;i<size_;i++){
			int j =i;
			while(j>0 && data[j].get_name() < data[j-1].get_name()){
				swap(data[j-1],data[j]);
				--j;
			}

		}
	}

	void sort_type(){
		for (int i=1;i<size_;i++){
			int j =i;
			while(j>0 && data[j].get_type() < data[j-1].get_type()){
				swap(data[j-1],data[j]);
				--j;
			}

		}
	}

	void sort_year(){
		for (int i=1;i<size_;i++){
			int j =i;
			while(j>0 && data[j].get_produced_year() < data[j-1].get_produced_year()){
				swap(data[j-1],data[j]);
				--j;
			}

		}
	}

	void reverse(){
		int first = 0;
		int last = size_-1;
		while(first<last){
			medicine temp = data[first]; //took help from https://www.youtube.com/watch?v=WI54wvu0_4E 
			data[first] = data[last];//in understanding the concept behind reversing an array
			data[last] = temp;
			first++;
			last--;
		}
	}


	//displays all the records stored in class array 
	void display_all(){
		for(int i=0;i<size_;i++){
			cout << data[i].get_name() <<" "<< data[i].get_type()<<" "<<data[i].get_produced_year()<<endl;
		}
	}

	//DELETE FUNCTIONS
	void delete_medicine_byname(string name){
		for(int i=0;i<name.size();i++){
			name[i] = tolower(name[i]);
		}

		int found;
		for(int i=0;i<size_;i++){
			if(data[i].get_name() == name){
				found++;
				string get;
				cout << "Are you sure you want to delete this record(y/n): \n";
				cout << data[i].get_name()<<" "<<data[i].get_type()<<" "<<data[i].get_produced_year();
				cout <<endl;
				if(cin.peek()=='\n')cin.ignore();
				getline(cin,get);
				if(get == "y" || get == "Y"){
					data[i] = data[size_-1];
					size_ --;
				}
				else if(get =="n" || get=="N"){
					break;
				}
			}
		}
		if(found == 0)
			cout << "This record doesn't exist\n";
	}

	void delete_medicine_bytype(string type){
		for(int i=0;i<type.size();i++){
			type[i] = tolower(type[i]);
		}

		int found;
		for(int i=0;i<size_;i++){
			if(data[i].get_type() == type){
				found++;
				string get;
				cout << "Are you sure you want to delete this record(y/n): \n";
				cout << data[i].get_name()<<" "<<data[i].get_type()<<" "<<data[i].get_produced_year();
				cout <<endl;
				if(cin.peek()=='\n')cin.ignore();
				getline(cin,get);
				if(get == "y" || get == "Y"){
					data[i] = data[size_-1];
					size_ --;
				}
				else if(get =="n" || get=="N"){
					break;
				}
			}
		}
		if(found == 0)
			cout << "This record doesn't exist\n";
	}

	void delete_medicine_byyear(string year){
		for(int i=0;i<year.length();i++){
			while(!(isdigit(year[i])) ||
					stoi(year)<0 ||
					stoi(year) > 2021)
				{
					cout <<"Enter the year again"<<endl;
					cout << "\nEnter the production year: ";
					cin >> year;
				}
		}

		for(int i=0;i<size_;i++){
			if(data[i].get_produced_year() == stoi(year)){
				data[i] = data[size_-1];
				size_--;
			}
		}
	}

	void delete_all(){
		size_ =0;
	}
	
	//updates the text file with the contents of data array once the user quits the program
	void update_file(){
		fstream fin;
		fin.open("pharmacy.txt");
		for(int i=0;i<size_-1;i++){
			fin << data[i].get_name()<<" " << data[i].get_type()<<" "<<data[i].get_produced_year();
			fin << endl;
		}
		fin.close();
	}


	
	void read_from_file(const string& filename){
		string name_file;
		string type_file;  // making temporary variables to read from the file
		int year_file;
		medicine tmp;
		fstream fin;    //file object
		fin.open(filename);  
		while(fin >> name_file >> type_file >> year_file){  //reading from file excluding spaces
			tmp.set_name(name_file);  // setting temp class object to different values
			tmp.set_type(type_file);
			tmp.set_year(year_file);
			append(tmp);  //appending to the database array 
			  //to display and test the function
		}
		fin.close();
	}
	
	//helper function to ask the user about the fields  
	medicine ask(){
		medicine med;
		string temp_name;
		string temp_type;
		string temp_year;
		cout << "Enter the medicine name: ";
		if(cin.peek() == '\n')cin.ignore();
		getline(cin,temp_name);

		for(int i=0;i<size_;i++){
			if(data[i].get_name() == temp_name){
				cout << "Medicine by this name already exists!!"<<endl;
				cout <<"Enter medicine name again: ";
				getline(cin,temp_name);
			}
		}

		cout << "\nEnter the medicine type: ";
		if(cin.peek() == '\n')cin.ignore();

		getline(cin,temp_type);

		cout << "\nEnter the production year: ";
		if(cin.peek() == '\n')cin.ignore();
		getline(cin,temp_year);

		for(int i=0;i<temp_year.length();i++){
			while(!(isdigit(temp_year[i])) ||
					stoi(temp_year)<0 ||
					stoi(temp_year) > 2021)
				{
					cout <<"Enter the year again"<<endl;
					cout << "\nEnter the production year: ";
					cin >> temp_year;
				}
		}
		
		med.set_name(temp_name);
		med.set_type(temp_type);
		med.set_year(stoi(temp_year));

		return med;
	}

};