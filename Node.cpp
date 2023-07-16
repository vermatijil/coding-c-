template <typename T>

class Node
{
public:
    T data;
    Node *link;
    Node(T data)
    {
        this->link = NULL;
        this->data = data;
    }
};