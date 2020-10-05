#ifndef BOOK_H
#define BOOK_H
#include<string>
class Book{
	private:
	std::string m_language, m_condition;
	int m_isbn;
	public:
	Book(const int &isbn, const std::string& language, const std::string& condition);
	const int get_isbn();
	const std::string get_language();
	const std::string get_condition();
	void return_book_info();
};


#endif
