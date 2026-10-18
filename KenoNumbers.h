#ifndef CSC_275_TEST1_KENO_KENONUMBERS_H
#define CSC_275_TEST1_KENO_KENONUMBERS_H

#include <vector>

class KenoNumbers
{
private:
    // Stores the 20 winning Keno numbers.
    std::vector<int> m_numbers;

public:
    // Created a KenoNumbers object.
    KenoNumbers();

    // Generates the numbers.
    void generateNumbers();

    // Returns the winning numbers.
    std::vector<int> getKenoNumbers() const;

    // Displays the winning numbers.
    void printKenoNumbers() const;

    // Clears the numbers before another round.
    void clearKenoNumbers();
};

#endif //CSC_275_TEST1_KENO_KENONUMBERS_H