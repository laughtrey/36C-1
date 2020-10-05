#include "Book.h"

Book::Book(const int &isbn, const std::string& language, const std::string& condition){
	m_isbn = isbn;
	m_language = language;
	m_condition = condition;
}
int Book::get_isbn() const {
	return m_isbn;
}
std::string Book::get_language() const {
	return m_language;
}
std::string Book::get_condition() const {
	return m_condition;
}
bool Book::operator< (const Book& b) const{
	if (get_isbn() == b.get_isbn()) {
		return (get_language() > b.get_language());
	}
	else{
		return (get_isbn() < b.get_isbn());
	}
}
