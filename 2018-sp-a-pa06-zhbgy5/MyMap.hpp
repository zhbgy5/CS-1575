void get_identity(std::string my_id[])
{
    my_id[0]="zhbgy5";
    my_id[1]="12350273";
}
//HELPERS
template <typename K, typename V>
V&MyMap<K,V>::at_helper(TreeNode<MyPair<K,V>>*& rt, const K& key)
{
    return find_helper(rt,key)->second;
}
template <typename K, typename V>
int MyMap<K,V>::size_helper(TreeNode<MyPair<K,V>>* rt) const
{
    if(rt == NULL)
    {
        return 0;
    }
    else
    {
        return 1+size_helper(rt->left)+size_helper(rt->right);
    }
}
template <typename K, typename V>
void MyMap<K,V>::clear_helper(TreeNode<MyPair<K,V>>*& rt)
{
    if(rt == NULL)
    {
        return;
    }
    if (rt->left != NULL)
    {
        clear_helper(rt->left);
    }
    if (rt->right != NULL)
    {
        clear_helper(rt->right);
    }
    delete rt;
    rt = NULL;
}
template <typename K, typename V>
void MyMap<K,V>::insert_helper(TreeNode<MyPair<K,V>>*& rt, const MyPair<K,V>& init_pair)
{
    if(rt == NULL)
    {
        rt = new TreeNode<MyPair<K,V>>(init_pair,NULL,NULL);
    }
    else if (rt->data.first > init_pair.first)
    {
        insert_helper(rt->left,init_pair);
    }
    else
    {
        insert_helper(rt->right,init_pair);
    }

}
template <typename K, typename V>
TreeNode<MyPair<K,V>>*MyMap<K,V>::get_min(TreeNode<MyPair<K,V>>* rt)
{
    if(rt == NULL)
    {
        return NULL;
    }
    else if(rt->left == NULL)
    {
        return rt;
    }
    else
    {
        return get_min(rt->left);
    }
}
template <typename K, typename V>
void MyMap<K,V>::erase_helper(TreeNode<MyPair<K,V>>*& rt, const K& key)
{
    TreeNode<MyPair<K,V>>* temp;
    if(rt == NULL)
    {
        return;
    }
    if(rt->data.first == key)
    {
        if(rt->right == NULL && rt->left == NULL)
        {
            delete rt;
            return;
        }
        else if (rt->right == NULL || rt->left == NULL)
        {
            if(rt->right == NULL)
            {
                temp = rt->left;
                rt->data.first = temp->data.first;
                rt->data.second = temp->data.second;
                rt->left = temp->left;
                rt->right = temp->right;
                delete temp;
                return;
            }
            else
            {
                temp = rt->right;
                rt->data.first = temp->data.first;
                rt->data.second = temp->data.second;
                rt->left = temp->left;
                rt->right = temp->right;
                delete temp;
                return;
            }
        }
        else
        {
            temp = get_min(rt->right);
            if (temp == NULL)
            {
                return;
            }
            rt->data.first = temp->data.first;
            rt->data.second = temp->data.second;
            if(temp == rt->right)
            {
                rt->right = temp->right;
                delete temp;
            }
            erase_helper(rt->right,rt->data.first);
            return;
        }
    }
    else if(rt->data.first > key)
    {
        erase_helper(rt->left,key);
    }
    else if(rt->data.first < key)
    {
        erase_helper(rt->right,key);
    }
    return;
}
template <typename K, typename V>
MyPair<K,V>*MyMap<K,V>::find_helper(TreeNode<MyPair<K,V>>* rt, const K& key) const
{
        if(rt == NULL)
        {
            return NULL;
        }
        else if(key < rt->data.first)
        {
            find_helper(rt->left,key);
        }
        else if(key > rt->data.first)
        {
            find_helper(rt->right,key);
        }
        else
        {
            return &(rt->data);
        }
}
template <typename K, typename V>
void MyMap<K,V>::print_helper(TreeNode<MyPair<K,V>>* rt, std::string indent) const
{
    if (rt == NULL)
    {
        cout<<indent<<"empty"<<endl;
        return;
    }
    print_helper(rt->right,indent + "  ");
    cout<<indent<<rt->data.first<<" "<<rt->data.second<<endl;
    print_helper(rt->left,indent + "  ");
}
template <typename K, typename V>
int MyMap<K,V>::count_helper(TreeNode<MyPair<K,V>>* rt, const K& key) const
{
    if(rt == NULL)
    {
        return 0;
    }
    if (rt->data.first == key)
    {
        return 1 + count_helper(rt->left,key) + count_helper(rt->right,key);
    }
    else
    {
        count_helper(rt->left,key);
        count_helper(rt->right,key);
        return 0;
    }
}
template <typename K, typename V>
TreeNode<MyPair<K,V>>*MyMap<K,V>::clone(const TreeNode<MyPair<K,V>>* rt)
{
    if(rt ==  NULL)
    {
        return NULL;
    }
    TreeNode<MyPair<K,V>>* CopyNode =  new TreeNode<MyPair<K,V>>(rt->data,clone(rt->left),clone(rt->right));
    return CopyNode;
}
//FUNCTIONS
template <typename K, typename V>
MyMap<K,V>::MyMap()
{
    root = NULL;
}
template <typename K, typename V>
MyMap<K,V>::~MyMap()
{
    this->clear_helper(root);
}
template <typename K, typename V>
MyMap<K,V>::MyMap(const MyMap<K, V> &source)
{
    this->root = clone(source.root);
}
template <typename K, typename V>
MyMap<K,V>&MyMap<K,V>::operator=(const MyMap<K, V> &source)
{
    this->clear();
    this->root = clone(source.root);
    return *this;
}
template <typename K, typename V>
V&MyMap<K,V>::at(const K &key)
{
    if(find_helper(root,key)==NULL)
    {
        throw std::out_of_range("MyMap::at");
    }
    return at_helper(root,key);
}
template <typename K, typename V>
V&MyMap<K,V>::operator[](const K &key)
{
    if(find_helper(root,key)==NULL)
    {
        MyPair<K,V> temp(key);
        insert_helper(root,temp);
        return at_helper(root,key);
    }
    return at_helper(root,key);
}
template <typename K, typename V>
bool MyMap<K,V>::empty() const
{
    if(size_helper(root)>0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
template <typename K, typename V>
int MyMap<K,V>::size() const
{
    return size_helper(root);
}
template <typename K, typename V>
void MyMap<K,V>::insert(const MyPair<K,V> & init_pair)
{
    insert_helper(root,init_pair);
}
template <typename K, typename V>
void MyMap<K,V>::erase(const K& key)
{
    erase_helper(root,key);
}
template <typename K, typename V>
MyPair<K, V>*MyMap<K,V>::find(const K& key) const
{
    return find_helper(root,key);
}
template <typename K, typename V>
void MyMap<K,V>::print() const
{
    print_helper(root,"   ");
}
template <typename K, typename V>
int MyMap<K,V>::count(const K& key) const
{
    return count_helper(root,key);
}
template <typename K, typename V>
void MyMap<K,V>::clear()
{
    clear_helper(root);
}
