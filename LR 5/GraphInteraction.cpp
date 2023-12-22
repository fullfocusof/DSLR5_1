//#include "GraphInteraction.h"
//
//GraphInteraction::GraphInteraction()
//{
//
//}
//
//vector<vector<int>> GraphInteraction::getAdjM()
//{
//	return adjacencyM;
//}
//
//vector<forward_list<int>> GraphInteraction::getAdjL()
//{
//	return adjacencyL;
//}
//
//void GraphInteraction::printQuit()
//{
//	cout << endl << endl << "Backspace - возврат в меню";
//
//	int answ = _getch();
//	bool press = false;
//
//	while (!press)
//	{
//		if (answ == 8)
//		{
//			press = true;
//			break;
//		}
//		else
//		{
//			answ = _getch();
//		}
//	}
//
//	system("cls");
//}
//
//void GraphInteraction::Read_g()
//{
//	ifstream ifs("data1.txt");
//	if (ifs.is_open())
//	{
//		ifs >> verts;
//		ifs >> edges;
//		adjacencyM.resize(verts + 1, vector<int>(verts + 1));
//		for (int i = 1; i < adjacencyM.size(); i++)
//		{
//			for (int j = 1; j < adjacencyM[i].size(); j++)
//			{
//				ifs >> adjacencyM[i][j];
//			}
//		}
//		cout << "Данные успешно считаны" << endl;
//	}
//	else
//	{
//		cerr << "Ошибка открытия файла" << endl;
//	}
//	ifs.close();
//}
//
//void GraphInteraction::Print_gAdjM()
//{
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
//}
//
//void GraphInteraction::Print_gAdjL()
//{
//	for (int i = 1; i <= verts; i++)
//	{
//		cout << i << " вершина: ";
//		vector<int> temp;
//		for (auto el : adjacencyL[i])
//		{
//			temp.push_back(el);
//			cout << el << " ";
//		}
//		if (temp.empty())
//		{
//			cout << "<нет смежных вершин>";
//		}
//		cout << endl;
//	}
//}
//
//bool GraphInteraction::isConversionValid()
//{
//	int n = adjacencyM.size();
//
//	if (adjacencyL.size() != n)
//	{
//		return false;
//	}
//
//	for (int i = 1; i <= verts; i++)
//	{
//		int cnt = 0;
//		for (auto el : adjacencyM[i])
//		{
//			if (el == 1)
//			{
//				cnt++;
//			}
//		}
//
//		int cntList = 0;
//		for (auto el : adjacencyL[i])
//		{
//			cntList++;
//		}
//
//		if (cnt != cntList)
//		{
//			return false;
//		}
//	}
//
//	for (int i = 1; i <= verts; ++i)
//	{
//		forward_list<int> temp = adjacencyL[i];
//		for (auto& el : temp)
//		{
//			if (el > verts || el < 0)
//			{
//				return false;
//			}
//
//			if (adjacencyM[i][el] != 1)
//			{
//				return false;
//			}
//		}
//	}
//
//	return true;
//}
//
//void GraphInteraction::fromMatrixToList()
//{
//	int n = adjacencyM.size();
//	adjacencyL.push_back(forward_list<int>());
//
//	for (int i = 1; i < n; ++i)
//	{
//		forward_list<int> v;
//		for (int j = 1; j < n; ++j)
//		{
//			if (adjacencyM[i][j] == 1)
//			{
//				v.push_front(j);
//			}
//		}
//		v.reverse();
//		adjacencyL.push_back(v);
//	}
//}
//
//void GraphInteraction::clearMatrix()
//{
//	for (auto row : adjacencyM)
//	{
//		row.clear();
//	}
//	adjacencyM.clear();
//}
//
//void GraphInteraction::fromListToMatrix()
//{
//	int n = adjacencyL.size();
//
//	adjacencyM.resize(n, vector<int>(n));
//
//	for (int i = 1; i < n; ++i)
//	{
//		for (auto& el : adjacencyL[i])
//		{
//			adjacencyM[i][el] = 1;
//		}
//	}
//}
//
//void GraphInteraction::clearList()
//{
//	for (auto row : adjacencyL)
//	{
//		row.clear();
//	}
//	adjacencyL.clear();
//}
//
//vector<vector<int>> GraphInteraction::getFrameBFSAdjM()
//{
//	queue<int> qTemp;
//	vector<bool> status(verts + 1);
//	vector<vector<int>> result;
//
//	int curNum = 1;
//	while (curNum <= verts)
//	{
//		if (!status[curNum])
//		{
//			status[curNum] = true;
//			qTemp.push(curNum);
//			vector<int> temp;
//			while (!qTemp.empty())
//			{
//				int curVert = qTemp.front();
//				qTemp.pop();
//
//				for (int j = 1; j <= verts; j++)
//				{
//					if (adjacencyM[curVert][j] && !status[j])
//					{
//						status[j] = true;
//						qTemp.push(j);
//						temp.push_back(curVert);
//						temp.push_back(j);
//					}
//				}
//
//				if (temp.empty())
//				{
//					temp.push_back(curVert);
//				}
//			}
//			result.push_back(temp);
//		}
//		curNum++;
//	}
//
//	return result;
//}
//
//void GraphInteraction::DFSCompsAdjM(vector<int>& comp, vector<bool>& status, int curVert)
//{
//	status[curVert] = true;
//
//	for (int i = 1; i <= verts; i++)
//	{
//		if (adjacencyM[curVert][i] && !status[i])
//		{		
//			comp.push_back(curVert);
//			comp.push_back(i);
//			DFSCompsAdjM(comp, status, i);
//		}
//	}
//}
//
//vector<vector<int>> GraphInteraction::getFrameDFSAdjM()
//{
//	vector<vector<int>> result;
//	vector<bool> visited(verts + 1);
//
//	for (int i = 1; i <= verts; i++)
//	{
//		if (!visited[i])
//		{
//			vector<int> component;
//			DFSCompsAdjM(component, visited, i);
//
//			if (component.empty())
//			{
//				component.push_back(i);
//			}
//
//			result.push_back(component);
//		}
//	}
//
//	return result;
//}
//
//vector<vector<int>> GraphInteraction::getFrameBFSAdjL()
//{
//	queue<int> qTemp;
//	vector<bool> status(verts + 1);
//	vector<vector<int>> result;
//
//	int curNum = 1;
//	while (curNum <= verts)
//	{
//		if (!status[curNum])
//		{
//			status[curNum] = true;
//			qTemp.push(curNum);
//			vector<int> temp;
//			while (!qTemp.empty())
//			{
//				int curVert = qTemp.front();
//				qTemp.pop();
//
//				for (auto el : adjacencyL[curVert])
//				{
//					if (!status[el])
//					{
//						status[el] = true;
//						qTemp.push(el);
//						temp.push_back(curVert);
//						temp.push_back(el);
//					}
//				}
//
//				if (temp.empty())
//				{
//					temp.push_back(curVert);
//				}
//			}
//			result.push_back(temp);
//		}
//		curNum++;
//	}
//
//	return result;
//}
//
//vector<vector<int>> GraphInteraction::getFrameDFSAdjL()
//{
//	vector<vector<int>> result;
//	vector<bool> visited(verts + 1);
//
//	for (int i = 1; i <= verts; i++)
//	{
//		if (!visited[i])
//		{
//			vector<int> component;
//			DFSCompsAdjL(component, visited, i);
//
//			if (component.empty())
//			{
//				component.push_back(i);
//			}
//
//			result.push_back(component);
//		}
//	}
//
//	return result;
//}
//
//void GraphInteraction::DFSCompsAdjL(vector<int>& comp, vector<bool>& status, int curVert)
//{
//	status[curVert] = true;
//
//	for (auto el : adjacencyL[curVert])
//	{
//		if (!status[el])
//		{
//			comp.push_back(curVert);
//			comp.push_back(el);
//			DFSCompsAdjL(comp, status, el);
//		}
//	}
//}