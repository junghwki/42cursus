#include "span.hpp"

void longest_error(Span &span)
{
    try {
        std::cout << "Longest span" << span.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
void shortest_error(Span &span)
{
    try {
        std::cout << "Shortest span" << span.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
void full_span_error(Span &span)
{
    try {
        std::cout << "full_span" << std::endl;
        span.addNumber(18);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    Span span_with_num(5);
    std::cout << "-------------Vector is Empty.. So Throw Error---------------" << std::endl;
    longest_error(span_with_num);
    shortest_error(span_with_num);
    span_with_num.addNumber(7);
    span_with_num.addNumber(3);
    span_with_num.addNumber(1);
    span_with_num.addNumber(42);
    span_with_num.addNumber(17);
    std::cout << "--------------Vector is Full.. So Throw Error---------------" << std::endl;
    full_span_error(span_with_num);
    std::cout << "----------All Element..----------" << std::endl;
    span_with_num.showElements();
    std::cout << "LongestSpan : " << span_with_num.longestSpan() << std::endl;
    std::cout << "ShortestSpan : " << span_with_num.shortestSpan() << std::endl;

    std::cout << "----------add with iterator----------" << std::endl;
    srand(time(NULL));
    Span span_with_iter(10000);
    std::vector<int> vec(10000);
    std::vector<int>::iterator begin = vec.begin();
    *begin++ = rand() % 10000 + 10000;
    for (int i = 0; begin != vec.end(); i++) {
        *begin = i;
        begin++;
    } 
    span_with_iter.addNumber(vec.begin(), vec.end());
    span_with_iter.showElements();
    std::cout << "LongestSpan : " << span_with_iter.longestSpan() << std::endl;
    std::cout << "ShortestSpan : " << span_with_iter.shortestSpan() << std::endl;

}