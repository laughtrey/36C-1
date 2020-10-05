#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include"Book.h"
#include"splitstring.h"
std::vector<Book> parseList(std::string fileName);
int main(int argc, char *argv[]) {

	char search_type;

	if (argc < 3 || argc > 3){
		std::cerr << "Usage: " << ".SearchNewBooks <newBooks.dat> <request.dat> <result_file.dat>" << std::endl;

	return 1;
	}

	std::string books_file = argv[1];				//arg1 should be books
	std::string request_file = argv[2];				//arg2 should be requests
	std::vector<Book> newBooksList = parseList(books_file); 	//creating book objects and pushing them to the vector
	std::vector<Book> requests = parseList(request_file); 		//creating book objects and pushing them to the vector
		
	std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
	std::cin >> search_type;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	if(isdigit(search_type) == true){
		do{
		std::cerr << "Incorrect choice" << std::endl;
		std::cin >> search_type;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		}while(isdigit(search_type) == true);
	}
	do{
		std::cerr << "Incorrect choice" << std::endl;
		std::cin >> search_type;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		}while(search_type !='l' && search_type !='L' && search_type !='b' && search_type !='B');

	if(search_type == 'l' || search_type == 'L'){
		std::cout << "linear" << std::endl;
	}
	if(search_type == 'b' || search_type == 'B'){
		std::cout << "binary" << std::endl;
	}
/*
	for(auto i : newBooksList){
		std::cout << i.get_isbn() << std::endl;
}
	std::sort(newBooksList.begin(),newBooksList.end());

	for(auto i : newBooksList){
		std::cout << i.get_isbn() << std::endl;
}
*/
return 0;
}

std::vector<Book> parseList(std::string fileName){
	std::vector<Book> v;
	int isbn = 0;
	std::ifstream file(fileName.c_str());
	std::string line;
	while (std::getline(file, line)){
		splitstring input(line);
		std::vector<std::string> flds = input.split(',');	//Expected: [0] = ISBN, [1] = Language, [2] = Condition
		std::stringstream isbnstring(flds[0]);			//Cast the ISBN string to int
		isbnstring >> isbn;					//Cast the ISBN string to int 
		v.push_back(Book(isbn, flds[1], flds[2]));		//push the new book back into the vector
	}
	return v;
}
