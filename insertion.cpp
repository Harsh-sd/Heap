#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {

        size = 0;
    }
    // swapping the value by taking as a referrence
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void insert(int val)
    {
        // inc.the size by 1
        size = size + 1;
        // pint that to index
        int index = size;
        // storing the value at that particular index
        arr[index] = val;
        // loop condition
        while (index > 1)
        {
            // finding its parent
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    };
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i];
            cout << endl;
        }
    };
    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "nothing to delte";
            return;
        }
        // put the last value to root position
        arr[1] = arr[size];
        // root is removed
        size--;
        // now put it to its right position
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex <= size && arr[leftindex] > arr[i])
            {
                swap(arr[leftindex], arr[i]);
                i = leftindex;
            }
            else if (rightindex < size && arr[rightindex] > arr[i])
            {
                swap(arr[rightindex], arr[i]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    heap h;
    h.insert(60);
    h.insert(65);
    h.insert(52);
    h.insert(61);
    h.insert(57);
    h.insert(59);
    h.insert(55);
    h.print();
    h.deletefromheap();
    h.print();
    return 0;
}
// result is: 65 61 59 60 57 52 55
// result is:61 60 59 55 57 52