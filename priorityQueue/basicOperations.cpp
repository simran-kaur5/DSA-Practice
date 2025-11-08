#include <iostream>
#include <vector>
using namespace std;
class Heap
{
    vector<int> vec;

public:
    void push(int val)
    {
        // first push value at last idx
        vec.push_back(val);

        // correct the CBT to make it max Heap

        int childIdx = vec.size() - 1;
        int parIdx = (childIdx - 1) / 2;

        while (parIdx >= 0 && vec[childIdx] > vec[parIdx])
        {
            swap(vec[childIdx], vec[parIdx]);

            childIdx = parIdx;
            parIdx = (childIdx - 1) / 2;
        }
    }

    void fixHeap(int idx)
    {
        if (idx >= vec.size())
        {
            return;
        }

        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        int maxIdx = idx;
        if (left < vec.size() && vec[left] > vec[maxIdx])
        {
            maxIdx = left;
        }
        if (right < vec.size() && vec[right] > vec[maxIdx])
        {
            maxIdx = right;
        }

        swap(vec[idx], vec[maxIdx]);
        if (maxIdx != idx)
        {
            fixHeap(maxIdx);
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        swap(vec[0], vec[vec.size() - 1]); // O(1)

        vec.pop_back(); // delete last element -> O(1)

        fixHeap(0);  //this is called heapify it takes O(log n)
    }

    int top()
    {
        if (vec.empty())
        {
            cout << "Heap is empty!" << endl;
            return -1; // or throw exception
        }
        return vec[0];
    }

    bool isEmpty()
    {
        return vec.size() == 0;
    }
};
int main()
{
    Heap heap;
    heap.push(10);
    heap.push(34);

    cout << "Top of heap: " << heap.top() << endl;
    heap.pop();
    cout << "Top of heap: " << heap.top() << endl;

    return 0;
}