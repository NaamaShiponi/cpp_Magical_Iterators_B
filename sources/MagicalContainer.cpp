
#include "MagicalContainer.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace ariel;

/* MagicalContainer */

void MagicalContainer::addElement(int element)
{
    auto it = elements.emplace(element).first;

    if (isPrime(element))
        primeElements.push_back(&(*it));

    ascendingElements.push_back(&(*it));

    // Sort ascendingElements
    std::sort(ascendingElements.begin(), ascendingElements.end(),
              [](const int* a, const int* b) { return *a < *b; });

    // Update sideCrossElements
    sideCrossElements.clear();
    size_t begin = 0;
    size_t end = (size_t)size() - 1;

    if (size() <= 1)
    {
        sideCrossElements.push_back(ascendingElements.at(0));
    }
    else
    {
        while (begin <= end && end >= 0)
        {
            sideCrossElements.push_back(ascendingElements.at(begin));

            if (begin !=end)
            {
                sideCrossElements.push_back(ascendingElements.at(end));
            }
            begin++;
            end--;
        }
    }
}



void MagicalContainer::removeElement(int element)
{
    if (size() == 0)
        return;

    auto it = elements.find(element);

    if (it != elements.end())
    {
        ascendingElements.erase(find(ascendingElements.begin(), ascendingElements.end(), &(*it)));

        sideCrossElements.erase(find(sideCrossElements.begin(), sideCrossElements.end(), &(*it)));

        if (isPrime(element))
            primeElements.erase(find(primeElements.begin(), primeElements.end(), &(*it)));

        elements.erase(element);
    }
    else
        throw runtime_error("Element Does not exist");
}

bool MagicalContainer::isPrime(int num)
{
    if (num < 2 || (num > 2 && num % 2 == 0))
        return false;
    if (num == 2)
        return true;
    for (int i = 3; i <= sqrt(num); i = i + 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

/* AscendingIterator */

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (index >= container.ascendingElements.size())
        throw runtime_error("Iterator Increment Beyond End");

    if (index <= container.size() - 1)
        index++;

    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    return *(container.ascendingElements.at(index));
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{

    if (&container != &other.container)
        throw runtime_error("operator= throws when iterators are pointing at different containers");

    index = other.index;

    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other)
{

    container = other.container;
    index = other.index;

    return *this;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{

    bool forReturn = index < other.index;
    return forReturn;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return !(*this < other) && !(*this == other);
}

/* SideCrossIterator */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (index >= container.sideCrossElements.size())
        throw runtime_error("Iterator Increment Beyond End");

    if (index <= container.size() - 1)
        ++index;

    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    return *(container.sideCrossElements[index]);
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other)
{

    container = other.container;
    index = other.index;

    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{

    if (&container != &other.container)
        throw runtime_error("operator= throws when iterators are pointing at different containers");

    container = other.container;
    index = other.index;

    return *this;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    bool forReturn = index < other.index;
    return forReturn;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return !(*this < other) && !(*this == other);
}

/* PrimeIterator */

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (index >= container.primeElements.size())
        throw runtime_error("Iterating over elements");

    if (index < container.size())
        ++index;

    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return *(container.primeElements[index]);
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (&container != &other.container)
        throw runtime_error("operator= throws when iterators are pointing at different containers");

    container = other.container;
    index = other.index;

    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other)
{

    container = other.container;
    index = other.index;

    return *this;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    bool forReturn = index < other.index;
    return forReturn;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return !(*this < other) && !(*this == other);
}
