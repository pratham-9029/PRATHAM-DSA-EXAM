#include<iostream>
#include<vector>
using namespace std;


//==============Merger Sort==============
void merge(vector<int>& arr,int start,int mid,int end)
{
    vector<int> temp;
    int i=start,j=mid+1;

    while (i<=mid && j<=end)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j<=end)
    {
        temp.push_back(arr[j++]);
    }

    for (int k = 0; k <temp.size();k++)
    {
        arr[start + k] = temp[k];
    }   
}
void merge_Sort(vector<int>& arr,int start,int end)
{
    if(start >= end) return;

    int mid = start + (end - start)/2;

    merge_Sort(arr,start,mid);
    merge_Sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}



//==========Quick Sort===========
int partition(vector<int> &arr,int start,int end)
{
    int pivot = arr[start];
    int cnt = 0;
    for(int i = start+1; i<=end; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }
    }
    int pivotIndex = start + cnt;
    swap(arr[pivotIndex],arr[start]);

    int i = start, j= end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        while(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int>& arr, int start, int end)
{
    if(start >= end) return ;

    int p = partition(arr,start,end);

    quickSort(arr,start,p);
    quickSort(arr,p+1,end);
}


//========Binary Search==========
int BinarySearch(vector<int>& arr,int target)
{

    int start = 0;
    int end = arr.size()-1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}


//========Display Array=========
void print_Array(vector<int>& arr)
{
    for ( int i = 0; i <arr.size(); i++)
    {
        cout<<arr.at(i)<<" ";
    }
    cout<<endl;
    
}


//=========Main Function===========
int main()
{

    int choice,n;
    do
    {
        cout<<endl<<"1. Merge Sort"<<endl;
        cout<<"2. Quick Sort"<<endl;
        cout<<"0. Exit!!"<<endl;

        cout<<endl<<"Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"Code Exited"<<endl;
                break;
            case 1:
                {
                    cout<<"Enter Size Of Array : ";
                    cin>>n;
                    
                    vector<int> arr(n);
                    for(int i = 0; i<n; i++)
                    {
                        cout<<"Enter arr["<<i<<"]: ";
                        cin>>arr[i];
                    }

                    cout<<"---Orignal---"<<endl;
                    print_Array(arr);

                    cout<<endl<<"---Sorted---"<<endl;
                    merge_Sort(arr,0,arr.size()-1);
                    print_Array(arr);

                    int target;
                    cout<<endl<<"=====Searching Through Binary Search====="<<endl;
                    cout<<"Enter target Element: ";
                    cin>>target;

                    int result = BinarySearch(arr,target);

                    if(result != 0)
                    {
                        cout<<"Value Found At Index: "<<result<<endl;
                    }
                    else
                    {
                        cout<<"Not Found"<<endl;
                    }
                    break; 
                }
            case 2:
                {
                    cout<<"Enter Size Of Array : ";
                    cin>>n;
                    
                    vector<int> arr(n);
                    for(int i = 0; i<n; i++)
                    {
                        cout<<"Enter arr["<<i<<"]: ";
                        cin>>arr[i];
                    }

                    cout<<"---Orignal---"<<endl;
                    print_Array(arr);

                    cout<<endl<<"---Sorted---"<<endl;
                    quickSort(arr,0,arr.size()-1);
                    print_Array(arr);

                    int target;
                    cout<<endl<<"=====Searching Through Binary Search====="<<endl;
                    cout<<"Enter target Element : ";
                    cin>>target;

                    int result = BinarySearch(arr,target);

                    if(result != 0)
                    {
                        cout<<"Value Found At Index: "<<result<<endl;
                    }
                    else
                    {
                        cout<<"Not Found"<<endl;
                    }
                    break;
                }
        }

    } while (choice != 0);

    return 0;
}