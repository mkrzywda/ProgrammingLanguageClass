#include "BST.h"
#include <iostream>

int instanceCount = 0; // Licznik instancji drzew (static)


void* Node::operator new(size_t size) {
    return ::new char[size];
}

void Node::operator delete(void* ptr) {
    ::delete[] static_cast<char*>(ptr);
}

// === CREATION ===
void initTree(struct BST* tree) {
    tree->root = nullptr;
    instanceCount++; // Inkrementacja licznika instancji
}

// === TRAVERSING ===
void preOrder(struct Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// === SEARCH ===
bool searchRec(struct Node* node, int val) {
    if (!node) return false;
    if (node->data == val) return true;
    if (val < node->data) {
        return searchRec(node->left, val);
    }
    return searchRec(node->right, val);
}

bool search(struct BST* tree, int val) {
    return searchRec(tree->root, val);
}

// === INSERTION ===
void insertRec(struct Node** node, struct Node* parent, int val) {
    if (!*node) {
        *node = new Node;
        (*node)->data = val;
        (*node)->left = nullptr;
        (*node)->right = nullptr;
        (*node)->parent = parent;
        return;
    }
    if (val < (*node)->data) {
        insertRec(&(*node)->left, *node, val);
    } else if (val > (*node)->data) {
        insertRec(&(*node)->right, *node, val);
    }
}

void insert(struct BST* tree, int val) {
    insertRec(&tree->root, nullptr, val);
}

// === DELETION ===
void removeRec(struct BST* tree, struct Node** node, int val) {
    if (!*node) return;

    if (val < (*node)->data) {
        removeRec(tree, &(*node)->left, val);
    } else if (val > (*node)->data) {
        removeRec(tree, &(*node)->right, val);
    } else {
        if (!(*node)->left && !(*node)->right) {
            delete *node;
            *node = nullptr;
        } else if (!(*node)->left) {
            struct Node* temp = *node;
            *node = (*node)->right;
            if (*node) (*node)->parent = (*node)->parent;
            delete temp;
        } else if (!(*node)->right) {
            struct Node* temp = *node;
            *node = (*node)->left;
            if (*node) (*node)->parent = (*node)->parent;
            delete temp;
        } else {
            struct Node* successor = findMin((*node)->right);
            (*node)->data = successor->data;
            removeRec(tree, &(*node)->right, successor->data);
        }
    }
}

void remove(struct BST* tree, int val) {
    removeRec(tree, &tree->root, val);
}

// === UTILITY ===
int height(struct Node* node) {
    if (!node) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int size(struct Node* node) {
    if (!node) return 0;
    return 1 + size(node->left) + size(node->right);
}

void printTreeRec(struct Node* node, int level, const std::string& prefix) {
    if (!node) return;

    // Right subtree
    printTreeRec(node->right, level + 1, prefix + "    ");

    // Current node
    std::cout << prefix;
    if (level > 0) {
        std::cout << (node->parent && node == node->parent->right ? "┌── " : "└── ");
    }
    std::cout << "\033[1;34m" << node->data << "\033[0m" << std::endl;

    // Left subtree
    printTreeRec(node->left, level + 1, prefix + "    ");
}

void printTree(struct BST* tree) {
    if (!tree->root) {
        std::cout << "\033[1;31mDrzewo jest puste\033[0m" << std::endl;
        return;
    }
    std::cout << "\033[1;32m=== Struktura drzewa BST ===\033[0m" << std::endl;
    printTreeRec(tree->root, 0, "");
    std::cout << "\033[1;33mPre-order:\033[0m ";
    preOrder(tree->root);
    std::cout << "\n\033[1;33mWysokość:\033[0m " << height(tree->root) << std::endl;
    std::cout << "\033[1;33mLiczba węzłów:\033[0m " << size(tree->root) << std::endl;
}



struct BST globalTree;
