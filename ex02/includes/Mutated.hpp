#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector> // Für std::vector
# include <deque>  // Für std::deque (Standard)
# include <typeinfo> // Für typeid

template<typename T, typename Container = std::deque<T> > // Standardmäßig std::deque
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename std::stack<T, Container>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

    MutantStack() {}
    ~MutantStack() {}
    MutantStack(const MutantStack& src) { *this = src; }
    
    // Zuweisungsoperator
    MutantStack<T, Container>& operator=(const MutantStack<T, Container>& src) {
        if (this != &src) {
            this->c = src.c; // Zugriff auf den internen Container von std::stack
        }
        return *this;
    }

    // Iteratoren
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    // Funktion zum Ausgeben des Container-Typs
    void printContainerType() const {
        std::cout << "Underlying container type: " << typeid(container_type).name() << std::endl;
    }
};

//# include "MutantStack.tpp"

#endif
