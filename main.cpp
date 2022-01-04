#include "header.h"

int main()
{
	linked_list lista1;
	linked_list lista2;
	
	cout << "Uppgift 1 - Fyll två länkade listor med 100 stigande slumptal vardera" << endl;
	for (int i = 1; i <= 100; i++)
	{
		lista1.push_back(lista1.back() + rand()% 20);
		lista2.push_back(lista2.back() + rand()% 20);
	}
	cout << "Lista 1: " << endl;
    lista1.print();
    cout << "\n" << endl;
	cout << "Lista 2:" << endl;
	lista2.print();
	cout << "\n" << endl;
	
	cout << "Uppgift 2 - Kontrollera vilken lista var 50:e element är störst" << endl;
	double störstTal = 0;
	if(lista1.at(50) < lista2.at(50))
	{
		störstTal = lista2.at(50);
		cout << "Lista 2 har det största talet: " << störstTal << "\n" << endl;
	}
	else if(lista1.at(50) > lista2.at(50))
	{
		störstTal = lista1.at(50);
		cout << "Lista 1 har det största talet: " << störstTal << "\n" << endl;
	}
	else if(lista1.at(50) == lista2.at(50))
	{
		störstTal = lista2.at(50);
		cout << "Båda listorna har samma tal på plats 50: " << störstTal << "\n" << endl;
	}
	
	cout << "Uppgift 3 - Ta bort det större av elementen" << endl;
    if(lista1.at(50) > lista2.at(50))
    {
		lista1.remove(50);
		lista1.print();
	}
    else if(lista1.at(50) < lista2.at(50))
    {
		lista2.remove(50);
		lista2.print();
	}
	else if (lista1.at(50) == lista2.at(50))
	{
		cout << "Talen på plats 50 är lika stor i båda listorna!" << endl;
	}
	cout << "\n" << endl;

	cout << "Uppgift 4 - Deklarera en tredje lista. Tilldela därefter lista 1 till den tredje listan" << endl;
	linked_list lista3;
	lista3 = lista1;
    cout << "Lista 3: " << endl;
	lista3.print();
	cout << "\n" << endl;

	cout << "Uppgift 5 - Ta bort varannat element genom att iterera 50 gånger" << endl;
	for (size_t i = 0; i < 50; ++i)
	{
		lista3.pop_back();
		lista3.push_front(lista3.pop_back());
	}
	lista3.print();
	cout << "\n" << endl;
	
	cout << "Uppgift 6 - Skapa och anropa en global funktion som skriver ut innehållet i tredje listan" << endl;
	print_list(lista3);
	cout << "\n" << endl;

	cout << "Uppgift 7 - Skapa en fjärde lista. Kombinera lista 1 och lista 2 till den fjärde listan" << endl;
	linked_list lista4;
	lista4.merge(lista1,lista2);
	lista4.print();
	cout << "\n" << endl;

	cout << "Uppgift 8 - Kontrollera att lista 4 är sorterad" << endl;
	lista4.sort(lista4);
	
    return 0;
}