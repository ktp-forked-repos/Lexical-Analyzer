// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
using namespace std;




int  isKeyword(string str);
int  isOp(string str);
void isDel(string str);
void isID(string str);
void isNum(const string& s);

char   op[]        = { '=','+','-','!','/','*',':','^','>','<' };
char   del[]       = { '{','}','(',')','[',']',';','#','&' };
char   logic[]     = { '<','>','=','>','=' };
string keyWord[]   = { "begin","end","int","if","else" };


int main()
{

	string str = ("begin x : = x + 1;end");
	//string str("else if(isKeyword(a))5g");

	regex reg("\\s");
	sregex_token_iterator iter(str.begin(), str.end(), reg, -1);
	sregex_token_iterator end;
	vector<string> vec(iter, end);

	int i = 0;
	for (auto a : vec)
	{
		isOp(a);
		isKeyword(a);
		isDel(a);
		isNum(a);
		isID(a);
	}
	_getch();
    return 0;
}

int isOp(string str) {
	int a = false;
	for (int i = 0; i < str.length(); i++)
	{
		a = false;
		for (int k = 0; k < 10; k++)
		{
			if ( str[i] == op[k])
			{
				for (int j = 0; j < 5; j++)
				{
					if (str[i+1] != '\0' && str[i+1] == logic[j] )
					{
						cout << str[i] << str[i+1] << "		id	=	logical op" <<endl;
						a = true;
						break;
					}
				}
				if (!a)
				{
					cout << str[i] << "		id	=	operator" << endl;
				}
			}
		}
	}
	return a;
}

int isKeyword(string str) {
	string temp = "";
	bool a = false;
	bool t = false;
	for (int i = 0; i < 5; i++)
	{
		if (str == keyWord[i])
		{
			cout << str << endl;
			cout << str << "		id	=	KeyWord" <<i<< endl;
			return 1;
			break;
		}
		string temp = "";
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '(' || str[j] == '{' || str[j] == ' ')
			{
				for (int k = 0; k < j; k++)
				{
					temp += str[k];
				}
				t = true;
				break;
			}
		}
		if (t)
		{
			if (temp == keyWord[i])
			{
				a = true;
				cout << temp << "		id	=	KeyWord" << endl;
				return 1;
			}
		}
		if (str == keyWord[i])
		{
			a = true;
			cout << str;
			return 1;
		}
	}
	return 0;
}

void isDel(const string str) {
	bool a = false;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (str[i] == del[j])
			{
				cout << str[i] << "		id	=	del" <<endl;
			}
		}
	}
}

void isNum(const string& str) {
	string temp = "";
	for (int i = 0; i < str.length()+1; i++)
	{
		if (str[i] > 47 && str[i] < 58)
		{
			temp += str[i];
		}
		if (!(str[i] > 47 && str[i] < 58) && !(temp==""))
		{
			cout << temp << "		id	=	Number" << endl;
			temp = "";
		}
	}
	/*bool a = false;

	std::string::const_iterator it = str.begin();
	while (it != str.end() && isdigit(*it)) ++it;
	return !str.empty() && it == str.end();*/
}

void isID(string str) {
	string temp = "";
	if (isKeyword(str))
	{
		return;
	}
	bool a = true;
	bool b = false;
	if ((str[0] == '_' || (str[0] <= 122 && str[0] >= 97)))
	{
		for (int i = 0; i < 10; i++)
		{
			if (str[0] == op[i])
			{
				b = true;
				break;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (str[0] == del[i])
			{
				b = true;
				break;
			}
		}
		if (b)
		{
			cout << str[0] << "		id	=	Identifier" << endl;
		}
		temp += str[0];
		for (int i = 1; i < str.length(); i++)
		{
			
			if (!((str[i]<58 && str[i]>47) || (str[i] < 91 && str[i] > 63 ) || (str[i] < 123 && str[i] > 96)))
			{
				a = false;
				break;
			}
			temp += str[i];
		}
	}
	if (a && temp!="")
	{
		cout <<temp<< "		id	=	Identifier" << endl;
	}
}