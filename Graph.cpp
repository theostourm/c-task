#include "Graph.hpp"
#include "Node.hpp"
#include <vector>
#include <map>
#include <iostream>

 
using namespace std;


Graph::Graph(std::vector<Node*> nodes) 
{
    m_nodes = nodes;
}

void Graph::displayFinalBuffers()
// Goes through the nodes of the graph and returns their entry and exit buffers.
{
    for (int i = 0; i < m_nodes.size(); i++)
    {
        cout << m_nodes[i]->getName() << "-- Buffer IN: " 
        << m_nodes[i]->getBufferIn() << " // Buffer Out: " << m_nodes[i]->getBufferOut() << endl;
    }
}
 
int Graph::getFirstFreeBuffer()
// Checks if there is already a buffer available in the map, otherwise returns a new one, equals to size of the map.
{
    for (int i = 1; i < m_buffers.size(); i++) 
    {
        if (m_buffers[i] == false)
        {
            return i;
        }
    }
    int i;
    i = m_buffers.size();

    return i;
}

void Graph::setBuffer(int i, bool v) 
{
    m_buffers[i] = v;
}

// Method to calculate the buffers and determine mixing stages.
void Graph::calculate_buffers(Node* start)
{
    Node* current_node(0);
    current_node = start;

    // if there is only one child, give the child the same entry and exit buffer as its parent.
    if (current_node->getChildren().size() == 1 and current_node->getChild()->getBufferOut() != -1)
    {
        if (current_node->getChild()->getBufferOut() != -1)
        {   
            int buffer_res; buffer_res = current_node->getBufferOut();
            current_node->getChild()->setBufferIn(buffer_res);
            current_node->getChild()->setBufferOut(buffer_res);
            cout << "----" << endl;
            cout << current_node->getChild()->getName() << " processes buffer " << buffer_res << " and places the result back in buffer " << buffer_res << endl;
        }
        calculate_buffers(current_node->getChild());
    }

    // if there is more than 1 child
    else if (current_node->getChildren().size() > 1)
    {
        int number_of_children;
        number_of_children = current_node->getChildren().size();

        std::map<int, bool> buffer_used_locally;
        buffer_used_locally[0] = true;

        int result_buffer_mixing;

        // loop through the list of children
        for (int i = 0; i < number_of_children; i++) 
        {   
            current_node->getChildren()[i]->setBufferIn(current_node->getBufferOut());

            // if the child is not the last, its exit buffer gets the first buffer available.
            if (i < number_of_children - 1)
            {
                int ffbuffer;
                ffbuffer = getFirstFreeBuffer();
                m_buffers[ffbuffer] = true;
                buffer_used_locally[ffbuffer] = true;
                current_node->getChildren()[i]->setBufferOut(ffbuffer);
                cout << "----" << endl;
                cout << current_node->getChildren()[i]->getName() << " processes buffer " << current_node->getBufferOut() << " and places the result in buffer " << ffbuffer << endl;
            }
            // if it is the last, its exit buffer is the same as its parents.
            else
            {
                current_node->getChildren()[i]->setBufferOut(current_node->getBufferOut());
                cout << "----" << endl;
                cout << current_node->getChildren()[i]->getName() << " processes buffer " << current_node->getBufferOut() << " and places the result back in buffer " << current_node->getBufferOut() << endl;
            }
            
            // Calculate the buffers for the child's children 
            calculate_buffers(current_node->getChildren()[i]);

            // Depending on the position of the child compared to its brother, determine the mixing stages.
            // If the child is the second and not the last, mix with its older brother and keep the older brother buffer value
            if (i < number_of_children - 1 and i == 1)
            {
                result_buffer_mixing = min(current_node->getChildren()[i]->getBufferOut(), current_node->getChildren()[i-1]->getBufferOut());
                cout << "----" << endl;
                cout << "Buffers " << current_node->getChildren()[i-1]->getBufferOut() << " and " << current_node->getChildren()[i]->getBufferOut() 
                << " are mixed together and placed in buffer " << result_buffer_mixing << endl;

                buffer_used_locally[max(current_node->getChildren()[i]->getBufferOut(), current_node->getChildren()[i-1]->getBufferOut())] = false;
                setBuffer(max(current_node->getChildren()[i]->getBufferOut(), current_node->getChildren()[i-1]->getBufferOut()), false);
            }
            // if the child is more than the third and not the last, the result of the mix is the same as the previous mix from older brothers
            else if (i < number_of_children - 1 and i >= 2) 
            {
                cout << "----" << endl;
                cout << "Buffers " << result_buffer_mixing << " and " << current_node->getChildren()[i]->getBufferOut() << " are mixed together and placed in buffer " << result_buffer_mixing << endl;

                buffer_used_locally[current_node->getChildren()[i]->getBufferOut()] = false;
                setBuffer(current_node->getChildren()[i]->getBufferOut(), false);
            }
            // if the child is the last and the second one, the result of the mix is the exit buffer from this child.
            else if (i == number_of_children - 1 and i == 1) 
            {
                cout << "----" << endl;
                cout << "Buffers " << current_node->getChildren()[i-1]->getBufferOut() << " and " << current_node->getChildren()[i]->getBufferOut() << " are mixed together and placed in buffer " << current_node->getChildren()[i]->getBufferOut() << endl;
                result_buffer_mixing = current_node->getChildren()[i-1]->getBufferOut();

                buffer_used_locally[result_buffer_mixing] = false;
                setBuffer(result_buffer_mixing, false);
            }
            // if the child is the last and not the second one, same result as previously - but we mix with the result of the mix, not the exit buffer from the older brother.
            else if (i == number_of_children - 1 and i >= 2)
            {
                cout << "----" << endl;
                cout << "Buffers " << result_buffer_mixing << " and " << current_node->getChildren()[i]->getBufferOut() << " are mixed together and placed in buffer " << current_node->getChildren()[i]->getBufferOut() << endl;

                buffer_used_locally[result_buffer_mixing] = false;
                setBuffer(result_buffer_mixing, false);
            }
            
        }
    }
}

