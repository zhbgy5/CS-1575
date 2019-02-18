void get_identity(std::string my_id[])
{
    my_id[0] ="zhbgy5";
    my_id[1] ="12350273";
}
template <typename K, typename V>
int MyUnorderedMap<K,V>::hash(const K& key) const
{
    int sum = 0;
    for(int i = 0; key[i] != '\0'; i++)
    {
        sum += (int)key[i];
    }
    return sum % reserved_size;
}
template <typename K, typename V>
MyUnorderedMap<K,V>::MyUnorderedMap()
{
    m_data = nullptr;
    data_size = 0;
    reserved_size = 0;
}
template <typename K, typename V>
MyUnorderedMap<K,V>::~MyUnorderedMap()
{
    delete[] m_data;
}
template <typename K, typename V>
MyUnorderedMap<K,V>::MyUnorderedMap(const MyUnorderedMap<K, V> &source)
{
    this->reserved_size = source.reserved_size;
    this->data_size = source.data_size;
    this->m_data = new MyPair<K,V> [source.reserved_size];
    for(int i = 0;i<source.reserved_size;i++)
    {
        if(source.m_data[i].first == "empty" || source.m_data[i].first == "tomb")
        {
            MyPair<K,V> temp("empty");
            this->m_data[i]=temp;
        }
        else
        {
            MyPair<K,V> temp(source.m_data[i].first,source.m_data[i].second);
            this->m_data[i] = temp;
        }
    }
}
template <typename K, typename V>
MyUnorderedMap<K, V>&MyUnorderedMap<K,V>::operator=(const MyUnorderedMap<K, V> &source)
{
    this->clear();
    this->reserved_size = source.reserved_size;
    this->data_size = source.data_size;
    this->m_data = new MyPair<K,V> [source.reserved_size];
    for(int i = 0;i<source.reserved_size;i++)
    {
        if(source.m_data[i].first == "empty" || source.m_data[i].first == "tomb")
        {
            MyPair<K,V> temp("empty");
            this->m_data[i]=temp;
        }
        else
        {
            MyPair<K,V> temp(source.m_data[i].first,source.m_data[i].second);
            this->m_data[i] = temp;
        }
    }
    return *this;

}
template <typename K, typename V>
V&MyUnorderedMap<K,V>::at(const K &key)
{
    if(reserved_size == 0)
    {
        throw std::out_of_range("MyUnorderedMap::at");
    }
    int temp_key = hash(key);
    if(m_data[temp_key].first == "empty" || m_data[temp_key].first == "tomb" || m_data[temp_key].first != key)
    {
        throw std::out_of_range("MyUnorderedMap::at");
    }
    return m_data[temp_key].second;
}
template <typename K, typename V>
V&MyUnorderedMap<K,V>::operator[](const K &key)
{
    if(reserved_size == 0)
    {
        data_size++;
        reserve(data_size);
    }
    int temp_key = hash(key);
    if(m_data[temp_key].first=="empty" || m_data[temp_key].first=="tomb")
    {
        data_size++;
        reserve(data_size);
        temp_key = hash(key);
        if(m_data[temp_key].first=="empty"|| m_data[temp_key].first=="tomb")
        {
            m_data[temp_key].first = key;
            return m_data[temp_key].second;
        }
    }
    else if(m_data[temp_key].first != "empty" && m_data[temp_key].first != "tomb" && m_data[temp_key].first != key)
    {
        int j = temp_key+1;
        while(m_data[j].first != "empty" && m_data[j].first != "tomb" && m_data[j].first != key && j<reserved_size)
        {
            j++;
        }
        if(j == reserved_size-1 && m_data[j].first !="empty" && m_data[j].first != "tomb" && m_data[j].first != key)
        {
            j=0;
            while(m_data[j].first != "empty" && m_data[j].first != "tomb" && m_data[j].first != key)
            {
                j++;
            }
        }
        if(m_data[j].first =="empty"||m_data[j].first =="tomb")
        {
            data_size++;
            reserve(data_size);
            temp_key = hash(key);
            m_data[temp_key].first = key;
            return m_data[temp_key].second;
        }
        return m_data[j].second;
    }
    else
    {
        return m_data[temp_key].second;
    }
}
template <typename K, typename V>
bool MyUnorderedMap<K,V>::empty() const
{
    if(data_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename K, typename V>
int MyUnorderedMap<K,V>::size() const
{
    return data_size;
}
template <typename K, typename V>
void MyUnorderedMap<K,V>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    data_size = 0;
    reserved_size = 0;
}
template <typename K, typename V>
void MyUnorderedMap<K,V>::insert(const MyPair<K, V> &init_pair)
{
    data_size++;
    reserve(data_size);
    int temp_key = hash(init_pair.first);
    if(m_data[temp_key].first != "empty" && m_data[temp_key].first != "tomb")
    {
        int j = temp_key+1;
        while(m_data[j].first != "empty" && m_data[j].first != "tomb" && j < reserved_size)
        {
            j++;
        }
        if(m_data[j].first != "empty" && m_data[j].first != "tomb")
        {
            j = 0;
            while(m_data[j].first != "empty" && m_data[j].first != "tomb")
            {
                j++;
            }
        }
        m_data[j]=init_pair;
    }
    else
    {
        m_data[temp_key] = init_pair;
    }
}
template <typename K, typename V>
void MyUnorderedMap<K,V>::erase(const K &key)
{
    if(reserved_size == 0)
    {
        return;
    }
    for(int i = 0; i<reserved_size;i++)
    {
        if(m_data[i].first == key)
        {
            m_data[i].first = "tomb";
            data_size--;
        }
    }
    reserve(data_size);
}
template <typename K, typename V>
MyPair<K, V>*MyUnorderedMap<K,V>::find(const K &key) const
{
    if(reserved_size == 0)
    {
        return nullptr;
    }
    int temp_key = hash(key);
    if(m_data[temp_key].first == "empty")
    {
        return nullptr;
    }
    else if (m_data[temp_key].first == "tomb" || m_data[temp_key].first != key)
    {
        for(int i = 0;i<reserved_size;i++)
        {
            if(m_data[i].first == key)
            {
                return &m_data[i];
            }
        }
        return nullptr;
    }
    else
    {
        return &m_data[temp_key];
    }
}
template <typename K, typename V>
void MyUnorderedMap<K,V>::print() const
{
    if(reserved_size == 0)
    {
        cout<<"[]";
        return;
    }
    cout<<"[";
    for(int i = 0;i<reserved_size-1;i++)
    {
        if(m_data[i].first == "empty" || m_data[i].first == "tomb")
        {
            cout<<"(empty),";
        }
        else
        {
            cout<<"("<<m_data[i].first<<","<<m_data[i].second<<"),";
        }
    }
    if(m_data[reserved_size-1].first == "empty" || m_data[reserved_size-1].first == "tomb")
    {
        cout<<"(empty)]";
    }
    else
    {
        cout<<"("<<m_data[reserved_size-1].first<<","<<m_data[reserved_size-1].second<<")]";
    }
}
template <typename K, typename V>
int MyUnorderedMap<K,V>::count(const K &key) const
{
    if(reserved_size == 0)
    {
        return 0;
    }
    int temp_key = hash(key);
    int sum = 0;
    if(m_data[temp_key].first == "empty")
    {
        return 0;
    }
    else
    {
        for(int i = 0;i<reserved_size;i++)
        {
            if(m_data[i].first == key)
            {
                sum++;
            }
        }
        return sum;
    }
}
template <typename K, typename V>
void MyUnorderedMap<K,V>::reserve(int new_cap)
{
    if(new_cap == 0)
    {
        delete[] m_data;
        m_data = nullptr;
        data_size = 0;
        reserved_size = 0;
        return;
    }
    if(reserved_size == 0)
    {
        reserved_size = new_cap * 2;
        m_data = new MyPair<K,V> [reserved_size];
        MyPair<K,V> temp_pair("empty");
        for(int i = 0;i<reserved_size;i++)
        {
            m_data[i] = temp_pair;
        }
        return;
    }
    if((new_cap/reserved_size) >= .6)
    {
        int temp_key,temp_reserved;
        MyPair<K,V> * temp = new MyPair<K,V> [reserved_size * 2];
        MyPair<K,V> temp_pair("empty");
        for(int i = 0;i<reserved_size*2;i++)
        {
            temp[i] = temp_pair;
        }
        temp_reserved = reserved_size;
        reserved_size = reserved_size * 2;
        for(int i = 0;i<temp_reserved;i++)
        {
            if(m_data[i].first != "empty" && m_data[i].first != "tomb")
            {
                temp_key = hash(m_data[i].first);
                if(temp[temp_key].first != "empty" && temp[temp_key].first != "tomb")
                {
                    int j = temp_key+1;
                    while(temp[j].first != "empty" && temp[j].first != "tomb" && j<reserved_size)
                    {
                        j++;
                    }
                    if(temp[j].first != "empty" && temp[j].first != "tomb")
                    {
                        j = 0;
                        while(temp[j].first != "empty" && temp[j].first != "tomb")
                        {
                            j++;
                        }
                    }
                    MyPair<K,V> temp_pair(m_data[i].first,m_data[i].second);
                    temp[j] = temp_pair;
                }
                else
                {
                    MyPair<K,V> temp_pair(m_data[i].first,m_data[i].second);
                    temp[temp_key]=temp_pair;
                }
        }
        delete[] m_data;
        m_data = temp;
        return;
    }
    if((new_cap/reserved_size) <= .1)
    {
        int temp_key,temp_reserved;
        temp_reserved = reserved_size *.3;
        MyPair<K,V> * temp = new MyPair<K,V> [temp_reserved];
        MyPair<K,V> temp_pair("empty");
        for(int i = 0;i<reserved_size*.3;i++)
        {
            temp[i] = temp_pair;
        }
        temp_reserved = reserved_size;
        reserved_size = reserved_size * .3;
        for(int i = 0;i<temp_reserved;i++)
        {
            if(m_data[i].first != "empty" && m_data[i].first != "tomb")
            {
                temp_key = hash(m_data[i].first);
                if(temp[temp_key].first != "empty" && temp[temp_key].first != "tomb")
                {
                    int j = temp_key+1;
                    while(temp[j].first != "empty" && temp[j].first != "tomb"&&j<reserved_size)
                    {
                        j++;
                    }
                    if(temp[j].first != "empty" && temp[j].first != "tomb")
                    {
                        j = 0;
                        while(temp[j].first != "empty" && temp[j].first != "tomb")
                        {
                            j++;
                        }
                    }
                    MyPair<K,V> temp_pair(m_data[i].first,m_data[i].second);
                    temp[j] = temp_pair;
                }
                else
                {
                    MyPair<K,V> temp_pair(m_data[i].first,m_data[i].second);
                    temp[temp_key]=temp_pair;
                }
            }
        }
        delete[] m_data;
        m_data = temp;
        return;
    }
}}
