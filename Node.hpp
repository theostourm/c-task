#ifndef DEF_NODE
#define DEF_NODE

#include <string>
#include <vector>

class Node
{
    public:

    Node(std::string name);
    Node(std::string name, int buffer_in, int buffer_out);

    std::string getName();

    int getBufferIn();
    int getBufferOut();
    void setBufferIn(int i);
    void setBufferOut(int j);

    void setChildren(std::vector<Node*> children);
    std::vector<Node*> getChildren();
    Node* getChild();
    
    private:

    std::string m_name;
    int m_buffer_in;
    int m_buffer_out;
    std::vector<Node*> m_children;
};

#endif