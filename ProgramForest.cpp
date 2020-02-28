#include <iostream>
#include <map>
#include <string>
#include <ostream>
#include <fstream>

using namespace std;


string NewNameAnimal()
{

	string Name;
	cout << "������� ���" << endl;
	cin >> Name;
	cout << "��������� ���- ���������." << endl;
	return Name;
}

class Animal
{
	public:

	string TypeAnimal;
	string Name;
	int warehouse = 0;
	string food;

	Animal()
	{
		
	}
	
	virtual void eat()
	{
		cout << "���� �������� ";
	}
	
	virtual ~Animal()
	{
		
	}
};
//**************************** ������� ������ ��� ���� ����� ��������	*****************
class Wolf :public Animal
{
	public:

	Wolf()
	{
		cout << "� ����� ���� ��������� ����."<<endl;
	}
	
	string TypeAnimal = "����";
	
	void eat() override
	{
		cout << "���� ���� ������� " << endl;
	}

	~Wolf() override
	{
		cout << "����" << "\t" << Name << "\t" << "����� ������- " << warehouse<< " (��)" << endl;
	}
};

class Bear :public Animal
{
	public:
	Bear()
	{
		cout << "� ����� ���� ��������� �������."<<endl;
	}
	
	string TypeAnimal = "�������";
	
	void eat() override
	{
		cout << "������� �������� ��� " << endl;
	}
	
	~Bear() override
	{
		cout << "�������" << "\t" << Name << "\t" << "����� ����- " << warehouse<< " (���.)" << endl;
	}
};

class Squirrel :public Animal
{
	public:
	Squirrel()
	{
		cout << "� ����� ���� ���������� �����." << endl;
	}
	
	string TypeAnimal = "�����";
	
	void eat() override
	{
		cout << "����� �������� �� ���� ���� " << endl;	
	}
	
	~Squirrel() override
	{
		cout << "�����" << "\t" << Name << "\t" << "����� �������- " << warehouse<<" (��.)" << endl;
	}
};

Animal* AddNewAnimal()
{
	int TypeAnimal;
	do
	{
		cout << "�������� ��������:\n1 - ����\n2 - �������\n3 - �����\n0 - ����� � �������� ����" << endl;
		(cin >> TypeAnimal).get();
		system("cls");
		
		switch (TypeAnimal)
		{
			case(1):
				return (new Wolf);
				break;

			case(2):
				return (new Bear);
				break;

			case(3):
				return (new Squirrel);
				break;

			case(0):
				
				return 0;
				break;

			default:
				cout << "������ �����. ��������, ����������, ���������� �����."<<endl;
				return 0;
				break;
		}
	} while (TypeAnimal < 0 || TypeAnimal>3);
}

void FeedAnimal()
{
	cout << "�������� ��� ���� ���. ������ ��������� ��� ��� ����� � �������� ����." << endl;
}

void SelectAnimal()
{
	cout << "������� ��� ���������, ������� �� ������ ������� ��� ������� 0 ��� ������ � ������� ����." << endl;
}

//*****************************************������� ������ ����**********************************
void MainMenu()
{
	cout << "1 - add new animal\n" << "2 - select animal\n" << "0 - close\n";
}

void SecondMenu()
{
	cout << "1 - ������� ����� ���\n" << "0 - ����� � �������� ����\n";
}
//*****************************************���������� ���������*********************************

int main()
{
		setlocale(LC_ALL, "rus");

		int start;
		int ChoiceAnimal;
		Animal* arrAnimal[5];
		int i = 0;
		int j = 0;
		bool UniqueName;
		string NewName;
		string name;
		bool FindName;
		int SecondMenuItem;

		do
		{
			MainMenu();

			(cin >> start).get();
			system("cls");
			switch (start)
			{
				case(1):
				{
					arrAnimal[i] = AddNewAnimal();

					if (arrAnimal[i]!=0)
					{
						do
						{
							cout << "������� ��� ���������" << endl;
							cin >> NewName;
							UniqueName = true;

							for (int j = 0; j < (i+1); j++)
							{
								if (arrAnimal[j]->Name==NewName)
								{
									cout << "����� ��� ��� ����. ���������� ������ ���. ��� ������� 0, ����� ����� � ������� ����" << endl;
									UniqueName = false;
									break;
								}

							}
							if (UniqueName)
							{
								arrAnimal[i]->Name = NewName;
								cout << "�� �������� " << NewName << " ���������" << endl << endl << endl;
								i++;
							}
						
						} while (!UniqueName);

						break;
					}
					else
					{
						break;
					}
				}

				case(2):
				{
					SelectAnimal();

					do
					{
						cin >> name;
						system("cls");
						if (name == "0")
						{
							break;
						}

						FindName = false;
						for (int j = 0; j<i ; j++)
						{
							if (name==arrAnimal[j]->Name)
							{
								cout << "��������"<<arrAnimal[j]->TypeAnimal<< arrAnimal[j]->Name << " ����� ������" << endl;
								system("cls");
								FindName = true;
								break;
							}
						}
						if (!FindName)
						{
						 cout <<"� ���� ��� ��������� � ����� ������!\n ���������� ������ ��� ��� ��� ������� 0 ��� ������ � ������� ����" << endl;
						}
					} while (!FindName);

					do
					{
						if (name == "0")
						{
							break;
						}
					 SecondMenu();
						cin >> SecondMenuItem;
						system("cls");
						switch (SecondMenuItem)
						{
							case(1):
								(arrAnimal[j]->warehouse)++;
								arrAnimal[j]->eat();
								break;

							case(0):
								break;

							default:
								cout << "��������� ����. ��������, ����������, ���������� �����" << endl;
								break;
						}
					} while (SecondMenuItem != 0);

					break;
				}

				case(0):
				{
					break;
				}

				default:
					cout << "��������� ����. ��������, ����������, ���������� �����" << endl;
					break;
			}

		} while (start != 0);

		string NameFile;
		NameFile = "ListAnimal.txt";
		ofstream SaveList;
		SaveList.open(NameFile, ofstream::app);
		if (!SaveList.is_open())
		{
			cout << "������ �������� �����";
		}
		
		else
		{
			for (int i = 0; i < 5; i++)
			{ 
				SaveList << arrAnimal[i];
			}
			SaveList.close();
		}
		for (int i = 0; i < 5; i++)
		{
			if (arrAnimal[i] != 0)
			{
				delete arrAnimal[i];
			}
		}

	}
/*setlocale(LC_ALL, "rus");
ofstream fout;
string path= "FileForest.txt";
fout.open(path);
if (!fout.is_open())
{
	cout << "������"<<endl;
}
else
{
	fout << "�������� ����";
}

fout.close();*/

				


