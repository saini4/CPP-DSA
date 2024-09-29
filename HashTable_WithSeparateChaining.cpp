/*
 * Hash Table Implementation
 *
 * This implementation uses separate chaining for collision resolution.
 *
 * Classes:
 * - Node: Represents an item with its name and price, and a pointer to the next node.
 * - HashTable: Manages the array of nodes and implements insertion, deletion, and searching.
 *
 * Time Complexities:
 * - Insert: O(1) on average; O(n) in the worst case (if all items hash to the same index).
 * - Remove: O(1) on average; O(n) in the worst case.
 * - Search: O(1) on average; O(n) in the worst case.
 *
 * Space Complexity: O(n) for storing n items.
 */

#include <iostream>
#include <cstring>
#define MAX_ITEM 10
#define MAX_SIZE 6

class Node
{
public:
    char item[MAX_ITEM];
    int price;
    Node *next;

    Node(const char *itemName, int cost)
    {
        strcpy(this->item, itemName);
        this->price = cost;
        this->next = nullptr;
    }
};

class HashTable
{
private:
    Node *table[MAX_SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            table[i] = nullptr;
        }
    }

    unsigned int hashFunction(const char *itemName)
    {
        unsigned int hashValue = 0;
        for (int i = 0; itemName[i] != '\0'; i++)
        {
            hashValue += itemName[i];
        }
        return hashValue % MAX_SIZE;
    }

    void insert(const char *itemName, int cost)
    {
        unsigned int index = hashFunction(itemName);
        Node *newNode = new Node(itemName, cost);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void remove(const char *itemName)
    {
        unsigned int index = hashFunction(itemName);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (strcmp(itemName, current->item) == 0)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                std::cout << "Item deleted: " << itemName << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        std::cout << "Item not found for deletion" << std::endl;
    }

    int search(const char *itemName)
    {
        unsigned int index = hashFunction(itemName);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (strcmp(itemName, current->item) == 0)
            {
                return current->price;
            }
            current = current->next;
        }
        std::cout << "Item not found" << std::endl;
        return -1;
    }
    void display()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            std::cout << "Index " << i << ": ";
            while (current != nullptr)
            {
                std::cout << current->item << " (" << current->price << ") -> ";
                current = current->next;
            }
            std::cout << "NULL" << std::endl;
        }
    }
};

int main()
{
    HashTable ht;

    ht.insert("Apple", 99);
    ht.insert("Banana", 49);
    ht.insert("Orange", 79);
    ht.insert("Milk", 49);
    ht.insert("Bread", 99);
    ht.insert("Eggs", 49);
    ht.insert("Cheese", 99);
    ht.display();

    std::cout << "Price of Orange: " << ht.search("Orange") << std::endl;
    ht.remove("Orange");
    ht.display();

    return 0;
}
