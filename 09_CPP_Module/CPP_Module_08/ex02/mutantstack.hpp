#ifndef MUSTANTSTACK_HPP
# define MUSTANTSTACK_HPP

template <typename T>
class MutantStack : public std::stack<T>
{
public:
typedef typename std::stack<T>::container_type::iterator iterator;
private:
};

#endif