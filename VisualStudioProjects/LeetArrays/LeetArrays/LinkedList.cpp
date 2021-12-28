template <typename listType>
class LinkedList
{
private:
	int _size;
	Node<listType>* _head = NULL;
	Node<listType>* _tail = NULL;
	Node<listType>* _itr = NULL;

public:

	LinkedList()
	{
		this->_size = 0;
	}

	void prepend(listType data)
	{
		if (this->_head == NULL)
		{
			this->_head = new Node<listType>(data);
			this->_tail = this->_head;
		}
		else
		{
			this->_head->_previous = new Node<listType>(data);
			this->_head->_previous->_next = this->_head;
			this->_head = this->_head->_previous;
		}
		this->_size++;
	}

	void append(listType data)
	{
		if (this->_head == NULL)
		{
			this->_head = new Node<listType>(data);
			this->_tail = this->_head;
		}
		else
		{
			this->_tail->_next = new Node<listType>(data);
			this->_tail->_next->_previous = this->_tail;
			this->_tail = this->_tail->_next;
		}
		this->_size++;
	}

	Node<listType>* iterate()
	{
		if (this->_itr == NULL)
			this->_itr = this->_head;
		else
			this->_itr = this->_itr->_next;

		return this->_itr;
	}

	listType ptr()
	{
		if (this->_itr != NULL)
			return this->_itr->_data;
		else
			return nullptr;
	}

	void resetIterator()
	{
		this->_itr = NULL;
	}
};

template<typename nodeType>
class Node
{
public:
	nodeType _data;
	Node* _next;
	Node* _previous;

	Node(nodeType value)
	{
		this->_data = value;
	}
};