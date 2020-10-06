#ifndef BOOK_H
#define BOOK_H
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"splitstring.h"
class Book{
	private:
	std::string m_language, m_condition;
	int m_isbn;
	int member_test_data;
	public:
	Book(const int &isbn, const std::string& language, const std::string& condition);
	int get_isbn() const;
	std::string get_language() const;
	std::string get_condition() const;
	static std::vector<Book> parseList(std::string fileName);
	bool operator< (const Book& b) const;
};
#endif
