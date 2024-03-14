#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class maxHeap
{
    public:
    vector<int> hp;
    int i; //! [0,i] -->Everything is a maxHeap.

    //! Takes care of the priority of elements present in our heap.
    //* In case of mean heap only the greater than sign changes in our unheapify function.Rest everything remains same.
    void unheapify(int ci)
    {
        while (ci > 0)
        {
            int pi = (ci - 1) / 2; //* In c++ by default we get floor value while dividing.
            if (hp[pi] < hp[ci])
            {
                swap(hp[ci], hp[pi]);
                ci = pi;
            }
            else
                break;
        }
    }

    void downheapify(int idx)
    {
        while (idx < hp.size())
        {
            int lc = (2 * idx) + 1;
            int rc = (2 * idx) + 2;

            if (lc >= hp.size())
                break; //* idx-->leaf

            int maxEl = idx;

            if ( hp[maxEl] < hp[lc])
                maxEl = lc;
            else if (rc < hp.size() &&  hp[maxEl] < hp[rc])
                maxEl = rc;
            if (maxEl != idx)
            {
                swap(hp[idx], hp[maxEl]);
                idx = maxEl; //! For next iteration
            }
            else
                break;
        }
    }


    bool empty()
    {
        return hp.size() == 0;
    }

    //! Returns the value of root of our tree.

    int peak()
    {
        if (empty())
            return INT_MIN;
        return hp[0];
    }

    //! Pushes the element in our heap.

    void push(int element)
    {
        hp.push_back(element);
        unheapify(hp.size() - 1); //* this step takes care of the order of the pushed element in our maxHeap.
    }

    //! Prints all the elements present in our Heap.

    void display()
    {
        cout << "[";
        for (int i = 0; i < hp.size(); i++)
        {
            cout << hp[i] << " ";
        }
        cout << "]" << endl;
    }

    void pop()
    {
        //! Removes the highest priority element.
        if (empty())
            return;
        swap(hp[0], hp[hp.size() - 1]);
        hp.pop_back();
        if (!empty())
            downheapify(0);
    }

    //! Every Sorted Array be it ascending or descending is a min and max heap but every max or min heap is not always a sorted array.
    //! We will make it like a Heap constructor.Which takes array as an input.
//* To convert array to heap.
    // maxHeap(vector<int> v)
    // {
    //     //* TC = O(nlog(n))
    //     hp = v;
    //     for (int i = 1; i < hp.size(); i++)
    //     {
    //         unheapify(i);
    //     }
    // }

//* To convert array to heap in the most optimized way.
//! The following optimized heap formation method makes use of the logic that almost half the number of total nodes lies in the most bottom level of our given Heap.

     maxHeap(vector<int> v)
    {
        //* TC = O(n)
        hp = v;
        for (int i = n/2; i>=0; i--)
        {
            downheapify(i);
        }
    }
};

int main()
{

    // maxHeap hp;
    // hp.push(3);
    // hp.push(4);
    // hp.push(11);
    // hp.push(9);
    // hp.push(14);
    // hp.push(-1);
    // hp.push(30);
    // hp.push(44);
    // hp.push(50);
    // hp.display();
    // hp.pop();
    // hp.display();
    // hp.pop();
    // hp.display();
    // hp.pop();
    // hp.display();

    vector<int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
    maxHeap hp(v);
    hp.display();
    return 0;
}