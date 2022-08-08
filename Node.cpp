#include "Node.hpp"
#include <vector>
#include <iostream>

using namespace std;

Node::Node(string name): m_name(name) {}

Node::Node(string name, int buffer_in, int buffer_out): m_name(name), m_buffer_in(buffer_in), m_buffer_out(buffer_out)
{

}

string Node::getName()
{
    return m_name;
}

int Node::getBufferIn()
{
    return m_buffer_in;
}

int Node::getBufferOut()
{
    return m_buffer_out;
}

void Node::setBufferIn(int i)
{
    m_buffer_in = i;
}

void Node::setBufferOut(int j)
{
    m_buffer_out = j;
}

void Node::setChildren(std::vector<Node*> children)
{
    m_children = children; 
}

std::vector<Node*> Node::getChildren() 
{
    return m_children;
}

Node* Node::getChild() 
{
    return m_children[0];
}

