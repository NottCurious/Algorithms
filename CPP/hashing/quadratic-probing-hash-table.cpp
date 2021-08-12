#include <cmath>
#include <iostream>
#include <vector>

namespace quadratic_probing
{
using Entry = struct Entry;

bool putProber(const Entry &entry, int key);
bool searchingProber(const Entry &entry, int key);
void add(int key);

int notPresent;
std::vector<Entry> table;
int totalSize;
int tomb = -1;
int size;
bool rehashing;

struct Entry
{
    explicit Entry(int key = notPresent) : key(key)
    {
    }
    int key;
};

size_t hashFxn(int key)
{
    std::hash<int> hash;
    return hash(key);
}

int quadraticProbe(int key, bool searching)
{
    int hash = static_cast<int>(hashFxn(key));
    int i = 0;
    Entry entry;

    do
    {
        size_t index = (hash + static_cast<size_t>(std::round(std::pow(i, 2)))) % totalSize;
        entry = table[index];

        if (searching)
        {
            if (entry.key == notPresent)
            {
                return notPresent;
            }
            if (searchingProber(entry, key))
            {
                std::cout << "Found key!" << std::endl;
                return index;
            }
            std::cout << "Found tombstone or equal hash, checking next" << std::endl;
            i++;
        }
        else
        {
            if (putProber(entry, key))
            {
                if (!rehashing)
                {
                    std::cout << "Spot Found" << std::endl;
                }

                return index;
            }
            if (!rehashing)
            {
                std::cout << "Spot taken, looking at next (Next index = "
                          << (hash + static_cast<size_t>(std::round(std::pow(i + 1, 2)))) % totalSize << std::endl;
            }
            i++;
        }

        if (i == totalSize * 100)
        {
            std::cout << "Quadratic probe failed (infinite loop)" << std::endl;
            return notPresent;
        }
    } while (entry.key != notPresent);
    return notPresent;
}

bool putProber(const Entry &entry, int key)
{
    if (entry.key == notPresent || entry.key == tomb)
    {
        return true;
    }

    return false;
}

bool searchingProber(const Entry &entry, int key)
{
    if (entry.key == key)
    {
        return true;
    }

    return false;
}

Entry find(int key)
{
    int index = quadraticProbe(key, true);
    if (index == notPresent)
    {
        return Entry();
    }

    return table[index];
}

void display()
{
    for (int i = 0; i < totalSize; i++)
    {
        if (table[i].key == notPresent)
        {
            std::cout << "Empty";
        }
        else if (table[i].key == tomb)
        {
            std::cout << "Tomb";
        }
        else
        {
            std::cout << std::endl << table[i].key;
        }
    }

    std::cout << std::endl;
}
} // namespace quadratic_probing