//dynamicmass02.cpp
// ������ 2. ������ �� ����� ���������������� �������� ������
// 1) ����������� ������ � ������������ �������� (��������, ����������, �������� ��������� �� ������������ ������� � ���������� ������� �������), �������� ������������� ��������.
// ������������������
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
	if (number > counter || number == 0) // ���� ����� ���������� ������� �������
	{
		cout << "��������� ������� �� ������������� ������� �������" << endl;
		return 1;
	}
	elem* newelem = new elem;
	newelem->data = d;
	if (first == NULL)	// ���� ������� ����������� � ������ ������ �������
	{
		newelem->next = NULL;
		first = newelem;
	}
	elem* temp = new elem;
	if (counter == 1)		// ���� ����������� ������ �������
	{
		temp->next = NULL;
		temp->data = d;
		first = temp;
	}
	//else if ( number == 1)		// ���� ������� ����������� � ������
	//{
	//	elem* temp2 = first;
	//	temp->data = d;
	//	temp->next = temp2;
	//	first = temp;
	//}
	else					// ���� ������� ����������� � �������� ������
	{
		temp = first;
		for (int i = 1; i < static_cast<int>(number - 1) && temp->next != NULL; i++)
		{
			temp = temp->next;
		}
		elem* temp3 = new elem;
		temp3 = temp->next;
		temp->next = newelem;
		if (number == counter)	// ���� ����������� ��������� �������
		{
			newelem->next = NULL;
		}
		else					// ���� ����������� �� ��������� �������
		{
			newelem->next = temp3;
		}
	}
	return 0;
}
int list::deleteitem(unsigned int number)
{
	if (number > counter || number == 0)			// ���� ����� ���������� ������� �������
	{
		cout << "��������� ������� �� ������������� ������� �������" << endl;
		return 1;
	}

	if (number == 1 && counter == 1)		// ���� ��������� ������ ������� �� ������ � ����� ���������
	{
		delete first;
		first = NULL;
	}
	else if (number == 1)					// ���� ��������� ������ ������� ������
	{
		delete first;
		first = first->next;
	}
	else									// ���� ��������� ������� �� �������� ������
	{
		elem* temp = new elem;
		temp = first;
		for (int i = 1; i < static_cast<int>(number - 1) && temp->next != NULL; i++)
		{
			temp = temp->next;
		}
		elem* temp2 = new elem;
		temp2 = temp->next;
		if (number == counter)				// ���� ��������� ��������� ������� ������
		{
			temp->next = NULL;
		}
		else								// ���� ��������� �� ��������� ������� ������
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
	cout << "������:" << endl;
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

	cout << "\t������������ ������: " << endl << endl;
	cout << "������� ������� ����: 'a,124,1' ��� 'd,1' ��� 'e' ��� 's'." << endl << endl;
	cout << "'a' - ����� �������� �������," << endl;
	cout << "'d' - ����� ������� �������," << endl;
	cout << "'e' - ����� ��������� �������������� �������," << endl;
	cout << "'s' - ����� ���������� ������," << endl;
	cout << "'124' - �������� ��������, '1' - ����� �������� � �������." << endl;
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
				cout << " > " << "��������� ������� ���������� ��������" << endl;
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
				cout << " > " << "��������� ������� ���������� ��������" << endl;
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
				cout << "���������� ���������� ������";
			}
			break;
		case 'e':
			cout << endl;
			//system("pause");
			break;
		default:
			cout << " > " << "����� ������ �������� ��� ������� �������." << endl;
		}
	} while (operation != 'e');

	li.display();
	cout << endl;

	system("pause");
	return 0;
}
