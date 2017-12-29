#include "MySet.h"

/**
 * This class represents a single element in the set
 */
class MyNode
{

public:

    /**
     * Constructor.
     * @param key the key of the new element.
     * @param data the data of the new element.
     */
    MyNode(std::string key, double data);

    /**
     * default constructor.
     */
    MyNode();

    // a pointer to the next element
    MyNode* next;

    // the data of the element
    double data;

    // the key of the element
    std::string key;
};

/**
 * Constructor.
 * @param key the key of the new element.
 * @param data the data of the new element.
 */
MyNode::MyNode(std::string key, double data)
{
    this->key = key;
    this->data = data;
    this->next = nullptr;
}

/**
 * default constructor.
 */
MyNode::MyNode(){}

/******** MySet ******/


/**
 * Default constructor
 */
MySet::MySet()
{
    head = nullptr;
    weight = 0;
}

/**
 * copy constructor
 * @param other the object to copy
 */
MySet::MySet(const MySet &other)
{
    MyNode* currentNode = other.head;
    while (currentNode != nullptr)
    {
        this->add(currentNode->key, currentNode->data);
        currentNode = currentNode->next;
    }
}

/**
 * Destructor
 */
MySet::~MySet()
{
    MyNode* currNode = this->head;
    while (currNode != nullptr)
    {
        MyNode* next = currNode->next;
        delete(currNode);
        currNode = next;
    }
}

/**
 * Return true if the element is in the Set, or false otherwise.
 * If the element exists in the Set, return in 'data' its appropriate data
 * value. Otherwise don't change the value of 'data'.
 * @param key the key of the element to search
 * @param data the data of the element to search
 * @return true iff the element is in the set
 */
bool MySet::isInSet(std::string key, double &data)
{
    MyNode* currNode = _findNode(key);
    if (currNode != nullptr)
    {
        // node is in the set
        data = currNode->data;
        return true;
    }
    return false;
}

/**
 * Adds a new element to the set
 * @param key the key of the element
 * @param data the data of the element
 */
void MySet::add(const std::string &key, double data)
{
    MyNode* node = _findNode(key);
    if (node != nullptr)
    {
        node->data = data;
        return;
    }
    // node was not found
    MyNode* newNode = new MyNode(key, data);
    newNode->next = this->head;
    this->head = newNode;
    weight++;
}

/**
 * Remove a string from the MySet.
 * Return the number of removed elements (0/1)
 * @param str
 * @return
 */
int MySet::remove(const std::string &str)
{
    MyNode * currNode = this->head;
    MyNode * prevNode = nullptr;
    if (weight == 0)
    {
        return 0;
    }
    for (; currNode != nullptr; currNode = currNode->next)
    {
        if (currNode->key == str)
        {
            weight--;
            if (prevNode == nullptr)
                // the head is being removed
            {
                this->head = this->head->next;
            }
            else if (currNode->next == nullptr)
                // the tail is being removed
            {
                prevNode->next = nullptr;
            }
            else
            {
                // some node in the middle is being removed
                prevNode->next = currNode->next;
            }
            delete(currNode);
            return 1;
        }
        prevNode = currNode;
    }
    // nothing was found
    return 0;
}

/**
 * @return the total myHashFunction weight of all the Set keys
 */
int MySet::totWeight() const
{
    unsigned int sum = 0;
    MyNode * currNode = this->head;
    if (currNode == nullptr)
    {
        return 0;
    }
    for (; currNode != nullptr; currNode = currNode->next)
    {
        std::string str = currNode->key;
        sum += myHashFunction(str);
    }
    return sum;
}

/**
 * The hash function.
 * Input parameter - any C++ string.
 * Return value: the hash value - the sum of all the characters of the string
 *   (according to their ASCII value) modulus HASH_SIZE. The hash value of the
 *   empty string is 0 (since there are no characters, their sum according to
 *   the ASCII value is 0).
 * NOTE: In a better design the function would have belong to the string class
 *	 (or to a class that is derived from std::string). We implement it as a "stand
 *	 alone" function since you didn't learn inheritance yet. Keep the function
 *	 global (it's important to the automatic tests).
 */
int MySet::myHashFunction(const std::string &str)
{
    unsigned int sum = 0;
    unsigned int i;
    for (i = 0; i < str.length(); ++i)
    {
        sum += str.at(i);
    }
    return sum;
}

/**
 * @return the sum of all data elements stored in the Set.
 */
double MySet::sumSet() const
{
    double sum = 0;
    MyNode * currNode = this->head;
    if (currNode == nullptr)
    {
        return 0;
    }
    for (; currNode != nullptr; currNode = currNode->next)
    {
        sum += currNode->data;
    }
    return sum;
}

/**
 * gets a key of element and returns this element
 */
MyNode* MySet::_findNode(const std::string& key) const
{
    MyNode * currNode = this->head;
    if (currNode == nullptr)
    {
        return nullptr;
    }
    for (; currNode != nullptr; currNode = currNode->next)
    {
        if (currNode->key == key)
        {
            return currNode;
        }
    }
    return nullptr;
}

/************** operators **************/

/**
 * @param other the set to compare this to.
 * @return true iff this.key hash value is greater than other.key
 */
bool MySet::operator>(const MySet &other) const
{
    return this->totWeight() > other.totWeight();
}

/**
 * @param other the set to compare this to.
 * @return true iff this.key hash value is smaller than other.key
 */
bool MySet::operator<(const MySet &other) const
{
    return this->totWeight() < other.totWeight();
}

/**
 * @param other the set to compare this to.
 * @return true iff this.key hash value is equal to other.key
 */
bool MySet::operator==(const MySet &other) const
{
    return this->totWeight() == other.totWeight();
}

/**
 * @param other the set to copy
 * @return deep copy other
 */
MySet& MySet::operator=(const MySet& other)
{
    if (this == &other)
    {
        return *this;
    }
    while (weight > 0)
    {
        this->remove(this->head->key);
    }
    MyNode* currentNode = other.head;
    while (currentNode != nullptr)
    {
        this->add(currentNode->key, currentNode->data);
        currentNode = currentNode->next;
    }
    return *this;
}

/**
 * @param other the set to operate on.
 * @return another set that has all the elements of this, that are not in other.
 */
MySet MySet::operator-(const MySet &other)
{
    MySet set;
    MyNode* currNode = this->head;
    for (; currNode != nullptr; currNode = currNode->next)
    {
        // adding all the nodes that are in the left set but not in the right
        if (other._findNode(currNode->key) == nullptr)
        {
            set.add(currNode->key, currNode->data);
        }
    }
    return set;
}

/**
 * @param other the set to operate on.
 * @return another set that has all the elements of this, and all the element of other that
 * are not in this.
 */
MySet MySet::operator|(const MySet &other)
{
    MySet set;
    MyNode* currNode = this->head;
    for (; currNode != nullptr; currNode = currNode->next)
    {
        // adding all the nodes from the left set
        set.add(currNode->key, currNode->data);
    }
    currNode = other.head;
    for (; currNode != nullptr; currNode = currNode->next)
    {
        // adding all the nodes that are in the right set, but not in the left
        if (!this->_findNode(currNode->key))
        {
            set.add(currNode->key, currNode->data);
        }
    }
    return set;
}

/**
 * @param other the set to operate on.
 * @return another set that has all the elements of this that are also in other.
 */
MySet MySet::operator&(const MySet &other)
{
    MySet set;
    MyNode* currNode = this->head;
    for (; currNode != nullptr; currNode = currNode->next)
    {
        // adding all the nodes that are in the left set and also in the right
        if (other._findNode(currNode->key) != nullptr)
        {
            set.add(currNode->key, currNode->data);
        }
    }
    return set;
}

/**
 * print set contents.
 */
void MySet::printSet() const
{
    if (weight == 0)
    {
        std::cout << "EMPTY" << std::endl;
        return;
    }

    MyNode arr[weight];
    MyNode * temp = this->head;
    int count = 0;
    // initializing the array that we will later sort and print
    while (temp != nullptr)
    {
        arr[count++] = *temp;
        temp = temp->next;
    }
    int i, j;

    // sorting the array by insertion sort:
    for (i = 0; i < weight; ++i)
    {
        for (j = i + 1; j < weight; ++j)
        {
            if (myHashFunction(arr[j].key) <= myHashFunction(arr[i].key))
            {
                MyNode helper = arr[i];
                arr[i] = arr[j];
                arr[j] = helper;
            }
        }
    }
    // now the actual printing:
    int k;
    for (k = 0; k < weight; k++)
    {
        std::cout << arr[k].key << "," << arr[k].data << std::endl;
    }
}

/**
 * @return the cardinality of the set.
 */
int MySet::size() const
{
    return weight;
}