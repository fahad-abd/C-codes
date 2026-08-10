#include<iostream>
using namespace std;
void merge(int a[], int lb, int mid, int ub) 
{
    int b[100];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while(i <= mid && j <= ub) 
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else 
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i > mid) 
    {
        while(j <= ub) 
        {
            b[k] = a[j];
            j++;
            k++;
        }
    } 
    else 
    { 
        while(i <= mid) 
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(k = lb; k <= ub; k++) 
    {
        a[k] = b[k];
    }
}
void mergesort(int a[], int lb, int ub) 
{
    if(lb < ub) 
    {
        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
int main()
{
    int a[100], lb, ub;
    cout << "enter value of lower bound" << endl;
    cin >> lb;
    cout << "enter value of upper bound" << endl;
    cin >> ub;
    cout << "enter elements" << endl;
    for(int i = lb; i < ub; i++)
    {
        cin >> a[i];
    }
    cout << "displaying array" << endl;
    for(int i = lb; i < ub; i++)
    {
        cout << a[i] << " ";
    }
    mergesort(a, lb, ub - 1);
    cout << "\n after sorting \n";
    for(int i = lb; i < ub; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
