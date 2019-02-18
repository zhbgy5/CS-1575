
template <typename T>
bool my_is_sorted(T init_array[],int size)
{
    T temp;
    T temp_array[size];
    for(int i = 0;i<size;i++)
    {
        temp_array[i] = init_array[i];
    }
    for(int i = 0;i<size; i++)
    {
        for(int j = 0;j<size-1;j++)
        {
            if(init_array[j]<init_array[j+1])
            {
                temp = init_array[j];
                init_array[j] = init_array[j+1];
                init_array[j+1] = temp;
            }
        }
    }
    int i = 0;
    while(temp_array[i]==init_array[i])
    {
        if(i==size-1)
        {
            return true;
        }
        i++;
    }
    return false;
}
