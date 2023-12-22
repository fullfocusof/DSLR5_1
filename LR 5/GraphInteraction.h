//#pragma once
//#include <iostream>
//#include <fstream>
//
//#include <forward_list>
//#include <queue>
//#include <vector>
//#include <stack>
//
//#include <Windows.h>
//#include <conio.h>
//
//using namespace std;
//
//class GraphInteraction
//{
//	int verts, edges;
//	vector<vector<int>> adjacencyM;
//	vector<forward_list<int>> adjacencyL;
//
//public:
//
//	GraphInteraction();
//
//	vector<vector<int>> getAdjM();
//	vector<forward_list<int>> getAdjL();
//
//	void printQuit();
//
//	void Read_g();
//	void Print_gAdjM();
//	void Print_gAdjL();
//
//	bool isConversionValid();
//	void fromMatrixToList();
//	void clearMatrix();
//	void fromListToMatrix();
//	void clearList();
//
//	vector<vector<int>> getFrameBFSAdjM();
//	vector<vector<int>> getFrameDFSAdjM();
//	void DFSCompsAdjM(vector<int>& comp, vector<bool>& status, int curVert);
//
//	vector<vector<int>> getFrameBFSAdjL();
//	vector<vector<int>> getFrameDFSAdjL();
//	void DFSCompsAdjL(vector<int>& comp, vector<bool>& status, int curVert);
//};