#include <iostream>
#include "BST.h"

// Funkcja do rekurencyjnego usuwania drzewa
void clearTree(struct Node* node) {
    if (!node) return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

int main() {
    // Tworzenie czterech instancji drzew
    struct BST tree1, tree2, tree3, tree4;
    
    // Inicjalizacja drzew
    initTree(&tree1);
    initTree(&tree2);
    initTree(&tree3);
    initTree(&tree4);

    // Wstawianie wartości do drzewa 1
    insert(&tree1, 7);
    insert(&tree1, 3);
    insert(&tree1, 18);
    insert(&tree1, 10);
    insert(&tree1, 22);
    insert(&tree1, 8);
    insert(&tree1, 11);
    insert(&tree1, 26);
    insert(&tree1, 2);
    insert(&tree1, 6);

    // Wstawianie wartości do drzewa 2
    insert(&tree2, 15);
    insert(&tree2, 10);
    insert(&tree2, 20);
    insert(&tree2, 5);
    insert(&tree2, 12);

    // Wstawianie wartości do drzewa 3
    insert(&tree3, 50);
    insert(&tree3, 30);
    insert(&tree3, 70);
    insert(&tree3, 60);
    insert(&tree3, 80);

    // Wstawianie wartości do drzewa 4
    insert(&tree4, 1);
    insert(&tree4, 2);
    insert(&tree4, 3);

    search(&tree4, 1)


    // Wyświetlanie liczby instancji
    std::cout << "\033[1;36mLiczba instancji drzew: " << getInstanceCount() << "\033[0m\n" << std::endl;

    // Wyświetlanie wszystkich drzew
    std::cout << "Drzewo 1 (przed usunięciem):" << std::endl;
    printTree(&tree1);
    std::cout << "\nDrzewo 2 (przed usunięciem):" << std::endl;
    printTree(&tree2);
    std::cout << "\nDrzewo 3:" << std::endl;
    printTree(&tree3);
    std::cout << "\nDrzewo 4:" << std::endl;
    printTree(&tree4);

    // Usuwanie węzłów z drzewa 1
    std::cout << "\n\033[1;35mUsuwanie węzłów 18, 3, 11 z drzewa 1\033[0m" << std::endl;
    remove(&tree1, 18);
    remove(&tree1, 3);
    remove(&tree1, 11);

    // Usuwanie węzłów z drzewa 2
    std::cout << "\n\033[1;35mUsuwanie węzłów 10, 20 z drzewa 2\033[0m" << std::endl;
    remove(&tree2, 10);
    remove(&tree2, 20);

    // Wyświetlanie drzew po usunięciu
    std::cout << "\nDrzewo 1 (po usunięciu):" << std::endl;
    printTree(&tree1);
    std::cout << "\nDrzewo 2 (po usunięciu):" << std::endl;
    printTree(&tree2);

    // Dodawanie nowych wartości do drzewa 1
    std::cout << "\n\033[1;35mDodawanie wartości 15, 19 do drzewa 1\033[0m" << std::endl;
    insert(&tree1, 15);
    insert(&tree1, 19);

    // Dodawanie nowych wartości do drzewa 2
    std::cout << "\n\033[1;35mDodawanie wartości 7, 25 do drzewa 2\033[0m" << std::endl;
    insert(&tree2, 7);
    insert(&tree2, 25);

    // Wyświetlanie drzew po dodaniu
    std::cout << "\nDrzewo 1 (po dodaniu):" << std::endl;
    printTree(&tree1);
    std::cout << "\nDrzewo 2 (po dodaniu):" << std::endl;
    printTree(&tree2);

    // Usuwanie wszystkich drzew
    std::cout << "\n\033[1;35mUsuwanie wszystkich drzew\033[0m" << std::endl;
    clearTree(tree1.root);
    clearTree(tree2.root);
    clearTree(tree3.root);
    clearTree(tree4.root);
    resetInstanceCount(); // Reset licznika instancji po usunięciu drzew

    // Wyświetlanie liczby instancji po usunięciu
    std::cout << "\n\033[1;36mLiczba instancji po usunięciu drzew: " << getInstanceCount() << "\033[0m" << std::endl;

    return 0;
}


// Liczba instancji drzew: 4

// Drzewo 1 (przed usunięciem):
// === Struktura drzewa BST ===
//             ┌── 26
//         ┌── 22
//     ┌── 18
//             ┌── 11
//         └── 10
//             └── 8
// 7
//         ┌── 6
//     └── 3
//         └── 2
// Pre-order: 7 3 2 6 18 10 8 11 22 26
// Wysokość: 4
// Liczba węzłów: 10

// Drzewo 2 (przed usunięciem):
// === Struktura drzewa BST ===
//     ┌── 20
// 15
//         ┌── 12
//     └── 10
//         └── 5
// Pre-order: 15 10 5 12 20
// Wysokość: 3
// Liczba węzłów: 5

// Drzewo 3:
// === Struktura drzewa BST ===
//         ┌── 80
//     ┌── 70
//         └── 60
// 50
//     └── 30
// Pre-order: 50 30 70 60 80
// Wysokość: 3
// Liczba węzłów: 5

// Drzewo 4:
// === Struktura drzewa BST ===
//         ┌── 3
//     ┌── 2
// 1
// Pre-order: 1 2 3
// Wysokość: 3
// Liczba węzłów: 3

// Usuwanie węzłów 18, 3, 11 z drzewa 1

// Usuwanie węzłów 10, 20 z drzewa 2

// Drzewo 1 (po usunięciu):
// === Struktura drzewa BST ===
//         ┌── 26
//     ┌── 22
//         └── 10
//             └── 8
// 7
//     └── 6
//         └── 2
// Pre-order: 7 6 2 22 10 8 26
// Wysokość: 4
// Liczba węzłów: 7

// Drzewo 2 (po usunięciu):
// === Struktura drzewa BST ===
// 15
//     └── 12
//         └── 5
// Pre-order: 15 12 5
// Wysokość: 3
// Liczba węzłów: 3

// Dodawanie wartości 15, 19 do drzewa 1

// Dodawanie wartości 7, 25 do drzewa 2

// Drzewo 1 (po dodaniu):
// === Struktura drzewa BST ===
//         ┌── 26
//     ┌── 22
//                 ┌── 19
//             ┌── 15
//         └── 10
//             └── 8
// 7
//     └── 6
//         └── 2
// Pre-order: 7 6 2 22 10 8 15 19 26
// Wysokość: 5
// Liczba węzłów: 9

// Drzewo 2 (po dodaniu):
// === Struktura drzewa BST ===
//     ┌── 25
// 15
//     └── 12
//             ┌── 7
//         └── 5
// Pre-order: 15 12 5 7 25
// Wysokość: 4
// Liczba węzłów: 5

// Usuwanie wszystkich drzew

// Liczba instancji po usunięciu drzew: 0
