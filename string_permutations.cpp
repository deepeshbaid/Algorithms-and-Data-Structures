#include<iostream>
using namespace std;

void permute(string s,string chosen)
{	
	if(s.empty())
		{	
			cout<<chosen<<endl;
		}
	else
	{
		for(int i=0;i<s.length();i++)
		{
			char c=s[i];
			chosen=chosen+c;
			s.erase(i,1);
			permute(s,chosen);
			s.insert(i,1,c);
			chosen.erase(chosen.length()-1,1);
		}
	}
}

int main()
{	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s="abcde";
    cout<<"Permutations of string \""<<s<<"\" are:"<<endl;
    permute(s," ");
 
	return 0;
}