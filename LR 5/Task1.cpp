//#include "GraphInteraction.h"
//
//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_ENTER 13
//#define KEY_ESC 27
//#define KEY_BACKSPACE 8
//
//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//void GoToXY(short x, short y)
//{
//	SetConsoleCursorPosition(hStdOut, { x, y });
//}
//
//void ConsoleCursorVisible(bool show, short size)
//{
//	CONSOLE_CURSOR_INFO structCursorInfo;
//	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
//	structCursorInfo.bVisible = show;
//	structCursorInfo.dwSize = size;
//	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	SetConsoleTitle(L"Графы");
//	ConsoleCursorVisible(false, 100);
//	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
//
//	GraphInteraction test;
//
//	int active_menu = 0;
//	int keyInput;
//	bool exitProg = false;
//
//	system("cls");
//
//	while (!exitProg)
//	{
//		int x = 40, y = 12;
//		GoToXY(x, y);
//
//		vector<string> menu =
//		{
//			"Считать граф из файла",
//			"Вывести граф на экран",
//			"Преобразовать матрицу смежности в список связей",
//			"Преобразовать список связей в матрицу смежности",
//			"Построить каркас графа поиском в ширину",
//			"Построить каркас графа поиском в глубину",
//			"Выход"
//		};
//
//		for (int i = 0; i < menu.size(); i++)
//		{
//			if (i == active_menu)
//			{
//				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
//			}
//			else
//			{
//				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
//			}
//
//			GoToXY(x, y++);
//			cout << menu[i] << endl;
//		}
//
//		keyInput = _getch();
//		switch (keyInput)
//		{
//			case KEY_ESC:
//				exit(0);
//
//			case KEY_UP:
//			{
//				if (active_menu > 0)
//				{
//					active_menu--;
//				}
//			}
//			break;
//
//			case KEY_DOWN:
//			{
//				if (active_menu < menu.size() - 1)
//				{
//					active_menu++;
//				}
//			}
//			break;
//
//			case KEY_ENTER:
//			{
//				switch (active_menu)
//				{
//					case 0:
//					{
//						system("cls");
//						
//						if (!test.getAdjM().empty() || !test.getAdjL().empty())
//						{
//							cout << "Данные уже считаны" << endl;
//						}
//						else
//						{
//							test.Read_g();
//						}
//
//						test.printQuit();
//					}
//					break;
//
//					case 1:
//					{
//						system("cls");
//
//						if (!test.getAdjM().empty())
//						{
//							cout << "Данные хранятся в виде матрице смежности" << endl;
//							test.Print_gAdjM();
//						}
//						else if (!test.getAdjL().empty())
//						{
//							cout << "Данные хранятся в виде списка связей" << endl;
//							test.Print_gAdjL();
//						}
//						else
//						{
//							cout << "Данные отсутствуют";
//						}
//
//						test.printQuit();
//					}
//					break;
//
//					case 2:
//					{
//						system("cls");
//
//						if (test.getAdjL().empty())
//						{
//							test.fromMatrixToList();
//
//							if (test.isConversionValid())
//							{
//								cout << "Преобразование успешно";
//								test.clearMatrix();
//							}
//							else
//							{
//								cout << "Ошибка преобразования";
//							}
//						}
//						else
//						{
//							cout << "В списке связей присутствуют данные";
//						}
//
//						test.printQuit();
//					}
//					break;
//
//					case 3:
//					{
//						system("cls");
//
//						if (test.getAdjM().empty())
//						{
//							test.fromListToMatrix();
//
//							if (test.isConversionValid())
//							{
//								cout << "Преобразование успешно";
//								test.clearList();
//							}
//							else
//							{
//								cout << "Ошибка преобразования";
//							}
//						}
//						else
//						{
//							cout << "В матрице смежности присутствуют данные";
//						}			
//
//						test.printQuit();
//					}
//					break;
//
//					case 4:
//					{
//						system("cls");
//
//						if (!test.getAdjM().empty())
//						{
//							vector<vector<int>> frame = test.getFrameBFSAdjM();
//							cout << "Каркас(ы) графа: " << endl;
//							for (int i = 0; i < frame.size(); i++)
//							{
//								cout << i + 1 << " каркас: ";
//								for (auto& el : frame[i])
//								{
//									cout << el << " ";
//								}
//								cout << endl;
//							}
//						}
//						else if (!test.getAdjL().empty())
//						{
//							vector<vector<int>> frame = test.getFrameBFSAdjL();
//							cout << "Каркас(ы) графа: " << endl;
//							for (int i = 0; i < frame.size(); i++)
//							{
//								cout << i + 1 << " каркас: ";
//								for (auto& el : frame[i])
//								{
//									cout << el << " ";
//								}
//								cout << endl;
//							}
//						}
//						else
//						{
//							cout << "Данные отсутствуют";
//						}
//				
//						test.printQuit();
//					}
//					break;
//
//					case 5:
//					{
//						system("cls");
//
//						if (!test.getAdjM().empty())
//						{
//							vector<vector<int>> frame = test.getFrameDFSAdjM();
//							cout << "Каркас(ы) графа: " << endl;
//							for (int i = 0; i < frame.size(); i++)
//							{
//								cout << i + 1 << " каркас: ";
//								for (auto& el : frame[i])
//								{
//									cout << el << " ";
//								}
//								cout << endl;
//							}
//						}
//						else if (!test.getAdjL().empty())
//						{
//							vector<vector<int>> frame = test.getFrameDFSAdjL();
//							cout << "Каркас(ы) графа: " << endl;
//							for (int i = 0; i < frame.size(); i++)
//							{
//								cout << i + 1 << " каркас: ";
//								for (auto& el : frame[i])
//								{
//									cout << el << " ";
//								}
//								cout << endl;
//							}
//						}
//						else
//						{
//							cout << "Данные отсутствуют";
//						}
//
//						test.printQuit();
//					}
//					break;
//
//					case 6:
//					{
//						system("cls");
//						exitProg = true;
//					}
//					break;
//				}
//			}
//			break;
//
//		}
//	}
//
//	/*Read_g();
//	if (adjacencyM.empty())
//	{
//		cout << "Данные отсутствуют";
//	}
//	else
//	{
//		Print_g();
//	}
//	cout << endl;
//	system("pause");
//
//	system("cls");
//	vector<forward_list<int>> adjL = fromMatrixToList();
//	cout << "Статус преобразования - " << (isConversionValid(adjacencyM, adjL) ? "успешно" : "безуспешно") << endl << endl;
//	cout << "Списки связности:" << endl;
//	for (int i = 1; i <= verts; i++)
//	{
//		cout << i << " вершина: ";
//		vector<int> temp;
//		for (auto& el : adjL[i])
//		{
//			cout << el << " ";
//			temp.push_back(el);
//		}
//		if (temp.empty())
//		{
//			cout << "<нет смежных вершин>";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	system("pause");
//
//	system("cls");
//	vector<vector<int>> adjM = fromListToMatrix(adjL);
//	cout << "Статус преобразования - " << (isConversionValid(adjM, adjL) ? "успешно" : "безуспешно") << endl << endl;
//	cout << "Матрица смежности:" << endl;
//	for (int i = 1; i <= verts; i++)
//	{
//		cout << i << " вершина: ";
//		vector<int> temp;
//		for (int j = 1; j <= verts; j++)
//		{
//			if (adjacencyM[i][j] == 1)
//			{
//				temp.push_back(j);
//				cout << j << " ";
//			}
//		}
//		if (temp.empty())
//		{
//			cout << "<нет смежных вершин>";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	system("pause");*/
//}