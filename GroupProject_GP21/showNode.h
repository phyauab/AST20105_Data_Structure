#ifndef showNode_H
#define showNode_H
#include <string>
using namespace std;

class showNode {
public:
	string tconst;
	string titleType;
	string primaryTitle;
	int startYear;
	int runtimeMinutes;
	string genres[3] = { "", "", "" };
	showNode *next = NULL;

public:
	showNode(string a, string b, string c, int d, int e, string f) 
	{
		tconst = a;
		titleType = b;
		primaryTitle = c;
		startYear = d;
		runtimeMinutes = e;
		 
		int i = 0, flength = 0;
		string s = "";
		//cout << "this is f:  " << f.length() << "."<< endl;
		
		for (char& c : f)
		{
			flength++;
			if (c == ' ')
			{
				genres[i] = s;
				s = "";
				i++;
			
			}
			else if (flength == f.length())
			{
				s += c;
				genres[i] = s;
			}
			else
			{
				s += c;
			}
			
		}
	}
	~showNode() {
	}
};

#endif 
