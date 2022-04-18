#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
  template <class KeyType>
  struct Node {
    KeyType mKey;
    shared_ptr<Node<KeyType>> mLeft;
    shared_ptr<Node<KeyType>> mRight;
    Node() noexcept : mKey(0), mLeft(nullptr), mRight(nullptr) {}
    explicit Node(KeyType key) noexcept
        : mKey(key), mLeft(nullptr), mRight(nullptr) {}
    explicit Node(KeyType key, shared_ptr<Node<KeyType>> left,
                  shared_ptr<Node<KeyType>> right) noexcept
        : mKey(key), mLeft(left), mRight(right) {}
  };

  // Hash Map Bucket Size
  const int mBucketSize;
  // Hash Map Representation
  unique_ptr<shared_ptr<Node<int>>[]> mData;

  template <class KeyType>
  shared_ptr<Node<KeyType>> insertNodeIntoTree(shared_ptr<Node<KeyType>> root,
                                               KeyType key) noexcept {
    if (root == nullptr)
      // Key Not Exist, Creating New Node
      return shared_ptr<Node<KeyType>>(new Node<KeyType>(key));

    if (key == root->mKey)
      // Key Already Exist, Do Nothing
      return root;

    // Insert in the Sub Tree
    key < root->mKey ? root->mLeft = insertNodeIntoTree(root->mLeft, key)
                     : root->mRight = insertNodeIntoTree(root->mRight, key);

    // Return Current Node
    return root;
  }

  template <class KeyType>
  shared_ptr<Node<KeyType>> searchNodeInTree(shared_ptr<Node<KeyType>> root,
                                             KeyType key) noexcept {
    if (root == nullptr || key == root->mKey)
      // Key Not Exist || Key Matches
      return root;

    // Search Sub Tree
    return key < root->mKey ? searchNodeInTree(root->mLeft, key)
                            : searchNodeInTree(root->mRight, key);
  }

  template <class KeyType>
  shared_ptr<Node<KeyType>> removeNodeInTree(shared_ptr<Node<KeyType>> root,
                                             KeyType key) noexcept {
    if (root == nullptr) {
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
      shared_ptr<Node<KeyType>> smallestNode = root->mRight;
      while (smallestNode->mLeft) smallestNode = smallestNode->mLeft;
      root->mKey = smallestNode->mKey;
      root->mRight = removeNodeInTree(root->mRight, smallestNode->mKey);
    } else {
      // One Child
      return root->mLeft ? root->mLeft : root->mRight;
    }

    // Return Current Node
    return root;
  }

 public:
  MyHashSet() noexcept
      : mBucketSize(100), mData(new shared_ptr<Node<int>>[mBucketSize]) {}

  void add(int key) noexcept {
    const int hashKey = key % mBucketSize;
    mData[hashKey] = insertNodeIntoTree(mData[hashKey], key);
  }

  void remove(int key) noexcept {
    const int hashKey = key % mBucketSize;
    mData[hashKey] = removeNodeInTree(mData[hashKey], key);
  }

  bool contains(int key) noexcept {
    const int hashKey = key % mBucketSize;
    return searchNodeInTree(mData[hashKey], key) != nullptr;
  }
};
