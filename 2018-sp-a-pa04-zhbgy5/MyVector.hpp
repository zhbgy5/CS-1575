/* Define all your MyVector-related functions here.
 * You do not need to include the h file.
 * It included this file at the bottom.
 */
template <typename T>
MyVector<T>::MyVector()
{
    m_data =  new T [1];
    reserved_size = 1;
    data_size = 0;
}

template <typename T>
MyVector<T>&MyVector<T>::operator=(const MyVector<T> &source)
{
    if(this == &source)
    {
        return *this;
    }
    if(m_data != NULL)
    {
        delete [] m_data;
    }
    this->reserved_size = source.reserved_size;
    this->data_size = source.data_size;
    this->m_data = new T [reserved_size];
    for(int i=0;i<this->data_size;i++)
    {
        this->m_data[i] = source.m_data[i];
    }
    return *this;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
    this->reserved_size = source.reserved_size;
    this->data_size = source.data_size;
    this->m_data = new T [reserved_size];
    for(int i=0;i<this->data_size;i++)
    {
        this->m_data[i] = source.m_data[i];
    }
}
// We're giving you this one for free
// and as a guide for the syntax.
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}

template <typename T>
 T & MyVector<T>::operator[](int i)
 {
     if(i<0 || i>(data_size-1))
     {
         throw OutOfBoundsException();
     }
     return m_data[i];
 }

// Another example: remember, return type first,
// then scope just before the function name.
template <typename T>
T & MyVector<T>::at(int index)
{
    if(index<0 || index>(data_size-1))
     {
         throw OutOfBoundsException();
     }
    return m_data[index];
}

template <typename T>
T & MyVector<T>::front()
{
    return m_data[0];
}

template <typename T>
T & MyVector<T>::back()
{
    return m_data[data_size-1];
}

template <typename T>
int MyVector<T>::capacity()
{
    return reserved_size;
}

template <typename T>
void MyVector<T>::reserve(int new_cap)
{
        if(new_cap == data_size)
        {
            new_cap =new_cap*2;
        }
        T *p= new T [new_cap];
        for(int i=0;i<data_size;i++)
        {
            p[i] = m_data[i];
        }
        delete[] m_data;
        m_data = p;
        reserved_size = new_cap;
        p = nullptr;
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    T *p = new T [data_size*2];
    for(int i=0;i<data_size+1;i++)
    {
        p[i] = m_data[i];
    }
    delete[] m_data;
    m_data = p;
    reserved_size = data_size*2;
    p = nullptr;
}

template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
    data_size = count;
    if(count>reserved_size)
    {
        reserve(count);
    }
    if(count<(reserved_size/4))
    {
        shrink_to_fit();
    }
    delete[] m_data;
    m_data = new T [reserved_size];
    for(int i=0;i<count;i++)
    {
        m_data[i]=value;
    }
}

template <typename T>
void MyVector<T>::clear()
{
    delete[] m_data;
    m_data = new T [1];
    data_size = 0;
    reserved_size = 1;
}

template <typename T>
void MyVector<T>::push_back(const T &x)
{
    data_size++;
    if(data_size>reserved_size)
    {
        reserve(data_size);
    }
    m_data[data_size-1] = x;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if(data_size==1)
    {
        delete[] m_data;
        m_data = new T [1];
        data_size = 0;
        reserved_size = 1;
    }
    else if(data_size == 0)
    {
        throw OutOfBoundsException();
    }
    else
    {
        data_size--;
        if((data_size)<(reserved_size/4))
        {
            shrink_to_fit();
        }
        T *p= new T [reserved_size];
        for(int i=0;i<data_size;i++)
        {
            p[i]=m_data[i];
        }
        delete[] m_data;
        m_data = p;
        p = nullptr;
    }
}

template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
    if(i<0 || i>data_size)
    {
        throw OutOfBoundsException();
    }
    data_size++;
    if(data_size>reserved_size)
    {
        reserve(data_size+1);
    }
    T *p=new T [reserved_size];
    int q = 0;
    for(int j=0;j<data_size;j++)
    {
        if(i==j)
        {
            p[q]=x;
            q++;
        }
        p[q]=m_data[j];
        q++;
    }
    delete[] m_data;
    m_data = p;
    p = nullptr;
}

template <typename T>
void MyVector<T>::remove(int i)
{
    if(i<0 || i>(data_size-1))
    {
        throw OutOfBoundsException();
    }
    data_size--;
    if((data_size)<(reserved_size/4))
    {
        shrink_to_fit();
    }
    T *p=new T [reserved_size];
    int q = 0;
    for(int j=0;j<data_size+1;j++)
    {
        if(j==i)
        {
            q++;
        }
        p[j] = m_data[q];
        q++;
    }
    delete[] m_data;
    m_data = p;
    p = nullptr;
}

template <typename T>
int MyVector<T>::size()
{
    return data_size;
}






