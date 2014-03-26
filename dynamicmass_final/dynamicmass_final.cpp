//dynamicmass02.cpp
// Раздел 2. Задачи на языке программирования высокого уровня
// 1) Организуйте работу с динамическим массивов (создание, добавление, удаление элементов из произвольной позиции с изменением размера массива), хранящим целочисленные значения.
// динаимческийсписок
#include <iostream>
using namespace std;
/////////////////////////////////////////////
struct elem
{
	int data;
	elem* next;
};

class list
{
private:
	elem* first;
	unsigned int counter;
public:
	list() : first(NULL), counter(0)
	{}
	int additem(int d, unsigned int number);
	int deleteitem(unsigned int number);
	void display()const;
	unsigned int get_counter()const;
};
int list::additem(int d, unsigned int number)
{
	counter++;
	if (number > counter || number == 0) // если место добавления выбрано неверно
	{
		cout << "Выбранный элемент не соответствует размеру массива" << endl;
		return 1;
	}
	elem* newelem = new elem;
	newelem->data = d;
	if (first == NULL)	// если элемент добавляется в начало первый элемент
	{
		newelem->next = NULL;
		first = newelem;
	}
	elem* temp = new elem;
	if (counter == 1)		// если добавляется первый элемент
	{
		temp->next = NULL;
		temp->data = d;
		first = temp;
	}
	//else if ( number == 1)		// если элемент добавляется в начало
	//{
	//	elem* temp2 = first;
	//	temp->data = d;
	//	temp->next = temp2;
	//	first = temp;
	//}
	else					// если элемент добавляется в серидину списка
	{
		temp = first;
		for (int i = 1; i < static_cast<int>(number - 1) && temp->next != NULL; i++)
		{
			temp = temp->next;
		}
		elem* temp3 = new elem;
		temp3 = temp->next;
		temp->next = newelem;
		if (number == counter)	// если добавляетмя последний элемент
		{
			newelem->next = NULL;
		}
		else					// если добавляетмя не последний элемент
		{
			newelem->next = temp3;
		}
	}
	return 0;
}
int list::deleteitem(unsigned int number)
{
	if (number > counter || number == 0)			// если место добавления выбрано неверно
	{
		cout << "Выбранный элемент не соответствует размеру массива" << endl;
		return 1;
	}

	if (number == 1 && counter == 1)		// если удаляется первый элемент из списка с одним элементом
	{
		delete first;
		first = NULL;
	}
	else if (number == 1)					// если удаляется первый элемент списка
	{
		delete first;
		first = first->next;
	}
	else									// если удаляется элемент из серидины списка
	{
		elem* temp = new elem;
		temp = first;
		for (int i = 1; i < static_cast<int>(number - 1) && temp->next != NULL; i++)
		{
			temp = temp->next;
		}
		elem* temp2 = new elem;
		temp2 = temp->next;
		if (number == counter)				// если удаляется последний элемент списка
		{
			temp->next = NULL;
		}
		else								// если удаляется не последний элемент списка
		{
			temp->next = temp2->next;
		}
	}
	counter--;
	return 0;
}
void list::display()const
{
	elem* current = first;
	cout << "Массив:" << endl;
	for (int i = 0; i < static_cast<int>(counter) /*&& current != NULL */; i++)
	{
		cout << "mass[" << i + 1 << "]=" << current->data << endl;
		current = current->next;
	}
}
unsigned int list::get_counter()const
{
	return counter;
}

int main()
{
	system("chcp 1251 > nul");
	char again = 'y';
	char comma_1 = ',', comma_2 = ',';
	char operation = '0';	// 'a', 'd', 'e', 's'
	char show = '0';
	list li;
	int dat = 0;
	int numb = 0;

	cout << "\tДинамический массив: " << endl << endl;
	cout << "Введите команду вида: 'a,124,1' или 'd,1' или 'e' или 's'." << endl << endl;
	cout << "'a' - чтобы добавить элемент," << endl;
	cout << "'d' - чтобы удалить элемент," << endl;
	cout << "'e' - чтобы закончить редактирование массива," << endl;
	cout << "'s' - чтобы отобразить массив," << endl;
	cout << "'124' - значение элемента, '1' - номер элемента в массиве." << endl;
	cout << endl;

	do
	{
		cout << " > ";
		operation = _getwche();

		switch (operation)
		{
		case 'a':
			cin >> comma_1 >> dat >> comma_2 >> numb;
			if (numb <= li.get_counter() + 1)
			{
				li.additem(dat, numb);
			}
			else
			{
				cout << " > " << "Выбранный элемент невозможно изменить" << endl;
			}
			break;
		case 'd':
			cin >> comma_2 >> numb;
			if (numb <= li.get_counter() + 1)
			{
				li.deleteitem(numb);
			}
			else
			{
				cout << " > " << "Выбранный элемент невозможно изменить" << endl;
			}
			break;
		case 's':
			cout << endl;
			if (numb <= li.get_counter() + 1)
			{
				li.display();
			}
			else
			{
				cout << "Невозможно отобразить массив";
			}
			break;
		case 'e':
			cout << endl;
			//system("pause");
			break;
		default:
			cout << " > " << "Можно только добавить или удалить элемент." << endl;
		}
	} while (operation != 'e');

	li.display();
	cout << endl;

	system("pause");
	return 0;
}
