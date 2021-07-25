#include <iostream>
#include <vector>

namespace linear_probing
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

int linearProbe(int key, bool searching)
{
    int hash = static_cast<int>(hashFxn(key));
    int i = 0;

    Entry entry;

    do
    {
        int index = static_cast<int>((hash + i) % totalSize);
        entry = table[index];

        if (searching)
        {
            if (entry.key == notPresent)
            {
                return notPresent;
            }

            if (searchingProber(entry, key))
            {
                std::cout << "Key Found!" << std::endl;
                return index;
            }

            std::cout << "Equal Hash Found, Checking Next" << std::endl;
        }
        else
        {
            if (putProber(entry, key))
            {
                if (!rehashing)
                {
                    std::cout << "Found Spot!" << std::endl;
                }

                return index;
            }
            if (!rehashing)
            {
                std::cout << "Spot Taken, Checking Next" << std::endl;
            }
            i++;
        }

        if (i == totalSize)
        {
            std::cout << "Linear Probe Failed. Exiting" << std::endl;
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

void display()
{
    for (int i = 0; i < totalSize; i++)
    {
        if (table[i].key == notPresent)
        {
            std::cout << "Empty ";
        }
        else if (table[i].key == tomb)
        {
            std::cout << "Tomb ";
        }
        else
        {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

void rehash()
{
    rehashing = true;

    int oldSize = totalSize;

    std::vector<Entry> oldTable(table);

    totalSize *= 2;
    table = std::vector<Entry>(totalSize);

    for (int i = 0; i < oldSize; i++)
    {
        if (oldTable[i].key != -1 && oldTable[i].key != notPresent)
        {
            size--;
            add(oldTable[i].key);
        }
    }

    rehashing = false;
    std::cout << "table was rehashed, size: " << totalSize << std::endl;
}

void add(int key)
{
    int index = linearProbe(key, false);
    table[index].key = key;

    if (++size / static_cast<double>(totalSize) >= 0.5)
    {
        rehash();
    }
}

void remove(int key)
{
    int index = linearProbe(key, true);
    if (index == notPresent)
    {
        std::cout << "Key Not Found" << std::endl;
    }

    std::cout << "Removal Successful, Leaving" << std::endl;
    table[index].key = tomb;
    size--;
}

void addInfo(int key)
{
    std::cout << "Initial Table: ";
    display();
    std::cout << std::endl;
    std::cout << "hash of " << key << " is " << hashFxn(key) << " % " << totalSize
              << " == " << hashFxn(key) % totalSize;
    std::cout << std::endl;
    add(key);
    std::cout << "New Table: ";
    display();
}

void removalInfo(int key)
{
    std::cout << "Initial table: ";
    display();
    std::cout << std::endl;
    std::cout << "hash of " << key << " is " << hashFxn(key) << " % " << totalSize
              << " == " << hashFxn(key) % totalSize;
    std::cout << std::endl;
    remove(key);
    std::cout << "New table: ";
    display();
}
} // namespace linear_probing

using linear_probing::Entry;
using linear_probing::table;
using linear_probing::totalSize;

int main()
{
    int cmd = 0, hash = 0, key = 0;
    std::cout << "Enter the initial size of Hash Table. = ";
    std::cin >> totalSize;
    table = std::vector<Entry>(totalSize);
    bool loop = true;
    while (loop)
    {
        std::cout << std::endl;
        std::cout << "PLEASE CHOOSE -" << std::endl;
        std::cout << "1. Add key. (Numeric only)" << std::endl;
        std::cout << "2. Remove key." << std::endl;
        std::cout << "3. Find key." << std::endl;
        std::cout << "4. Generate Hash. (Numeric only)" << std::endl;
        std::cout << "5. Display Hash table." << std::endl;
        std::cout << "6. Exit." << std::endl;
        std::cin >> cmd;
        switch (cmd)
        {
        case 1:
            std::cout << "Enter key to add = ";
            std::cin >> key;
            linear_probing::addInfo(key);
            break;
        case 2:
            std::cout << "Enter key to remove = ";
            std::cin >> key;
            linear_probing::removalInfo(key);
            break;
        case 3: {
            std::cout << "Enter key to search = ";
            std::cin >> key;
            Entry entry = table[linear_probing::linearProbe(key, true)];
            if (entry.key == linear_probing::notPresent)
            {
                std::cout << "Key not present";
            }
            break;
        }
        case 4:
            std::cout << "Enter element to generate hash = ";
            std::cin >> key;
            std::cout << "Hash of " << key << " is = " << linear_probing::hashFxn(key);
            break;
        case 5:
            linear_probing::display();
            break;
        default:
            loop = false;
            break;
            // delete[] table;
        }
        std::cout << std::endl;
    }
    return 0;
}