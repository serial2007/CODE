//p: 位置， content：加入的项
void LinkTable<T>::insert(int p, T content)
{
	LinkNode<T> *ptr, *tmp;
	if(p == 0)
	{
		tmp = this->head->next;
		this->head = new LinkNode<T>(content);
		this->head->next = tmp;
	}
	else{
		ptr = this->head;
		while(--p)
		{
			ptr = ptr->next;
			if(ptr == nullptr) {
				throw "错误，超出边界";
			}
		}
		tmp = ptr->next;
		ptr->next = new LinkNode<T>(content);
		ptr->next->next = tmp;
	}
}


