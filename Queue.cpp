// Author: Aslam Khan
// Email : aslamkhanofficial@yahoo.com
// Institute : Air University Islamabad

#include<iostream>
#include<conio.h>
using namespace std;

class Queue
{
public:

	int data;
	Queue* next;

	Queue()
	{
		data = 0;
		
	}


};

class Linked_list
{
public:
	Queue* Front;
	Queue* Rear;

	Linked_list();
	void Enqueue(Queue*);
	void Dequeue();
	int peek();
	void Display();
	bool IsEmpty();
	int counter();
	

};

Linked_list::Linked_list()
{
	Front = NULL;
	Rear = NULL;

}

int Linked_list::counter()
{
	int count = 0;
	Queue* ptr = Front;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return count;
}

bool Linked_list::IsEmpty()
{
	if (Front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Linked_list::Display()
{
	int i = 1;
	Queue* ptr = Front;
	if (Front == NULL)
	{
		cout << "List is Empty..." << endl;
	}
	else
	{
		while (ptr != NULL)
		{
			cout << "Node " << i << " = " << ptr->data << endl;
			ptr = ptr->next;
			i++;
		}
	}
	_getch();
}
void Linked_list::Enqueue(Queue* n)
{
	
	if(IsEmpty())
		{
		Front = n;
		Rear = n;
		
	}
	else
	{
		Queue* ptr = Front;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		
		ptr->next = n;
		Rear = n;
		
		
	}
	cout << "Node is Sucessfully Enqueued..." << endl;
	_getch();
}

void Linked_list::Dequeue()
{
	if (IsEmpty())
	{
		cout << "Queue Is Empty..." << endl;
	}
	else
	{
		Front = Front->next;
		cout << "Element is Sucessfully Dequeue..." << endl;
	}
	_getch();
}

int Linked_list::peek()
{
	return Front->data;

}



int main()
{
	int data;
	int p;
	Linked_list L;
	int ch;
	while (true)
	{
		system("cls");
		cout << "1 = Enqueue" << endl;
		cout << "2 = Dequeue" << endl;
		cout << "3 = Peek" << endl;
		cout << "4 = Display" << endl;
		cout << "Total Elements = " << L.counter() << endl;
		Queue* Q = new Queue();
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Data = ";
			cin >> data;
			Q->data = data;
			L.Enqueue(Q);
			break;

		case 2:
			L.Dequeue();
			break;
		case 3:
			cout << "Peek Value = " << L.peek() << endl;
			_getch();
			break;

		case 4:
			L.Display();
			break;

		default:
			cout << "Invalid Option Selected.." << endl;
			
		}


	}



	system("pause");
}
