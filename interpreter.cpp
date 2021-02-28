#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
bool is_declared(string str);
void print(string str);
int str_to_int(string str);
int get_index(const string str);
vector<string> tokens;
//vector<string> string1;
//vector<string> string2;
//vector<string> string3;
//	vector<string> string4;
vector<string> lvalues;
vector<int> rvalues;
int main()
{
	string line;
	string line1;
	string line2;
	string line3;
	string line4;
	fstream f("code.h");
//	getline(f, line1, ' ');
//	string1.push_back(line1);
//	while(getline(f, line2, ' '))
//		string2.push_back(line2);
//	while(getline(f, line3, ' '))
//		string3.push_back(line3);
//	while(getline(f, line4, ' '))
//		string4.push_back(line4);
//	for(int j = 0; j < string1.size(); ++j)
//		cout << string1[j];
	while(!(f.eof()))
	{
		(getline(f, line, ' '));
		tokens.push_back(line);
	}
//	tokens.pop_back();
	for(int j = 0; j < tokens.size(); ++j)
		cout << tokens[j] << endl;
	for(int i = 0; i < tokens.size(); ++i)
	{
		if(tokens[i] == "klor"){
			tokens.erase(tokens.begin() + i);
			lvalues.push_back(tokens[i]);
			tokens.erase(tokens.begin() + i);
			rvalues.push_back(stoi(tokens[i]));
	
		}
		
	
		if(tokens[i] == "="){
			if(is_declared(tokens[i+1])){
				tokens.erase(tokens.begin()+i);
				if(tokens[i+1] == "+")
					rvalues[get_index(tokens[i])] += stoi(tokens[i+2]);else
				if(tokens[i+1] == "-")
					rvalues[get_index(tokens[i])] -= stoi(tokens[i+2]);else
				if(tokens[i+1] == "/")
					rvalues[get_index(tokens[i])] /= stoi(tokens[i+2]);else
				if(tokens[i+1] == "*")
					rvalues[get_index(tokens[i])] *= stoi(tokens[i+2]);else
				if(tokens[i+1] == "%")
					rvalues[get_index(tokens[i+1])] %= stoi(tokens[i+3]);else
				cout << "Unknown operation" << endl;
			}
		}
		if(tokens[i] == "tpi")
		{

			if(is_declared(tokens[i+1]))
			{
			
				cout << rvalues[get_index(tokens[i+1])] << endl;
		
			}
			else
				cout << tokens[i+1] << endl;			
			
		}

	}
	
	cout << rvalues[0];
	for(int j = 0; j < tokens.size(); ++j)
	{
		cout << tokens[j] << endl;
		if(tokens[j] == "tpi")
                {

                        if(is_declared(tokens[j+1]))
                        {

                                cout << rvalues[get_index(tokens[j+1])] << endl;

                        }
                        else
                                cout << tokens[j+1] << endl;

                }

	}
	
	return 0;
}
bool is_declared(string str)
{
	for(int i = 0; i < lvalues.size(); ++i)
	{
		if(lvalues[i] == str)
			return true;
		else
			return false;
	}
}
int get_index(string str)
{
	for(int i = 0; i < lvalues.size(); ++i)
	{
		if(str == lvalues[i])
			return i;
		else{
			return -1;
		}
	}
}



























