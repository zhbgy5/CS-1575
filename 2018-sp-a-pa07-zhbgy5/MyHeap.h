
template <class T>
class MyHeap
{
        T* m_heap;
        int data_size;
        int reserved_size;
        void reserve(int size)
        {
            if(size == data_size)
            {
                size = size*2;
            }
            T *p= new T [size];
            for(int i=0;i<data_size;i++)
            {
                p[i] = m_heap[i];
            }
            delete[] m_heap;
            m_heap = p;
            reserved_size = size;
            p = nullptr;
        }
        void shrink_to_fit()
        {
            T *p = new T [data_size];
            for(int i=0;i<data_size+1;i++)
            {
                p[i] = m_heap[i];
            }
            delete[] m_heap;
            m_heap = p;
            reserved_size = data_size;
            p = nullptr;
        }
        void push_back(T x)
        {
            data_size=data_size+1;
            if(data_size>=reserved_size)
            {
                reserve(data_size);
            }
            m_heap[data_size-1] = x;
        }
        void erase(int i)
        {
            data_size--;
            if((data_size)<(reserved_size/4))
            {
            shrink_to_fit();
            }
            T *p= new T [reserved_size];
            int q = 0;
            for(int j=0;j<data_size+1;j++)
            {
                if(j==i)
                {
                    q++;
                }
                p[j] = m_heap[q];
                q++;
            }
            delete[] m_heap;
            m_heap = p;
            p = nullptr;
        }
        void move_up()
        {
            int bottom = data_size - 1;
            int this_top = get_up(bottom);
            while(m_heap[bottom]>m_heap[this_top] && bottom >= 0 && this_top >= 0)
            {
                swap(bottom,this_top);
                bottom = this_top;
                this_top = get_up(bottom);
            }
        }
        void move_down()
        {
            int this_top = 0;
            while(1)
            {
                int left = get_left(this_top);
                int right = get_right(this_top);
                int size = data_size;
                int biggest = this_top;
                if(left < size && m_heap[left] > m_heap[biggest])
                {
                    biggest = left;
                }
                if(right < size && m_heap[right] > m_heap[biggest])
                {
                    biggest = right;
                }
                if(biggest != this_top)
                {
                    swap(biggest,this_top);
                    this_top = biggest;
                }
                else
                {
                    break;
                }
            }
        }
        void swap(int first, int second)
        {
            T temp;
            temp=m_heap[first];
            m_heap[first] = m_heap[second];
            m_heap[second] = temp;
        }
        int get_left(int pos)
        {
            return 2*pos + 1;
        }
        int get_right(int pos)
        {
            return 2*pos +2;
        }
        int get_up(int pos)
        {
            if(pos%2 == 0)
            {
                return pos/2 - 1;
            }
            else
            {
                return pos/2;
            }
        }
    public:
        MyHeap()
        {
            m_heap =  new T [1];
            reserved_size = 1;
            data_size = 0;
        }
        ~MyHeap()
        {
            delete[] m_heap;
        }
        MyHeap(T init_array[],int size)
        {
            m_heap =  new T [1];
            reserved_size = 1;
            data_size = 0;
            for(int i = 0;i<size;i++)
            {
                push_back(init_array[i]);
                move_up();
            }
        }
        MyHeap(const MyHeap<T> &source)
        {
            this->reserved_size = source.reserved_size;
            this->data_size = source.data_size;
            this->m_heap = new T [reserved_size];
            for(int i=0;i<this->data_size;i++)
            {
                this->m_heap[i] = source.m_heap[i];
            }
        }
        MyHeap<T> & operator=(const MyHeap<T> &source)
        {
            if(this == &source)
            {
                return *this;
            }
            if(m_heap != NULL)
            {
            delete [] m_heap;
            }
            this->reserved_size = source.reserved_size;
            this->data_size = source.data_size;
            this->m_heap = new T [reserved_size];
            for(int i=0;i<this->data_size;i++)
            {
                this->m_heap[i] = source.m_heap[i];
            }
            return *this;
        }
        T & top()
        {
            return m_heap[0];
        }
        void pop()
        {
            erase(0);
            move_down();
        }
        void push(T value)
        {
            push_back(value);
            move_up();
        }
        bool empty()
        {
            if(data_size == 0)
            {
                return true;
            }
            return false;
        }
        int size()
        {
            return data_size;
        }
};

