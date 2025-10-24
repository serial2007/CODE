//p：位置
void LinkTable<T>::remove(int p)
{
	LinkNode<T> *ptr, *tmp;
	if(p == 0)
	{
		if(this->head == nullptr) {
			throw "错误，超出边界";
		}
		tmp = this->head->next;
		delete this->head;
		this->head = tmp;
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
		if(ptr->next == nullptr) {
			throw "错误，超出边界";
		}
		tmp = ptr->next->next;
		delete ptr->next;
		ptr->next = tmp;
	}
}


