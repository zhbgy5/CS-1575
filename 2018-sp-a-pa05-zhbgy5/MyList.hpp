
template <typename T>
MyList<T>::MyList()
{
    m_head = NULL;
    m_tail = m_head;
    m_size = 0;
}

template <typename T>
MyList<T>::~MyList()
{
    Node<T>* TempNode = m_head;
    while(m_size >0)
    {
        TempNode = TempNode->m_next;
        delete m_head;
        m_head = TempNode;
        m_size--;
    }
    delete m_head;
}

template <typename T>
MyList<T>&MyList<T>::operator=(const MyList<T> &source)
{
    this->clear();
    if(source.m_tail == NULL)
    {
        return *this;
    }
    Node<T>* CurrentNode;
    CurrentNode = source.m_head;
    for(int i=0;i<(source.m_size);i++)
    {
        this->push_back(CurrentNode->m_element);
        CurrentNode = CurrentNode->m_next;
    }
    return *this;
}

template <typename T>
MyList<T>::MyList(const MyList<T>& source)
{
    this->m_head = NULL;
    this->m_tail = m_head;
    this->m_size = 0;
    if(source->m_tail == NULL)
    {
        return;
    }
    Node<T>* CurrentNode;
    CurrentNode = source.m_head;
    for(int i=0;i<(source.m_size);i++)
    {
        this->push_back(CurrentNode->m_element);
        CurrentNode = CurrentNode->m_next;
    }
    return;
}

template <typename T>
T & MyList<T>::front()
{
    return m_head->m_element;
}

template <typename T>
T & MyList<T>::back()
{
    return m_tail->m_element;
}

template <typename T>
int MyList<T>::size()
{
    return m_size;
}

template <typename T>
void MyList<T>::assign(int count,const T &value)
{
    this->clear();
    for(int i=0;i<count;i++)
    {
        this->push_back(value);
    }
    m_size=count;
}

template <typename T>
void MyList<T>::clear()
{
    Node<T>* TempNode = m_head;
    while(m_size >0)
    {
        TempNode = TempNode->m_next;
        delete m_head;
        m_head = TempNode;
        m_size--;
    }
    delete m_head;
    m_head = NULL;
    m_tail = m_head;
    m_size = 0;
}

template <typename T>
void MyList<T>::push_front(const T& x)
{
    if(m_tail == NULL)
    {
        Node<T> *NewNode = new Node<T>(x,m_tail,NULL);
        m_tail = NewNode;
        m_head = m_tail;
        m_size++;
        return;
    }
    Node<T> *NewNode = new Node<T>(x,NULL,m_head);
    m_head->m_prev = NewNode;
    m_head = NewNode;
    m_size++;
}

template <typename T>
void MyList<T>::push_back(const T& x)
{
    if(m_tail == NULL)
    {
        Node<T> *NewNode = new Node<T>(x,m_tail,NULL);
        m_tail = NewNode;
        m_head = m_tail;
        m_size++;
        return;
    }
    Node<T> *NewNode = new Node<T>(x,m_tail,NULL);
    m_tail->m_next = NewNode;
    m_tail = NewNode;
    m_size++;
}

template <typename T>
void MyList<T>::pop_back()
{
    if(m_size == 0)
    {
        return;
    }
    if(m_size == 1)
    {
        this->clear();
        return;
    }
    Node<T> *NewNode = m_tail->m_prev;
    delete m_tail;
    m_tail = NewNode;
    m_size--;
}

template <typename T>
void MyList<T>::insert(int i,const T& x)
{
    if(i==0)
    {
        Node<T>* NewNode = new Node<T>(x,NULL,m_head);
        m_head->m_prev = NewNode;
        m_head = NewNode;
        m_size++;
        return;
    }
    if(i==m_size)
    {
        Node<T>* NewNode = new Node<T>(m_tail->m_element,m_tail,NULL);
        m_tail->m_next=NewNode;
        m_tail->m_element=x;
        m_tail=NewNode;
        m_size++;

        return;
    }
    Node<T>* CurrentNode = m_head;
    for(int j=1;j<i;j++)
    {
        CurrentNode=CurrentNode->m_next;
    }
    Node<T>* NewNode= new Node<T>(x,CurrentNode->m_prev,CurrentNode);
    CurrentNode->m_prev = NewNode;
    m_size++;
}


template <typename T>
void MyList<T>::remove(T i)
{
    Node<T>* CurrentNode = m_head;
    Node<T>* TempNode = m_head;
    for(int j=0;j<m_size;j++)
    {
      if(CurrentNode->m_element == i)
      {
        if(CurrentNode == m_head)
        {
            CurrentNode = m_head->m_next;
            delete m_head;
            m_head = CurrentNode;
            m_head->m_prev = NULL;
            j++;
            m_size--;
        }
        else if (CurrentNode == m_tail)
        {
            m_tail = CurrentNode->m_prev;
            delete CurrentNode;
            m_tail->m_next = NULL;
            j++;
            m_size--;
            return;
        }
        while (CurrentNode->m_element == i)
        {
            TempNode = CurrentNode;
            CurrentNode = CurrentNode->m_next;
            CurrentNode->m_prev = TempNode->m_prev;
            delete TempNode;
            TempNode = CurrentNode;
            j++;
            m_size--;
        }
        }
        CurrentNode=CurrentNode->m_next;
    }
}

template <typename T>
void MyList<T>::erase(int i)
{
    Node<T>* CurrentNode = m_head;
    Node<T>* TempNode = m_head;
    for(int j=0;j<i;j++)
    {
        CurrentNode = CurrentNode->m_next;
    }
    TempNode = CurrentNode;
    CurrentNode = CurrentNode->m_next;
    CurrentNode->m_prev=TempNode->m_prev;
    delete TempNode;
}

template <typename T>
void MyList<T>::reverse()
{
    Node<T>* CurrentFront = m_head;
    Node<T>* CurrentBack = m_tail;
    Node<T>* TempNode = new Node<T>(0,NULL,NULL);
    double Resultant = m_size/2;
    Resultant = Resultant+.5;
    for(int i=0;i<Resultant;i++)
    {
        TempNode->m_element=CurrentFront->m_element;
        CurrentFront->m_element=CurrentBack->m_element;
        CurrentBack->m_element=TempNode->m_element;
        CurrentFront=CurrentFront->m_next;
        CurrentBack=CurrentBack->m_prev;
    }
    delete TempNode;
}

template <typename T>
void MyList<T>::resize(int count)
{
    Node<T>* CurrentNode= m_head;
    Node<T>* TempNode=m_head;
    for(int i=0;i<count;i++)
    {
        CurrentNode=CurrentNode->m_next;
    }
    TempNode = CurrentNode;
    CurrentNode=CurrentNode->m_next;
    TempNode->m_next=m_tail;
    m_tail->m_prev=TempNode;
    while(CurrentNode!=m_tail)
    {
        TempNode = CurrentNode;
        CurrentNode=CurrentNode->m_next;
        delete TempNode;
    }
}

template <typename T>
bool MyList<T>::empty()
{
    if(m_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}





















