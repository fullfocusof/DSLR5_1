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
//void deleteNode(TreeNode*& t1, TreeNode* t, TreeNode*& temp)
//{
//    if (t1->right != NULL) 
//        deleteNode(t1->right, t, temp);
//    else 
//    {
//        temp = t1;
//        t->data = t1->data;
//        t1 = t1->left;
//    }
//}
//
//void deleteTree(TreeNode*& t, int a)
//{
//    TreeNode* temp = NULL;
//    if (t != NULL)
//    {
//        if (a > t->data) deleteTree(t->right, a);
//        else if (a < t->data) deleteTree(t->left, a);
//        else 
//        {
//            temp = t;
//            if (t->right == NULL) t = t->left;
//            else if (t->left == NULL)  t = t->right;
//            else deleteNode(t->left, t, temp);
//            delete temp;
//        }
//    }
//}
//
//void deleteNodesOnLevel(TreeNode*& root, int level)
//{
//    if (root == nullptr)
//        return;
//
//    if (level == 1)
//    {
//        deleteTree(root, root->data);
//        return;
//    }
//
//    deleteNodesOnLevel(root->left, level - 1);
//    deleteNodesOnLevel(root->right, level - 1);
//}
//
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//
//    TreeNode* root = createTree("data6.txt");
//    int depth = findMaxDepth(root);
//    printTree(root, depth * 5);
//    cout << endl << "Высота: " << depth << endl;
//
//    int depthToDel;
//    cout << endl << "Введите уровень дерева" << endl;
//    cin >> depthToDel;
//
//    while (depthToDel > depth || depthToDel < 1)
//    {
//        cerr << "Невозможно удалить несуществующие вершины" << endl;
//        cin >> depthToDel;
//    }
//
//    deleteNodesOnLevel(root, depthToDel);
//    cout << endl << endl;
//    printTree(root, depth * 5);
//
//
//    destroyTree(root);
//}