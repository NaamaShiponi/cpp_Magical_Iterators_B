#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP
#include <vector>
#include <set>
using namespace std;

namespace ariel
{

    class MagicalContainer
    {
        std::set<int> elements;
        std::vector<const int *> ascendingElements;
        std::vector<const int *> sideCrossElements;
        std::vector<const int *> primeElements;

    private:
        bool isPrime(int num);

    public:
        MagicalContainer(){};
        void addElement(int element);
        void removeElement(int element);
        int size() const { return elements.size(); }

        /* AscendingIterator */
        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:
            AscendingIterator(MagicalContainer &container) : container(container), index(0){};
            AscendingIterator(MagicalContainer &container, size_t index) : container(container), index(index){};
            AscendingIterator(const AscendingIterator &other) : container(other.container), index(other.index){};
            AscendingIterator(AscendingIterator &&other) noexcept : container(other.container), index(other.index){};
            ~AscendingIterator(){};

            AscendingIterator &operator++();
            int operator*() const;

            AscendingIterator &operator=(AscendingIterator &&other) noexcept;
            AscendingIterator &operator=(const AscendingIterator &other);


            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;

            AscendingIterator begin() 
            {
                return AscendingIterator(container, 0);
            }
            AscendingIterator end()
            {
                return AscendingIterator(container, container.ascendingElements.size());
            }
        };

        /* SideCrossIterator */
        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:
            SideCrossIterator(MagicalContainer &container) : container(container), index(0){};
            SideCrossIterator(MagicalContainer &container, size_t index) : container(container), index(index){};
            SideCrossIterator(const SideCrossIterator &other) : container(other.container), index(other.index){};
            SideCrossIterator(SideCrossIterator &&other) noexcept : container(other.container), index(other.index){};
            ~SideCrossIterator(){};

            SideCrossIterator &operator++();
            int operator*() const;

            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            SideCrossIterator begin() 
            {
                return SideCrossIterator(container, 0);
            }
            SideCrossIterator end()
            {
                return SideCrossIterator(container, container.sideCrossElements.size());
            }
        };

        /* PrimeIterator */

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:
            PrimeIterator(MagicalContainer &container) : container(container), index(0){};
            PrimeIterator(MagicalContainer &container, size_t index) : container(container), index(index){};
            PrimeIterator(const PrimeIterator &other) : container(other.container), index(other.index){};
            PrimeIterator(PrimeIterator &&other) noexcept: container(other.container), index(other.index){};
            ~PrimeIterator(){};

            PrimeIterator &operator++();
            int operator*() const;

            PrimeIterator &operator=(PrimeIterator &&other) noexcept;
            PrimeIterator &operator=(const PrimeIterator &other);


            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;

            PrimeIterator begin() 
            {
                return PrimeIterator(container, 0);
            }
            PrimeIterator end() 
            {
                return PrimeIterator(container, container.primeElements.size());
            }
        };
    };

}
#endif