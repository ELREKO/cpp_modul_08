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
  //std::list<int> random_vector = randomContainerList<std::list<int> >(max_numbers, min_range, max_range);
  //std::deque<int> random_vector = randomContainerList<std::deque<int> >(max_numbers, min_range, max_range);

    
    std::cout << "Size of the vector: " << random_vector.size() << std::endl;
    sp.addRange(random_vector.begin(), random_vector.end());
    sp.printSpan();
}


int main (void)
{
  test_set_1();
}

