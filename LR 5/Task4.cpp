//#include <iostream>
//#include <fstream>
//#include <algorithm>
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
//int findMaxDepth(TreeNode* root) 
//{
//    if (root == nullptr) 
//    {
//        return 0;
//    }
//
//    int leftHeight = findMaxDepth(root->left);
//    int rightHeight = findMaxDepth(root->right);
//
//    return max(leftHeight, rightHeight) + 1;
//}
//
//void printTree(TreeNode* node, int indent) 
//{
//    if (node == nullptr) 
//    {
//        return;
//    }
//
//    printTree(node->left, indent - 5);
//
//    for (int i = 0; i < indent; i++) 
//    {
//        cout << " ";
//    }
//    cout << node->data << endl;
//
//    printTree(node->right, indent - 5);
//}
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//
//    TreeNode* root = createTree("data4.txt");
//    int depth = findMaxDepth(root);
//    printTree(root, depth * 5);
//    cout << endl << "Высота: " << depth << endl;
//}