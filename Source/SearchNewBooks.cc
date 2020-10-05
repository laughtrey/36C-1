#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Book.h"
#include"splitstring.h"
std::vector<Book> parseList(std::string fileName);
int main(int argc, char *argv[]) {
	if (argc < 3 || argc > 3){
		std::cerr << "Usage: " << argv[0] << " Booksfile Requestfile" << std::endl;

	return 1;
	}
	std::string books_file = argv[1];
	std::string request_file = argv[2];
	//std::cout << argv[0] << argv[1] << argv[2] << std::endl; //Test argument values 
	std::vector<Book> newBooksList = parseList(books_file);
	std::vector<Book> requests = parseList(request_file);
	//std::cout << requests[0].get_isbn() << std::endl;

return 0;
}
std::vector<Book> parseList(std::string fileName){
	std::vector<Book> v;
	int isbn = 0;
	std::ifstream file(fileName.c_str());
	std::string line;
	while (std::getline(file, line)){
		splitstring input(line);
		std::vector<std::string> flds = input.split(',');//Expected: [0] = ISBN, [1] = Language, [2] = Condition
		std::stringstream isbnstring(flds[0]);//Cast the ISBN string to int
		isbnstring >> isbn;//Cast the ISBN string to int 
		//std::cout << flds[0] << flds[1] << flds[2] << std::endl;
		v.push_back(Book(isbn, flds[1], flds[2]));//push the new book back into the vector
	}
	return v;
}
