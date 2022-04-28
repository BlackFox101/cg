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


template <class T>
string VectorToString(vector<T> numbers)
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

size_t Permutation(vector<string> numbers)
{
    size_t evensCount = 0;

    sort(numbers.begin(), numbers.end());
    do {
        //if (IsEvenPermutation(numbers))
        //{
            cout << VectorToString(numbers) << endl;
            evensCount++;
        //}
    } while (next_permutation(numbers.begin(), numbers.end()));

    return evensCount;
}

float CubicRoot(float number)
{
    return pow(number, 1.0 / 3.0);
}

int main()
{
    float a1 = 1.0; // 1
    float b1 = 1.0 + sqrt(2.0); // 2.4
    float c1 = 1.0 + 2.0*sqrt(2.0); // 3.8

    vector<vector<float>> vertices = {
        {0, 0,  1},
        {0,  1, 0},
        {0,  1,  1},
        { 1, 0, 0},
        { 1, 0,  1},
        { 1,  1, 0},
    };


    size_t evensCount = 0;

    for (auto t : vertices)
    {
        evensCount += Permutation(t);
    }
    cout << evensCount << endl;

    //cout << Permutation({2, 4, 1, 3}) << endl;

    /*sort(vertices.begin(), vertices.end());
    for (auto t : vertices)
    {
        cout << VectorToString(t) << endl;
    }*/
}