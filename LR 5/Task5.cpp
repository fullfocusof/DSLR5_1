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
//    int heightLeftSubTree;
//    int heightRightSubTree;
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
//    newNode->heightLeftSubTree = 0;
//    newNode->heightRightSubTree = 0;
//    return newNode;
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
//TreeNode* insertValue(TreeNode* root, int value)
//{
//    if (root == nullptr) return createNode(value);
//
//    if (value == root->data) root->count++;
//    else if (value < root->data)
//    {
//        root->left = insertValue(root->left, value);
//        root->heightLeftSubTree = findMaxDepth(root->left);
//    }
//    else
//    {
//        root->right = insertValue(root->right, value);
//        root->heightRightSubTree = findMaxDepth(root->right);
//    }
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
//        cerr << "ќшибка при открытии файла" << endl;
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
//void printTree(TreeNode* node, int indent = 0) 
//{
//    if (node == nullptr) 
//    {
//        return;
//    }
//
//    printTree(node->right, indent + 8);
//
//    for (int i = 0; i < indent; i++) 
//    {
//        cout << " ";
//    }
//    cout << node->data << "(" << node->heightLeftSubTree << ", " << node->heightRightSubTree << ")" << endl;
//
//    printTree(node->left, indent + 8);
//}
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//
//    TreeNode* root = createTree("data5.txt");
//    printTree(root);
//    cout << endl;
//    system("pause");
//
//    while (true)
//    {
//        system("cls");
//
//        int key;
//        cout << "¬ведите значение, которое нужно вставить в дерево" << endl;
//        cin >> key;
//
//        insertValue(root, key);
//        printTree(root);
//        cout << endl;
//        system("pause");
//    }
//}