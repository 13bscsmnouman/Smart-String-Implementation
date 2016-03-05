/*
Muhammad Nouman Ahmad
Reg 5265
BSCS-3B
*/



#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;


class StringBuffer
{
public:
	StringBuffer() // //default constructor
	{
		_length = 0;
		//cout<<" Constructor 1 Called   "<<endl;
		_strbuf = NULL;
	};


	~StringBuffer()              //destructor; would delete the allocated buffer
	{
		if (_strbuf != NULL)
		{
			delete[] _strbuf;
			_strbuf = NULL;
		}
	}


	StringBuffer(const StringBuffer&);              //constructor for shallow copying


	StringBuffer(char* str, int len)    ////constructor to convert a char* to StringBuffer
	{
		_length = len;
		//cout<<" Hey i am caled 2   "<<endl;
		_strbuf = new char[_length];
		strcpy(_strbuf, str);
	};
	char charAt(int at) const   //returns the character at the passed index
	{
		return _strbuf[at];
	}

	int length() const                            //returns the length of the buffer
	{
		return _length;
	}
	void reserve(int len)                            //allocates memory for the string, according to the passed character length
	{
		char* temp = new char[_length];

		strcpy(temp, _strbuf);

		_strbuf = new char[_length + len];
		strcpy(_strbuf, temp);
		_length = _length + len;
		delete[] temp;
		temp = NULL;
	}
	void append(char ch)                          //appends a single character at the end
	{
		reserve(1);
		_strbuf[_length - 1] = ch;
		_strbuf[_length] = '\0';
	}

	void print()
	{
		cout << _strbuf << endl;
	}
private:
	char* _strbuf;                                   //buffer to store the original string
	int _length;                                       //length of the string
};




int main(int argc, char *argv[])
{
	StringBuffer my((char *)"aaaaaaaaaaaaaaa              a", 30);
	cout << "Initial String is :";
	my.print();
	cout << "Appending a charatcer X" << endl;
	my.append('X');
	cout << "New String is :    ";
	my.print();
	cout << "Character at index 5 is  :   ";
	cout << my.charAt(5) << endl;
	//StringBuffer my2((char *)"NNN",3);
	//my2.print();
	//my.print();
	return 0;
}

