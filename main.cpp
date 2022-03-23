#include "PrimeNumbersBuild.hpp"
#include <iostream>
#include <ostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    int k;

    try 
    {
        n = std::stoi(argv[1]);
        if(n > 2)
        {
            static PrimeNumbers *arr = new PrimeNumbers(n);
            for (int i = 2; i < argc; i++)
            {
                try
                {
                    k = std::stoi(argv[i]);
                    int j = 0;
                    for(unsigned int b = 2; b < unsigned(n); b++)
                    {
                        if(arr->primes[b])
                        {
                            j++;
                        }
                    }
                    if(k >= j || k < 0)
                    {
                        cout << argv[i] << " - liczba spoza zakresu" << endl;
                    }
                    else 
                    {
                        cout << argv[i] << " - ";
                        unsigned int m = arr->liczba(k);
                        cout << m << endl;
                    }
            }
            catch (exception)
            {
                cout << argv[i] << " - nieprawidłowa dana" << endl;
            }
        }
        delete arr;
        }
        else 
        {
            cout << argv[0] << " - Nieprawidłowy zakres" << endl;
        }
    } 
    catch (exception)
    {
        cout << "Nieprawidłowy zakres" << endl;
    }
}