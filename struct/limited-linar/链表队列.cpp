void LinkQueue <Type>::InQueue(Type &e)
{
	if(!front) 
		rear = front = new QueueNode;
	else
		rear = rear->next = new QueueNode;
}

