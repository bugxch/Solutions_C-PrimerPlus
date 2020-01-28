#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person
{
private:
    enum { LIMIT = 25 };
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = "", fname[0] = '\0'; }
	Person(const std::string ln, const char* fn = "Heyyou");
	void show() const;
	void FormalShow() const;
};
#endif // !PERSON_H_