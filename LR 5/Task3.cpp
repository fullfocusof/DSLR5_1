//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//struct TreeNode
//{
//    int data;
//    int count;
//    TreeNode* left;
//    TreeNode* right;
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
//bool compareTrees(TreeNode* tree1, TreeNode* tree2) 
//{
//    if (tree1 == nullptr && tree2 == nullptr) return true;
//    else if (tree1 == nullptr || tree2 == nullptr) return false;
//    else if (tree1->data != tree2->data) return false;
//    else if (tree1->count != tree2->count) return false;
//    else return compareTrees(tree1->left, tree2->left) && compareTrees(tree1->right, tree2->right);
//}
//
//TreeNode* createTree(const string& filename)
//{
//    ifstream ifs(filename);
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
//    return root;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//
//    TreeNode* firstTree = createTree("data3.txt");
//    TreeNode* secondTree = createTree("data3_2.txt");
//
//    if (compareTrees(firstTree, secondTree))
//    {
//        cout << "Деревья равны" << endl;
//    }
//    else
//    {
//        cout << "Деревья не равны" << endl;
//    }
//
//    destroyTree(firstTree);
//    destroyTree(secondTree);
//}