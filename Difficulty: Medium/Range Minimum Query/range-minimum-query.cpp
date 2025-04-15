//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */
void buildSegmentTree(int ind , int left, int right, int arr[],  int segTree[]){
        if(left == right){
            segTree[ind] = arr[left];
            return;
        }
        int mid = (left + right)/2;
        buildSegmentTree(2*ind + 1, left, mid, arr, segTree);
        buildSegmentTree(2*ind + 2, mid + 1, right, arr, segTree);
        
        segTree[ind] = min(segTree[2*ind + 1] , segTree[2*ind + 2]);
        return;
    }
int *constructST(int arr[],int n)
{
    int *segTree = new int[4*n];
    fill(segTree, segTree + 4 * n, INT_MAX);
    buildSegmentTree(0, 0, n-1, arr, segTree);
    return segTree;
}
int Query(int start, int end, int ind, int left, int right, int st[]){
        if(end < left || start > right) return INT_MAX; //out of bound
        else if(start <= left && right <= end) return st[ind];
        int mid = (left + right)/2;
        return min(Query(start, end, 2*ind + 1, left, mid, st), Query(start, end, 2*ind + 2, mid+1, right, st));
    }

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return Query(a, b, 0, 0, n-1, st);
}