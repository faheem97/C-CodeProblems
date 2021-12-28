template <typename nodeType>
class Node
{
public:
	nodeType _value;
	Node _next;
	Node _previous;

	Node(nodeType data)
	{
		this->_value = data;
	}
};

template <typename qType>
class Queue
{
public:
	Queue();
	~Queue();
	void enque(qType value);
	qType deque();

private:
	int _size;
	Node<qType>* _head;
	Node<qType>* _tail;
};

template <typename qType>
Queue<qType>::Queue()
{
	this->_size = 0;
}

template <typename qType>
Queue<qType>::~Queue()
{

}

template<typename qType>
void Queue<qType>::enque(qType value)
{
	if (this->_head == NULL)
	{
		this->_head = new Node<qType>(value);
		this->_tail = this->_head;
	}
	else
	{
		this->_tail->_next = new Node<qType>(value);
		this->_tail->_next->_previous = this->_tail;
		this->_tail = this->_tail->_next;
	}
	this->_size++;
}

template<typename qType>
qType Queue<qType>::deque()
{
	Node<qType>* tmp = this->_tail;
	this->_tail = this->_tail->_previous;
	this->_tail->_next = NULL;
	this->_size--;
	return tmp->_value;
}
