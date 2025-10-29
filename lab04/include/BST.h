#ifndef BST_H
#define BST_H

#include <cstddef> // For size_t
#include <string>  // For std::string

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;

    void* operator new(size_t size);
    void operator delete(void* ptr);
};

struct BST {
    struct Node* root;
};

extern struct BST globalTree;

// Creation
void initTree(struct BST* tree);

// Traversing
void preOrder(struct Node* node);
void printTree(struct BST* tree);
void printTreeRec(struct Node* node, int level, const std::string& prefix);

// Search
inline bool searchRec(struct Node* node, int val);
inline bool search(struct BST* tree, int val);

// Insertion
void insert(struct BST* tree, int val);
void insertRec(struct Node** node, struct Node* parent, int val);

// Deletion
void remove(struct BST* tree, int val);

// Utility
inline struct Node* findMin(struct Node* node) {
    if (!node || !node->left) return node;
    return findMin(node->left);
}
inline struct Node* findMax(struct Node* node) {
    if (!node || !node->right) return node;
    return findMax(node->right);
}
int height(struct Node* node);
int size(struct Node* node);

inline static int getInstanceCount() {
    extern int instanceCount;
    return instanceCount;
}
inline static void resetInstanceCount() {
    extern int instanceCount;
    instanceCount = 0;
}


#endif
