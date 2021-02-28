#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
bool is_declared(string str);
int get_index(const string str);
vector<string> tokens;
vector<string> lvalues;
vector<int> rvalues;
int main()
{	

	string line;
	fstream f("code.h");
	while(!(f.eof()))
	{
		(getline(f, line, ' '));
		tokens.push_back(line);
	}
	for(int j = 0; j < tokens.size(); ++j)
		cout << tokens[j] << endl;
	for(int i = 0; i < tokens.size(); ++i)
	{

		// checking for declaration

		if(tokens[i] == "klor"){
			tokens.erase(tokens.begin() + i);
			lvalues.push_back(tokens[i]);
			tokens.erase(tokens.begin() + i);
			rvalues.push_back(stoi(tokens[i]));
	
		}
		
		// checking for assignment

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




