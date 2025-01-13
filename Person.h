#pragma once
//#include <iostream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdbool.h>
using namespace  std;
class Person
{
private:
	int _id;
	string  _name;

public:
	int getid();
	string getname();
	void setid(int id);
	void setname(string name);
	//Person& operator= (const Person& other);
	Person& operator=(Person other) noexcept // call copy or move constructor to construct other
	{
		this->_id = other._id;
		this->_name = other.getname();
	
		return *this;
	}



};

