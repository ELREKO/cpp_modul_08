#include "includes/span.hpp"

// add a big set of numbers 
void test_set_1 (void)
{   unsigned int range = 10;
    unsigned int max_numbers = 10000;
    int min_range = -2140000; // Beispiel: Minimaler Wert
    int max_range = 2140000; // Beispiel: Maximaler Wert

    std::cout << "Range of " << range << " numbers" << std::endl; 
    Span sp(range);
   
    // For Test with other container
    std::vector<int> random_vector = randomContainerList<std::vector<int> >(max_numbers, min_range, max_range);
  // std::list<int> random_vector = randomContainerList<std::list<int> >(max_numbers, min_range, max_range);
  //std::deque<int> random_vector = randomContainerList<std::deque<int> >(max_numbers, min_range, max_range);

    std::cout << "Size of the vector: " << random_vector.size() << std::endl;
    sp.addRange(random_vector.begin(), random_vector.end());
    sp.printSpan();
}

// Schecke ERRORS
void test_set_2(void)
{
    unsigned int range = 1;
    unsigned int max_numbers = 10000;
    int min_range = -2140000; // Beispiel: Minimaler Wert
    int max_range = 2140000; // Beispiel: Maximaler Wert

    Span sp(range);
    sp.addNumber(12);
    sp.addNumber(13);
    std::vector<int> random_vector = randomContainerList<std::vector<int> >(max_numbers, min_range, max_range);
    sp.addRange(random_vector.begin(), random_vector.end());
    sp.trySpanFkt(&Span::shortestSpan);
    sp.trySpanFkt(&Span::longestSpan);

    try
    {
        sp.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void test_subject()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}



int main (void)
{
  //test_set_1();
  //test_set_2();
  //test_subject();
  return 0;
}

