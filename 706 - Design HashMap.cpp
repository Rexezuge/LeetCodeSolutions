#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
  template <class KeyType, class ValueType>
  struct Node {
    KeyType mKey;
    ValueType mValue;
    shared_ptr<Node<KeyType, ValueType>> mLeft;
    shared_ptr<Node<KeyType, ValueType>> mRight;
    Node() noexcept : mKey(0), mValue(0), mLeft(nullptr), mRight(nullptr) {}
    explicit Node(KeyType key, ValueType val) noexcept
        : mKey(key), mValue(val), mLeft(nullptr), mRight(nullptr) {}
    explicit Node(KeyType key, ValueType val,
                  shared_ptr<Node<KeyType, ValueType>> left,
                  shared_ptr<Node<KeyType, ValueType>> right) noexcept
        : mKey(key), mValue(val), mLeft(left), mRight(right) {}
  };

  // Hash Map Bucket Size
  const int mBucketSize;
  // Hash Map Representation
  unique_ptr<shared_ptr<Node<int, int>>[]> mData;

  template <class KeyType, class ValueType>
  shared_ptr<Node<KeyType, ValueType>> insertNodeIntoTree(
      shared_ptr<Node<KeyType, ValueType>> root, KeyType key,
      ValueType val) noexcept {
    if (!root)
      // Key Not Exist, Creating New Node
      return shared_ptr<Node<KeyType, ValueType>>(
          new Node<KeyType, ValueType>(key, val));

    if (key == root->mKey) {
      // Key Matches, Set New Value
      root->mValue = val;
      return root;
    }

    // Insert in the Sub Tree
    key < root->mKey
        ? root->mLeft = insertNodeIntoTree(root->mLeft, key, val)
        : root->mRight = insertNodeIntoTree(root->mRight, key, val);

    // Return Current Node
    return root;
  }

  template <class KeyType, class ValueType>
  shared_ptr<Node<KeyType, ValueType>> searchNodeInTree(
      shared_ptr<Node<KeyType, ValueType>> root, KeyType key) noexcept {
    if (!root || key == root->mKey)
      // Key Not Exist || Key Matches
      return root;

    // Search Sub Tree
    return key < root->mKey ? searchNodeInTree(root->mLeft, key)
                            : searchNodeInTree(root->mRight, key);
  }

  template <class KeyType, class ValueType>
  shared_ptr<Node<KeyType, ValueType>> removeNodeInTree(
      shared_ptr<Node<KeyType, ValueType>> root, KeyType key) noexcept {
    if (!root) {
      // Base Case
      return nullptr;
    } else if (key < root->mKey) {
      // Search Left Sub Tree
      root->mLeft = removeNodeInTree(root->mLeft, key);
    } else if (key > root->mKey) {
      // Search Right Sub Tree
      root->mRight = removeNodeInTree(root->mRight, key);
    } else if (!root->mLeft && !root->mRight) {
      // No Children
      return nullptr;
    } else if (root->mLeft && root->mRight) {
      // Two Children
      shared_ptr<Node<KeyType, ValueType>> smallestNode = root->mRight;
      while (smallestNode->mLeft) smallestNode = smallestNode->mLeft;
      root->mKey = smallestNode->mKey, root->mValue = smallestNode->mValue;
      root->mRight = removeNodeInTree(root->mRight, smallestNode->mKey);
    } else {
      // One Child
      return root->mLeft ? root->mLeft : root->mRight;
    }

    // Return Current Node
    return root;
  }

 public:
  MyHashMap() noexcept
      : mBucketSize(100), mData(new shared_ptr<Node<int, int>>[mBucketSize]) {}

  void put(int key, int value) noexcept {
    const int hashKey = key % mBucketSize;
    mData[hashKey] = insertNodeIntoTree(mData[hashKey], key, value);
  }

  int get(int key) noexcept {
    const int hashKey = key % mBucketSize;
    shared_ptr<Node<int, int>> searchResult =
        searchNodeInTree(mData[hashKey], key);
    return searchResult ? searchResult->mValue : -1;
  }

  void remove(int key) noexcept {
    const int hashKey = key % mBucketSize;
    mData[hashKey] = removeNodeInTree(mData[hashKey], key);
  }
};
