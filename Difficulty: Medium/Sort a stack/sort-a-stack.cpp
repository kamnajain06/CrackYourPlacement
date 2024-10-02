//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortHelper(stack<int> &s, int index){
    stack<int> temp;
    if(index == s.size()-1) return;
    int mini = s.top();
    s.pop();
    while(index != s.size()){
        int topEl = s.top();
        s.pop();
        if(topEl < mini){
            temp.push(mini);
            mini = topEl;
        }else{
            temp.push(topEl);
        }
    }
    temp.push(mini);
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
    sortHelper(s,index+1);
}
void SortedStack :: sort()
{
   sortHelper(s,0);
   return;
}
