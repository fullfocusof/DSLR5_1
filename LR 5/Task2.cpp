//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//struct TreeNode
//{
//	int data;
//	int count;
//	TreeNode* left;
//	TreeNode* right;
//};
//
//TreeNode* createNode(int value)
//{
//    TreeNode* newNode = new TreeNode;
//    newNode->data = value;
//    newNode->count = 1;
//    newNode->left = nullptr;
//    newNode->right = nullptr;
//    return newNode;
//}
//
//TreeNode* insertValue(TreeNode* root, int value)
//{
//    if (root == nullptr) return createNode(value);
//    
//    if (value == root->data) root->count++;
//    else if (value < root->data) root->left = insertValue(root->left, value);
//    else root->right = insertValue(root->right, value);
//
//    return root;
//}
//
//int searchValue(TreeNode* root, int value)
//{
//    if (root == nullptr) return 0;
//
//    if (value == root->data) return root->count;
//    else if (value < root->data) return searchValue(root->left, value);
//    else return searchValue(root->right, value);
//}
//
//void destroyTree(TreeNode* root)
//{
//    if (root != nullptr) 
//    {
//        destroyTree(root->left);
//        destroyTree(root->right);
//        delete root;
//    }
//}
//
//void countKeysInFile(const string& filename, int key)
//{
//    ifstream ifs(filename);
//
//    if (!ifs.is_open())
//    {
//        cerr << "Ошибка при открытии файла" << endl;
//    }
//
//    int value;
//    TreeNode* root = nullptr;
//
//    while (ifs >> value)
//    {
//        root = insertValue(root, value);
//    }
//    ifs.close();
//
//    int cnt = searchValue(root, key);
//    ofstream ofs(filename, ios::app);
//    ofs << endl << cnt;
//    cout << "Данные записаны: " << cnt << endl;
//
//    destroyTree(root);
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//    int key;
//    cout << "Введите искомое значение" << endl;
//    cin >> key;
//
//    countKeysInFile("data2.txt", key);
//}