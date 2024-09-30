
template<typename T>
MutantStack<T>::MutantStack() 
{this->printContainerType();}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{ *this = copy;}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
	if (this != &src)
		this->c = src.c;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{}