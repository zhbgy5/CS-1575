
template <typename T>
void my_sort(T init_array[],int size)
{
    T temp;
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
}
