#include <iostream>
#include <string>

class TreeNode {
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(const std::string &sv = std::string()):
        value(sv), count(0), left(NULL), right(NULL){}

    TreeNode(const TreeNode &orig)
    {
        value = orig.value;
        count = orig.count;
        if(orig.left == NULL)
        {
            left = NULL;
        }
        else
        {
            left = new TreeNode(*orig.left);
        }
        if(orig.right == NULL)
        {
            right = NULL;
        }
        else
        {
            right = new TreeNode(*orig.right);
        }
    }

    TreeNode & operator=(const TreeNode &orig)
    {
        value = orig.value;
        count = orig.count;
        TreeNode *templ = new TreeNode(*orig.left);
        delete left;
        left = templ;
        TreeNode *tempr = new TreeNode(*orig.right);
        delete right;
        right = tempr;
    }

    ~TreeNode()
    {
        if(left != NULL)
            delete left;
        if(right != NULL)
            delete right;
    }
};

class BinStrTree{
private:
    TreeNode *root;

public:
    BinStrTree() = delete;

    BinStrTree(const TreeNode &tn): root(new TreeNode(tn)){}

    BinStrTree(const BinStrTree & bt)
    {
        root = new TreeNode(*bt.root);
    }

    BinStrTree & operator=(const BinStrTree & bt)
    {
        TreeNode *tn = new TreeNode(*bt.root);
        delete root;
        root = tn;
    }

    ~BinStrTree()
    {
        delete root;
    }
};