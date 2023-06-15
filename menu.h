#include "database.h"

class Menu{
	
public:
	Menu(){ }

	int menu_display(){
		int choice;
		cout << "1. Add new_medicine." << endl;
		cout << "2. Search for medicine." << endl;
		cout << "3. Display all medicines records." << endl;
		cout << "4. Remove medicine from database." << endl;
		cout << "5. Quit" << endl;
		cin >> choice;
		return choice;

	}

	int delete_menu(){
		int choice;
		cout << "1. Delete medicine by name."<<endl;
		cout << "2. Delete medicine by type." << endl;
		cout << "3. Delete medicine by year." <<endl;
		cin >> choice;
		return choice;
	}


	int search_menu(){
		int choice;
		cout << "1. Search for medicine by name"<<endl;
		cout << "2. Search for medicine by type"<<endl;
		cout << "3. Search for medicine by year"<<endl;
		cout << "4. Search for medicine by year(Sorted)"<<endl;
		cout << "5. Search for medicine by range of the year"<<endl;
		cout << "6. Return back to the menu"<<endl;
		cin >> choice;
		return choice;
	}

	int display_type_menu(){
		int choice;
		cout << "1. Display by name(alphabetical order)."<<endl;
		cout << "2. Display by descending name(reverse alphabetical order)."<<endl;
		cout << "3. Display by type(alphabetical order)."<<endl;
		cout << "4. Display by type (reverse alphabetical order)."<<endl;
		cout << "5. Display by ascending year." <<endl;
		cout << "6. Display by descending year."<<endl;
		cin >>choice;
		return choice;
	}

	void main_menu(){
		int userchoice=0;
		database db;
		medicine med;
		db.read_from_file("pharmacy.txt");
		while(userchoice!=5){
			userchoice = menu_display();
			switch (userchoice)
			{
				case 1:{
					med =db.ask();
					db.append(med);
					//db.add();
					db.display_all();
					break;
				}
				case 2:{
					int choice=0;
					choice = search_menu();
					switch(choice){
						case 1:{
							system("clear");
							string name;
							cout << "Enter the name of the medicine: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,name);
							for(int i=0;i<name.size();i++){
								name[i] = tolower(name[i]);
							}
							db.search_byname(name);
							break;
						}
						case 2:{
							system("clear");
							string type;
							cout << "Enter the type of the medicine: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,type);
							for(int i=0;i<type.size();i++){
								type[i] = tolower(type[i]);
							}
							db.search_bytype(type);
							break;
						}
						case 3:{
							system("clear");
							string year;
							cout <<"Enter the year of the medicine: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,year);
							db.search_byyear(year);
							break;
						}
						case 4:{
							system("clear");
							string year;
							cout <<"Enter the year of the medicine: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,year);
							db.sort_year();
							db.search_byyear(year);
							break;
						}
						case 5:{
							system("clear");
							string min_year;
							string max_year;
							cout <<"Enter the start of the year of the medicine: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,min_year);
							db.search_byyear(min_year);
							cout <<"Enter the end of the year of the medicine: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,max_year);
							db.search_byyear(max_year);
							cout << "\n-------List of medicines:-------\n";
							db.search_by_range_yr(min_year, max_year);
							cout << "\n";
							break;
						}
						case 6:{
							system("clear");
							break;
						}
					}
					break;
				}
				case 3:{
					int choice=0;
					choice = display_type_menu();
					switch(choice){
						case 1:{
							system("clear");
							db.sort_name();
							db.display_all();
							break;
						}
						case 2:{
							system("clear");
							db.sort_name();
							db.reverse();
							db.display_all();
							break;
						}
						case 3:{
							system("clear");
							db.sort_type();
							db.display_all();
							break;
						}
						case 4:{
							system("clear");
							db.sort_type();
							db.reverse();
							db.display_all();
							break;
						}
						case 5:{
							system("clear");
							db.sort_year();
							db.display_all();
							break;
						}
						case 6:{
							system("clear");
							db.sort_year();
							db.reverse();
							db.display_all();
							break;
						}

					}
					break;
					
				}
				case 4:{
					int choice=0;
					choice = delete_menu();
					switch(choice){
						case 1:{
							system("clear");
							string med_name;
							cout << "Enter the name of the medicine to delete: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,med_name);
							db.delete_medicine_byname(med_name);
							db.display_all();
							break;
						}
						case 2:{
							system("clear");
							string med_type;
							cout << "Enter the type of the medicine to delete: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,med_type);
							db.delete_medicine_bytype(med_type);
							db.display_all();
							break;
						}
						case 3:{
							system("clear");
							string year;
							cout << "Enter the year of the medicine you want to delete: ";
							if(cin.peek() == '\n')cin.ignore();
							getline(cin,year);
							db.delete_medicine_byyear(year);
							db.display_all();
							break;
						}
					}
					break;
				}
				case 5:{
					db.update_file();
					break;
				}
				default:{
					system("clear");
					cout <<"Please enter a valid input\n";
					break;
				}
			}
		}
	}





	~Menu(){ };
};