#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, string> mob={
	{2,"abc"},
	{3,"def"},
	{4,"ghi"},
	{5,"jkl"},
	{6,"mno"},
	{7,"pqrs"},
	{8,"tuv"},
	{9,"wxyz"}
};

void getString(string s,vector<int> &v, int index)
{
	if(s.length()==v.size())
	{
		cout<<s<<" ";
		return;
	}
	
	for(int i=0;i<mob[v[index]].length();i++)
	{
		s=s+mob[v[index]][i];
		getString(s,v,index+1);
		s.erase(s.length()-1,1);
	}
}



int main()
{

	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	string s="";
	getString(s,v,0);


	return 0;
}
