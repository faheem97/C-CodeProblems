template <typename nodeType>
class Node
{
public:
	nodeType _value;
	Node _next;

	Node(nodeType data)
	{
		this->_value = data;
	}
};

template<typename stackType>
class Stack
{
public:
	Stack<stackType>()
	{
		this->_size = 0;
	}
	
	void push(stackType value)
	{
		if (this->_head == NULL)
		{
			this->_head = new Node<stackType>(value);
		}
		else
		{
			Node<stackType> *tmp = new Node<stackType>(value);
			
			tmp->_next = this->_head;
			this->_head = tmp;
		}

		this->_size++;
	}
	
	stackType pop()
	{
		if (this->_head == NULL)
			return nullptr;
		else
		{
			Node<stackType>* tmp = this->_head;
			this->_head = this->_head->_next;
			this->_size--;
			return tmp->_value;
		}
	}

	int size()
	{
		return this->_size;
	}

	Node<stackType>* iterate()
	{
		if (this->_itr == NULL)
		{
			this->_itr = this->_head;
		}
		else
		{
			this->_itr = this->_itr->next;
		}
		return this->_itr;
	}

	stackType ptr()
	{
		return this->_itr->value;
	}

	void resetIterator()
	{
		this->_itr = NULL;
	}

private:
	int _size;
	Node<stackType>* _head = NULL;
	Node<stackType>* _itr = NULL;
};
