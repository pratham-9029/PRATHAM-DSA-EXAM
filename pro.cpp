 
    
    int start = 0;
    int end = arr.size()-1;

    int mid = start + (end - start)/2;


    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
        else if (arr[i] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }