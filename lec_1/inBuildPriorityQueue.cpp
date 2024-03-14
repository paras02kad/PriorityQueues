#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main()
{

    // priority_queue<int>hp;//! Maxheap--> This is actually the short form.
    // priority_queue<int, vector<int>, less<int>> maxHeap;

    // cout<<hp.top()<<endl;


    //! minHeap;
    // priority_queue<int, vector<int>, greater<int>> hp;
    //! We need to give extra comparator to generate minHeap.
    //! Greater comparator is used because of the sign used in minHeap downHeapify Function.
    //* That is the function used is same as type of comparison done in downHeapify function.

    // hp.push(3);
    // hp.push(4);
    // hp.push(11);
    // hp.push(9);
    // hp.push(14);
    // hp.push(-1);
    // hp.push(30);
    // hp.push(44);
    // hp.push(50);
    // cout << hp.top() << endl;


   vector<int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
priority_queue<int,vector<int>,greater<int>>minHeapVector(v.begin(),v.end());

//! We need to give iterator when we give vector as input for Priority_queue.
//! Similarly we need to give pointers instead of iterators when we use arrays in place of vectors.

//cout<<minHeapVector.top()<<endl;//! 1 

int arr[] = {9, 6, 1, 19, 3, 2, 8, 12, 5};
priority_queue<int,vector<int>,less<int>>MaxHeapArray(arr,arr+9);
//cout<<MaxHeapArray.top()<<endl;//!19
cout<<v.size();
    return 0;
}