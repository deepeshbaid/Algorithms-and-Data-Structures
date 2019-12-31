#include <iostream>
using namespace std;

void brackets(int n,string s,int open,int close)
{
	if(s.length()==2*n)
	{
		cout<<s<<endl;
		return;
	}
	if(open<n)
	{
		s=s+'(';
		brackets(n,s,open+1,close);
		s.erase(s.length()-1,1);
	}
	if(close<open)
	{
		s=s+')';
		brackets(n,s,open,close+1);
		s.erase(s.length()-1,1);
	}

}



int main() {


	int n=3;
	string s="";
	brackets(n,s,0,0);
	
	return 0;
}
