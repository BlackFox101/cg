#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

bool IsEvenPermutation(vector<float> permutation)
{
    int inversionCount = 0;

    for (size_t i = 0; i < permutation.size(); i++)
    {
        for (size_t j = i + 1; j < permutation.size(); j++)
        {
            if (permutation[i] > permutation[j])
            {
                inversionCount++;
                //cout << "i = " << permutation[i] << ", j = " << permutation[j] << endl;
            }
        }
    }

    return inversionCount % 2 == 0;
}

string VectorToString(vector<float> numbers)
{
    ostringstream output;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        output << setw(2) << numbers[i];
        if (i < numbers.size() - 1)
        {
            output << ", ";
        }
    }

    return output.str();
}

bool IsEvenPositiveNumbers(vector<float> numbers)
{
    size_t positiveNumbersCount = 0;
    for (auto number : numbers)
    {
        if (number > 0)
        {
            positiveNumbersCount++;
        }
    }

    return positiveNumbersCount % 2 == 0;
}

size_t Permutation(vector<float> numbers)
{
    size_t evensCount = 0;

    sort(numbers.begin(), numbers.end());

    do {
        if (IsEvenPermutation(numbers) && IsEvenPositiveNumbers(numbers))
        {
            cout << VectorToString(numbers) << endl;
            evensCount++;
        }
        //cout << WriteVector(vertices) << " "
        //    << (IsEvenPermutation(vertices) ? "Even" : "Uneven") << '\n';
    } while (next_permutation(numbers.begin(), numbers.end()));

    return evensCount;
}

int main()
{
    // (±2a, ±2, ±2b),
    float m_fi = (1 + std::sqrt(5)) / 2;
    float e = 1.7155615;
    float a = e - 1 / e;
    float b = e * m_fi + m_fi * m_fi + m_fi / e;

    float a1 = 1; // 2 * a = 2.26
    float b1 = 2; // 2 = 2
    float c1 = 3; // 2 * b = 12.6

    vector<vector<float>> vertices = {
        {-a1, -b1, -c1},
        {-a1, -b1,  c1},
        {-a1,  b1, -c1},
        {-a1,  b1,  c1},
        { a1, -b1, -c1},
        { a1, -b1,  c1},
        { a1,  b1, -c1},
        { a1,  b1,  c1},
    };

    size_t evensCount = 0;

    for (auto t : vertices)
    {
        evensCount += Permutation(t);
    }
    cout << evensCount << endl;

    vertices = {
        {-3, -2, -1},
        {-2, -1, -3},
        {-1, -3, -2},
        {-1,  2,  3},
        {2,  3, -1},
        {3, -1,  2},
        {-2,  1,  3},
        {1,  3, -2},
        {3, -2,  1},
        {-3,  1,  2},
        {1,  2, -3},
        {2, -3,  1}
    };

    sort(vertices.begin(), vertices.end());
    for (auto t : vertices)
    {
        cout << VectorToString(t) << endl;
    }
}