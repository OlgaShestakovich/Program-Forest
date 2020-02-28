#include <iostream>
#include <map>
#include <string>
#include <ostream>
#include <fstream>

using namespace std;


string NewNameAnimal()
{

	string Name;
	cout << "Введите имя" << endl;
	cin >> Name;
	cout << "Выбранное имя- уникально." << endl;
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
		cout << "жует животное ";
	}
	
	virtual ~Animal()
	{
		
	}
};
//**************************** СОЗДАЛА КЛАССЫ ДЛЯ ВСЕХ ТИПОВ ЖИВОТНЫХ	*****************
class Wolf :public Animal
{
	public:

	Wolf()
	{
		cout << "В вашем лесу поселился волк."<<endl;
	}
	
	string TypeAnimal = "Волк";
	
	void eat() override
	{
		cout << "Волк жует колбасу " << endl;
	}

	~Wolf() override
	{
		cout << "Волк" << "\t" << Name << "\t" << "запас кобасы- " << warehouse<< " (шт)" << endl;
	}
};

class Bear :public Animal
{
	public:
	Bear()
	{
		cout << "В вашем лесу поселился медведь."<<endl;
	}
	
	string TypeAnimal = "Медведь";
	
	void eat() override
	{
		cout << "Медведь уплетает мед " << endl;
	}
	
	~Bear() override
	{
		cout << "Медведь" << "\t" << Name << "\t" << "запас меда- " << warehouse<< " (бан.)" << endl;
	}
};

class Squirrel :public Animal
{
	public:
	Squirrel()
	{
		cout << "В вашем лесу поселилась белка." << endl;
	}
	
	string TypeAnimal = "Белка";
	
	void eat() override
	{
		cout << "Белка засунула за щеку орех " << endl;	
	}
	
	~Squirrel() override
	{
		cout << "Белка" << "\t" << Name << "\t" << "запас орешков- " << warehouse<<" (шт.)" << endl;
	}
};

Animal* AddNewAnimal()
{
	int TypeAnimal;
	do
	{
		cout << "Выберите животное:\n1 - волк\n2 - медведь\n3 - белка\n0 - выход в основное меню" << endl;
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
				cout << "Ошибка ввода. Сделайте, пожалуйста, правильный выбор."<<endl;
				return 0;
				break;
		}
	} while (TypeAnimal < 0 || TypeAnimal>3);
}

void FeedAnimal()
{
	cout << "Животное ест вашу еду. Можете покормить еще или выйти в основное меню." << endl;
}

void SelectAnimal()
{
	cout << "Введите имя животного, которое вы хотите выбрать или нажмите 0 для выхода в Главное меню." << endl;
}

//*****************************************ФУНКЦИЯ ПЕРВОЕ МЕНЮ**********************************
void MainMenu()
{
	cout << "1 - add new animal\n" << "2 - select animal\n" << "0 - close\n";
}

void SecondMenu()
{
	cout << "1 - сделать запас еды\n" << "0 - выйти в основное меню\n";
}
//*****************************************РЕАЛИЗАЦИЯ ПРОГРАММЫ*********************************

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
							cout << "Укажите имя животного" << endl;
							cin >> NewName;
							UniqueName = true;

							for (int j = 0; j < (i+1); j++)
							{
								if (arrAnimal[j]->Name==NewName)
								{
									cout << "Такое имя уже есть. Придумайте другое имя. Или нажмите 0, чтобы выйти в главное меню" << endl;
									UniqueName = false;
									break;
								}

							}
							if (UniqueName)
							{
								arrAnimal[i]->Name = NewName;
								cout << "Не забудьте " << NewName << " покормить" << endl << endl << endl;
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
								cout << "Возможно"<<arrAnimal[j]->TypeAnimal<< arrAnimal[j]->Name << " хочет кушать" << endl;
								system("cls");
								FindName = true;
								break;
							}
						}
						if (!FindName)
						{
						 cout <<"В лесу нет животного с таким именем!\n Попробуйте ввести еще раз или нажмите 0 для выхода в Главное меню" << endl;
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
								cout << "Ошибочный ввод. Сделайте, пожалуйста, правильный выбор" << endl;
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
					cout << "Ошибочный ввод. Сделайте, пожалуйста, правильный выбор" << endl;
					break;
			}

		} while (start != 0);

		string NameFile;
		NameFile = "ListAnimal.txt";
		ofstream SaveList;
		SaveList.open(NameFile, ofstream::app);
		if (!SaveList.is_open())
		{
			cout << "Ошибка открытия файла";
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
	cout << "Ошибка"<<endl;
}
else
{
	fout << "Описание леса";
}

fout.close();*/

				


