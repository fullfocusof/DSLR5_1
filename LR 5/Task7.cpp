//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <vector>
//
//using namespace std;
//
//struct TreeNode
//{
//    string data;
//    int count;
//    TreeNode* left;
//    TreeNode* right;
//};
//
//TreeNode* createNode(string value)
//{
//    TreeNode* newNode = new TreeNode;
//    newNode->data = value;
//    newNode->count = 1;
//    newNode->left = nullptr;
//    newNode->right = nullptr;
//    return newNode;
//}
//
//TreeNode* insertValue(TreeNode* root, string value)
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
//vector<string> splitIntoWords(const string& text)
//{
//    vector<string> words;
//    stringstream ss(text);
//    string word;
//    while (ss >> word)
//    {
//        words.push_back(word);
//    }
//    return words;
//}
//
//string sanitizeWord(const string& word)
//{
//    string sanitized;
//    for (char c : word)
//    {
//        if (std::isalpha(c))
//        {
//            sanitized += c;
//        }
//    }
//    return sanitized;
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
//    string text;
//    string line;
//    
//
//    while (getline(ifs, line))
//    {
//        stringstream lineStream(line);
//        string word;
//        while (lineStream >> word)
//        {
//            string sanitizedWord = sanitizeWord(word);
//            if (!sanitizedWord.empty())
//            {
//                text += sanitizedWord + " ";
//            }
//        }
//    }
//    ifs.close();
//
//    vector<string> words = splitIntoWords(text);
//
//    TreeNode* root = nullptr;
//    for (auto& el : words)
//    {
//        root = insertValue(root, el);
//    }
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
//void printTree(TreeNode* node, int indent = 0)
//{
//    if (node == nullptr)
//    {
//        return;
//    }
//
//    printTree(node->right, indent + 12);
//
//    for (int i = 0; i < indent; i++)
//    {
//        cout << " ";
//    }
//    cout << node->data << endl;
//
//    printTree(node->left, indent + 12);
//}
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//
//    TreeNode* rootFirst = createTree("data7_1.txt");
//    TreeNode* rootSecond = createTree("data7_2.txt");
//
//    printTree(rootFirst);
//    cout << endl << endl << endl;
//}