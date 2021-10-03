//
// Created by sajith on 10/2/21.
//


#include <iostream>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
};

template<typename T>
class Generic_Parser
{
public:
    void parse_preorder(TreeNode *node)
    {
        if (node)
        {
            process_node(node);
            parse_preorder(node->left);
            parse_preorder(node->right);
        }
    }

    void process_node(TreeNode *node)
    {
        static_cast<T *>(this)->process_node(node);
    }
};

class EmployeeChart_Parser : public Generic_Parser<EmployeeChart_Parser>
{
public:
    void process_node(TreeNode *node)
    {
        cout << "Customized process_node() fro EmployeeChart\n";
    }
};

int main()
{

    return 0;
}
