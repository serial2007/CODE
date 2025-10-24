template <class Elem> class List {
public:
	virtual void clear() = 0;
	...
};
template <class Elem> class AListNode {
public:
	Elem data;
	AListNode<Elem> *next;
};

template <class Elem> class AList : public List<ELem> {
private:
	AListNode<Elem> *head, *cur, *next;
public:
	AList() {
		head = cur = next = new AListNode<Elem>;
	}
};
