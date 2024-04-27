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
    return 0;
}
// result is: 65 61 59 60 57 52 55