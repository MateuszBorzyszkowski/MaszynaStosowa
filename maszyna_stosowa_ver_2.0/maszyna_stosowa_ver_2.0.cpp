#include <iostream>

using namespace std;

struct lista
{
	lista *next;
	int data;
};

class stos
{
private:
	lista *S;

public:
	stos(); //konstruktor
	~stos(); //destruktor

	void push(int v); // dodanie
	void pop(void); //usuwanie
	void wypisz(void); //wypisz
	void zamiana(void); //zamiana
	void zamiana_r(void); //zamiana_r
	void suma(void); //suma

};

stos::stos() //konstruktor
{
	S = NULL;
}

stos::~stos() //destruktor
{
	while (S) pop();
}

void stos::push(int v) //dodanie
{
	lista *e = new lista;
	e->data = v;
	e->next = S;
	S = e;
}

void stos::pop(void) //usuwanie
{
	if (S)
	{
		lista *e = S;
		S = S->next;
		delete e;
	}
}

void stos::wypisz(void) //wypisz
{
	lista *e = S;

	while (e)
	{
		cout << e->data << " ";
		e = e->next;
	}
}

void stos::zamiana(void) //zamiana
{
	if ((S) && (S->next))
	{
		lista *e = S->next;
		S->next = e->next;
		e->next = S;
		S = e;
	}

}

void stos::zamiana_r(void) //zamiana_r
{
	int tmp = S->data;
	pop();
	bool flaga2 = true;

	if ((S) && (S->next))
	{
		if ((tmp != 0) && (tmp != 1)) // jesli jest od 2 w gore, dla 1 i 0 sie nie wykonuje
		{
			lista *e = S;
			lista *b = S->next;
			for (int i = 0; i < tmp - 1; i++) 
			{
				if (e->next)
				{
					e = e->next;
				}
				else
				{
					flaga2 = false;
					break;
				}
			}
			if (flaga2)
			{
				S->next = e->next;
				e->next = S;
				S = b;
			}
		}
	}

}

void stos::suma(void)
{
	if ((S) && (S->next))
	{
		int suma = S->data + S->next->data;
		pop();
		pop();
		push(suma);

	}
}

// Program główny
int main()
{
	stos S;
	char znak;
	int liczba = 0;
	bool flaga = true;
	bool czy_liczba = false;

	while (cin.good())/*!feof(stdin)*/
	{
		if (flaga)
		{
			cin.read(&znak, sizeof(znak));
		}
		flaga = true;

			switch (znak)
			{
			case 'p':
				S.wypisz();
				cout << endl;
				break;
			case 's':
				S.zamiana();
				break;
			case 'x':
				S.pop();
				break;
			case '+':
				S.suma();
				break;
			case 'r':
				S.zamiana_r();
				break;
			case 'q':
				exit(0);
				break;
			default:
				while (znak >= '0' && znak <= '9')
				{
					liczba *= 10;
					liczba += (znak - '0');
					cin.read(&znak, sizeof(znak));
					flaga = false;
					czy_liczba = true;
				}
				if (czy_liczba) 
				{
					S.push(liczba);
					liczba = 0;
					czy_liczba = false;
				}
					
				break;
			}	
	}

	return 0;
}