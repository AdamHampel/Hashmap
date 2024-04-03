#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <string>


class HashMap
{
public:
    typedef std::function<unsigned int(const std::string&)> HashFunction;

    // This constant specifies the number of buckets that a HashMap will
    // have when it is initially constructed.
    static constexpr unsigned int initialBucketCount = 10;


public:
    // This constructor initializes the HashMap to use whatever default
    // hash function you'd like it to use.  
    HashMap();

    // This constructor instead initializes the HashMap to use a particular
    // hash function instead of the default.  
    HashMap(HashFunction hasher);

    // The "Big Three" need to be implemented appropriately, so that HashMaps
    // can be created, destroyed, copied, and assigned without leaking
    // resources, interfering with one another, or causing crashes or
    // undefined behavior.
    HashMap(const HashMap& hm);
    ~HashMap();
    HashMap& operator=(const HashMap& hm);

    // add() takes a key and a value.  If the key is not already stored in
    // this HashMap, the key/value pair is added; if the key is already
    // stored, the function has no effect.
    //
    // If adding the new key/value pair will cause the load factor of this
    // HashMap to exceed 0.8, the following must happen:
    void add(const std::string& key, const std::string& value);

    // remove() takes a key and removes it (and its associated value) from
    // this HashMap if it is already present; if not, the function has no
    // effect.
    void remove(const std::string& key);

    // contains() returns true if the given key is in this HashMap, false
    // if not.
    bool contains(const std::string& key) const;

    // value() returns the value associated with the given key in this HashMap
    // if the key is stored in this HashMap; if not, the empty string is
    // returned.
    std::string value(const std::string& key) const;

    // size() returns the number of key/value pairs stored in this HashMap.
    unsigned int size() const;

    // bucketCount() returns the number of buckets currently allocated in
    // this HashMap.
    unsigned int bucketCount() const;

    // loadFactor() returns the proportion of the number of key/value pairs
    // to the number of buckets, a measurement of how "full" the HashMap is.
    // For example, if there are 20 key/value pairs and 50 buckets, we would
    // say that the load factor is 20/50 = 0.4.
    double loadFactor() const;

    // maxBucketSize() returns the number of key/value pairs stored in this
    // HashMap's largest bucket.
    unsigned int maxBucketSize() const;

    //Print self
    void printSelf();

private:
    // This structure describes the nodes that make up the linked lists in
    // each of this HashMap's buckets.
    struct Node
    {
        std::string key;
        std::string value;
        Node* next;
    };

    void copyBuckets(Node** source, Node** destination, unsigned int size);

    void rebuildMap(Node** oldBuckets, unsigned int oldNumBuckets);


    // Store the hash function (either the default hash function or the one
    // passed to the constructor as a parameter) in this member variable.
    HashFunction hasher;


    // You will no doubt need to add at least a few more private members
    Node** buckets;

    unsigned int numBuckets;
    unsigned int numItems;


};



#endif // HASHMAP_HPP
