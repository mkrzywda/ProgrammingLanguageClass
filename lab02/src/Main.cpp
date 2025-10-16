// 09.10.2025
// CWL 3 
// Laboratorium Język C++ - Zajęcia 2 
//
//Polecenie 
// Prosze napisać kod, który będzie implementował Stos i jego podstawowe funkcjonalności.
// W dostarczonym kodzie mogą państwo natrafić na: błędy - we wszystkich dostarczonych plikach - napraw/dopisz/usuń niepotrzebne rzeczy.
// Pliku Main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod)
// KISS - Keep It Simple Stupid - Kod powinien być tak prosty, jak to tylko możliwe. Co prawda likwidacja muchy za pomocą armaty może być widowiskowa, ale później i tak trzeba będzie posprzątać. 
// YANGI - You Aren’t Gonna Need It. - Co należy robić z kodem, którego nie potrzebujesz ? Bezwzględnie go usuwać. Nie przekształcać w komentarz, bo „może się potem przyda”. 
// DRY - Don’t Repeat Yourself. - Nie rób powtórzeń w kodzie źródłowym. Każdy programista i programistka powinien zauważać takie sytuacje niemal natychmiast – i sprawnie sobie z nimi radzić. 
//
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz o strukturze takiej jak w zadaniu na UPeL.
//
//
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem lab02/
// * katalog z zadaniem powinien zawierać podkatalog include/
//   w którym muszą znajdować się wszystkie niezbędne pliki nagłówkowe
// * katalog z zadaniem powinien zawierać podkatalog src/
//   w którym muszą znajdować się wszystkie niezbędne pliki z kodem źródłowym
// * katalog z zadaniem powinien zawierać podkatalog build/ 
//   w którym powinien znajdować się tylko i wyłącznie plik Makefile
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf lab01.tar.gz lab01/
// * rozpakowanie archiwum: tar -xvf nazwa.tar.gz
//
//
// * wszystkie funkcje w plikach *.h powinny być okomentowane (patrz przyklad w pliku StackOperations.h (format pod Doxygena))
// * do alokacji i dealokacji pamięci używaj operatorów: new i delete
//
// Powodzenia



#include <iostream>
#include "Stack.h"
#include "StackOperations.h"

int main(int argc, char** argv) 
{
    sstack Stack;
	
    init(&Stack);
    std::cout << "Top: " <<     value(&Stack)    << std::endl;

    push(&Stack, 'J');
    push(&Stack, 'e');
    push(&Stack, 'z');
    push(&Stack, 'y');
    push(&Stack, 'k');
    push(&Stack, ' ');
    push(&Stack, 'C');
    push(&Stack, '+');
    push(&Stack, '+');

    prints(&Stack);

    if (!empty(&Stack)) {
        std::cout << "Stack Size: " << size(&Stack) << std::endl;    
    };
    
    std::cout << "Top: " <<     value(&Stack)    << std::endl;

    pop(&Stack);
    prints(&Stack);

    std::cout << "Top: " <<     value(&Stack)    << std::endl;

    prints(&Stack);

    push(&Stack, 'A');
    push(&Stack, 'B');

    size(&Stack);

    prints(&Stack);

    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    prints(&Stack);


    size(&Stack);
    std::cout << "Top: " <<     value(&Stack)    << std::endl;
    pop(&Stack);

    std::cout << "Top: " <<     value(&Stack)    << std::endl;
    if (!empty(&Stack)) {
        std::cout << "Stack Size: " << size(&Stack) << std::endl;    
    };

    prints(&Stack);


    return 0;
}