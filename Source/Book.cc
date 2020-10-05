#include "Book.h"

Book::Book(const int &isbn, const std::string& language, const std::string& condition){
	m_isbn = isbn;
	m_language = language;
	m_condition = condition;
}
const int Book::get_isbn(){
	return m_isbn;
}
const std::string Book::get_language(){
	return m_language;
}
const std::string Book::get_condition(){
	return m_condition;
}
