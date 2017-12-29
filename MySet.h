/**
 * MySet.h
 *
 * --------------------------------------------------------------------------------------
 * General: This class represents a Set, a data structure of distinct objects 
 *
 *  Methods: 
 *   MySet() - Constructor
 *  ~MySet()         - Destructor
 *
 *  add                  - Add a string to the MySet. and add the element to
 *                         the begin of of the data structure.
 *                         If the element already exists , change its data to the
 *                         input parameter. 
 *
 *  remove               - Remove a string from the MySet. 
 *                         Return the numbr of removed elements (0/1)
 *
 *  isInSet            - Return true if the element is in the Set, or false otherwise.
 *                         If the element exists in the Set, return in 'data' its appropriate data
 *                         value. Otherwise don't change the value of 'data'.
 *
 *  size                 - Return number of elements stored in the Set.
 *
 *  sumSet              - Return sum of all data elements stored in the Set.
 *
 *  printSet             - print Set contents.
 *
 *
 *  totWeight            - Return the total myHashFunction weight of all the Set keys
 *
 * --------------------------------------------------------------------------------------
 */
#ifndef MY_SET_H
#define MY_SET_H

#include <iostream>

class MyNode;
/**
 * The definition of the Set
 */
class MySet
{
public:

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
	static int myHashFunction(const std::string &str);

    /**
     * Default constructor
     */
    MySet();

    /**
     * copy constructor
     * @param other the object to copy
     */
    MySet(const MySet& other);

    /**
     * Destructor
     */
    ~MySet();

    /**
     * Return true if the element is in the Set, or false otherwise.
     * If the element exists in the Set, return in 'data' its appropriate data
     * value. Otherwise don't change the value of 'data'.
     * @param key the key of the element to search
     * @param data the data of the element to search
     * @return true iff the element is in the set
     */
    bool isInSet(const std::string key, double& data);

    /**
     * Adds a new element to the set
     * @param key the key of the element
     * @param data the data of the element
     */
    void add(const std::string &key, double data);

    /**
     * Remove a string from the MySet.
     * Return the number of removed elements (0/1)
     * @param str
     * @return
     */
    int remove(const std::string &str);

    /**
     * @return the total myHashFunction weight of all the Set keys
     */
    int totWeight() const;

    /**
     * @return the sum of all data elements stored in the Set.
     */
    double sumSet() const;

    /**
     * print set contents.
     */
    void printSet() const;

    /**
     * @return the cardinality of the set.
     */
    int size() const;

    /**** operators ****/

    /**
     * @param other the set to compare this to.
     * @return true iff this.key hash value is greater than other.key
     */
    bool operator>(const MySet& other) const;

    /**
     * @param other the set to compare this to.
     * @return true iff this.key hash value is smaller than other.key
     */
    bool operator<(const MySet& other) const;

    /**
     * @param other the set to compare this to.
     * @return true iff this.key hash value is equal to other.key
     */
    bool operator==(const MySet& other) const;

    /**
     * @param other the set to operate on.
     * @return another set that has all the elements of this, that are not in other.
     */
    MySet operator-(const MySet& other);

    /**
     * @param other the set to operate on.
     * @return another set that has all the elements of this, and all the element of other that
     * are not in this.
     */
    MySet operator|(const MySet& other);

    /**
     * @param other the set to operate on.
     * @return another set that has all the elements of this that are also in other.
     */
    MySet operator&(const MySet& other);

    /**
     * @param other the set to copy
     * @return deep copy other
     */
    MySet& operator=(const MySet& other);

private:

    friend class MyNode;

    // gets a key of element and returns this element
    MyNode* _findNode(const std::string &key) const;

    // the head of the linked list
    MyNode* head;

    // number of element in the set
    int weight;
};

#endif