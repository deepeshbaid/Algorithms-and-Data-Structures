#include <iostream>
#include<stack>
using namespace std;

//https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0

int main() {
	int _;
	cin>>_;
	while(_--)
	{   
	    string s;
	    cin>>s;
	    int n=s.length();
	    stack<pair<int,int>> st;
	    st.push({-1,-1});
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]==')' && st.top().first!=-1 && st.top().second==40)//To check if top of stack is an opening parentheses and current character is closing parentheses 
	        {
	            st.pop();
	            int topIndex=st.top().first;
	            ans=max(i-topIndex,ans);
	        }
	        else
	        {   
	            int k=s[i];
	            st.push(make_pair(i,k));
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
