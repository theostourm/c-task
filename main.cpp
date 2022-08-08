#include <iostream>
#include <string>
#include <vector>

#include "Node.hpp"
#include "Graph.hpp"

using namespace std;


int main()
{
    /* The main program contains 5 test cases.
    Running the code will display results in the console for the selected test case.
    Feel free to change the test_case value below!
    */
    int test_case = 5;


    // first test case on the pdf document (in series)
    if (test_case == 0) 
    {
        // Create the nodes
        Node In("In", -1, 0); 
        Node LP0("LP0"); 
        Node EQ1("EQ1"); 
        Node EQ2("EQ2"); 
        Node HP3("HP3"); 
        Node Out("Out", 0, -1);

        // Create their pointers
        Node* ptrIn(0);
        Node* ptrLP0(0);
        Node* ptrEQ1(0);
        Node* ptrEQ2(0);
        Node* ptrHP3(0);
        Node* ptrOut(0);

        // Point the pointer to their respective node
        ptrIn = &In;
        ptrLP0 = &LP0;
        ptrEQ1 = &EQ1;
        ptrEQ2 = &EQ2;
        ptrHP3 = &HP3;
        ptrOut = &Out;

        // Create a vector of the nodes pointers for the graph object. Used later to get buffer results.
        vector<Node*> nodes;
        nodes.push_back(ptrIn); nodes.push_back(ptrLP0); nodes.push_back(ptrEQ1); nodes.push_back(ptrEQ2); nodes.push_back(ptrHP3); nodes.push_back(ptrOut);
        Graph graph(nodes);

        // Create a list of pointers for each node pointer to represent their children
        vector<Node*> childrenIn;
        childrenIn.push_back(ptrLP0);   
        vector<Node*> childrenLP0;
        childrenLP0.push_back(ptrEQ1);
        vector<Node*> childrenEQ1;
        childrenEQ1.push_back(ptrEQ2);
        vector<Node*> childrenEQ2;
        childrenEQ2.push_back(ptrHP3);
        vector<Node*> childrenHP3;
        childrenHP3.push_back(ptrOut);

        // Set the children list to the node object attribute "children"
        In.setChildren(childrenIn);
        LP0.setChildren(childrenLP0); 
        EQ1.setChildren(childrenEQ1);
        EQ2.setChildren(childrenEQ2);
        HP3.setChildren(childrenHP3);

                
        // Calculate the buffer, display the text in the console and display the final buffer results.
        graph.setBuffer(0, true);
        cout << "----" << endl;
        cout << "The input starts in buffer 0" << endl;
        graph.calculate_buffers(ptrIn);
        cout << "----" << endl;
        cout << "The final result is then available in buffer 0" << endl;
        cout << "----" << endl;
        cout << "----" << endl;
        graph.displayFinalBuffers();
        cout << "----" << endl;

    }

    // Second test case (4 effects in parallel)
    else if (test_case == 1)
    {
        // Create the nodes
        Node In("In", -1, 0); 
        Node BP0("BP0"); 
        Node BP1("BP1"); 
        Node BP2("BP2");
        Node BP3("BP3");
        Node Out("Out", 0, -1);

        // Create their pointers
        Node* ptrIn(0);
        Node* ptrBP0(0);
        Node* ptrBP1(0);
        Node* ptrBP2(0);
        Node* ptrBP3(0);
        Node* ptrOut(0);

        // Point the pointer to their respective node
        ptrIn = &In;
        ptrBP0 = &BP0;
        ptrBP1 = &BP1;
        ptrBP2 = &BP2;
        ptrBP3 = &BP3;
        ptrOut = &Out;

        // Create a vector of the nodes pointers for the graph object. Used later to get buffer results.
        vector<Node*> nodes;
        nodes.push_back(ptrIn); nodes.push_back(ptrBP0); nodes.push_back(ptrBP1); 
        nodes.push_back(ptrBP2); nodes.push_back(ptrBP3); nodes.push_back(ptrOut);
        Graph graph(nodes);

        // Create a list of pointers for each node pointer to represent their children
        vector<Node*> childrenIn;
        childrenIn.push_back(ptrBP0); childrenIn.push_back(ptrBP1); childrenIn.push_back(ptrBP2); childrenIn.push_back(ptrBP3);  
        vector<Node*> childrenBP0;
        childrenBP0.push_back(ptrOut);
        vector<Node*> childrenBP1;
        childrenBP1.push_back(ptrOut);
        vector<Node*> childrenBP2;
        childrenBP2.push_back(ptrOut);
        vector<Node*> childrenBP3;
        childrenBP3.push_back(ptrOut);
        vector<Node*> childrenOut(0);

        // Set the children list to the node object attribute "children"
        In.setChildren(childrenIn);
        BP0.setChildren(childrenBP0);
        BP1.setChildren(childrenBP1);
        BP2.setChildren(childrenBP2);
        BP3.setChildren(childrenBP3);
        Out.setChildren(childrenOut);

        // Calculate the buffer, display the text in the console and display the final buffer results.
        graph.setBuffer(0, true);
        cout << "----" << endl;
        cout << "The input starts in buffer 0" << endl;
        graph.calculate_buffers(ptrIn);
        cout << "----" << endl;
        cout << "The final result is then available in buffer 0" << endl;
        cout << "----" << endl;
        cout << "----" << endl;
        graph.displayFinalBuffers();
        cout << "----" << endl;
    } 

    // Third test case
    else if (test_case == 2)
    {
        // Create the nodes
        Node In("In", -1, 0); 
        Node BP0("BP0"); 
        Node BP1("BP1"); 
        Node BP2("BP2");
        Node Out("Out", 0, -1);

        // Create their pointers
        Node* ptrIn(0);
        Node* ptrBP0(0);
        Node* ptrBP1(0);
        Node* ptrBP2(0);
        Node* ptrOut(0);

        // Point the pointer to their respective node
        ptrIn = &In;
        ptrBP0 = &BP0;
        ptrBP1 = &BP1;
        ptrBP2 = &BP2;
        ptrOut = &Out;

        // Create a vector of the nodes pointers for the graph object. Used later to get buffer results.
        vector<Node*> nodes;
        nodes.push_back(ptrIn); nodes.push_back(ptrBP0); nodes.push_back(ptrBP1); 
        nodes.push_back(ptrBP2); nodes.push_back(ptrOut);
        Graph graph(nodes);

        // Create a list of pointers for each node pointer to represent their children
        vector<Node*> childrenIn;
        childrenIn.push_back(ptrBP0); childrenIn.push_back(ptrBP2);
        vector<Node*> childrenBP0;
        childrenBP0.push_back(ptrBP1);
        vector<Node*> childrenBP1;
        childrenBP1.push_back(ptrOut);
        vector<Node*> childrenBP2;
        childrenBP2.push_back(ptrOut);
        vector<Node*> childrenOut(0);

        // Set the children list to the node object attribute "children"
        In.setChildren(childrenIn);
        BP0.setChildren(childrenBP0);
        BP1.setChildren(childrenBP1);
        BP2.setChildren(childrenBP2);
        Out.setChildren(childrenOut);

        // Calculate the buffer, display the text in the console and display the final buffer results.
        graph.setBuffer(0, true);
        cout << "----" << endl;
        cout << "The input starts in buffer 0" << endl;
        graph.calculate_buffers(ptrIn);
        cout << "----" << endl;
        cout << "The final result is then available in buffer 0" << endl;
        cout << "----" << endl;
        cout << "----" << endl;
        graph.displayFinalBuffers();
        cout << "----" << endl;
    } 

    // Fourth test case
    else if (test_case == 3)
    {
        // Create the nodes
        Node In("In", -1, 0); 
        Node GATE0("GATE0"); 
        Node BP1("BP1"); 
        Node BP2("BP2");
        Node DLY3("DLY3");
        Node Out("Out", 0, -1);

        // Create their pointers
        Node* ptrIn(0);
        Node* ptrGATE0(0);
        Node* ptrBP1(0);
        Node* ptrBP2(0);
        Node* ptrDLY3(0);
        Node* ptrOut(0);

        ptrIn = &In;
        ptrGATE0 = &GATE0;
        ptrBP1 = &BP1;
        ptrBP2 = &BP2;
        ptrDLY3 = &DLY3;
        ptrOut = &Out;

        // Create a vector of the nodes pointers for the graph object. Used later to get buffer results.
        vector<Node*> nodes;
        nodes.push_back(ptrIn); nodes.push_back(ptrGATE0); nodes.push_back(ptrBP1); 
        nodes.push_back(ptrBP2); nodes.push_back(ptrDLY3); nodes.push_back(ptrOut);
        Graph graph(nodes);

        // Create a list of pointers for each node pointer to represent their children
        vector<Node*> childrenIn;
        childrenIn.push_back(ptrGATE0);
        vector<Node*> childrenGATE0;
        childrenGATE0.push_back(ptrBP1); childrenGATE0.push_back(ptrBP2);
        vector<Node*> childrenBP1;
        childrenBP1.push_back(ptrDLY3);
        vector<Node*> childrenBP2;
        childrenBP2.push_back(ptrDLY3);
        vector<Node*> childrenDLY3;
        childrenDLY3.push_back(ptrOut);
        vector<Node*> childrenOut(0);

        // Set the children list to the node object attribute "children"
        In.setChildren(childrenIn);
        GATE0.setChildren(childrenGATE0);
        BP1.setChildren(childrenBP1);
        BP2.setChildren(childrenBP2);
        DLY3.setChildren(childrenDLY3);
        Out.setChildren(childrenOut);

        // Calculate the buffer, display the text in the console and display the final buffer results.
        graph.setBuffer(0, true);
        cout << "----" << endl;
        cout << "The input starts in buffer 0" << endl;
        graph.calculate_buffers(ptrIn);
        cout << "----" << endl;
        cout << "The final result is then available in buffer 0" << endl;
        cout << "----" << endl;
        cout << "----" << endl;
        graph.displayFinalBuffers();
        cout << "----" << endl;
    } 

    /* Simple test case with 2 effects in parallel 

               IN 
               |  
          ----------
          |        |
         EQ1      EQ2
          |        |
          ----------
               |
              OUT

    */
    else if (test_case == 4) 
    {
        // Create the nodes.
        Node In("In", -1, 0); 
        Node EQ1("EQ1"); 
        Node EQ2("EQ2"); 
        Node Out("Out", 0, -1);

        // Create their pointers.
        Node* ptrIn(0);
        Node* ptrEQ1(0);
        Node* ptrEQ2(0);
        Node* ptrOut(0);

        // Point the pointer to their respective node.
        ptrIn = &In;
        ptrEQ1 = &EQ1;
        ptrEQ2 = &EQ2;
        ptrOut = &Out;

        // Create a vector of the nodes pointers for the graph object. Used later to get buffer results.
        vector<Node*> nodes;
        nodes.push_back(ptrIn); nodes.push_back(ptrEQ1); nodes.push_back(ptrEQ2); nodes.push_back(ptrOut);
        Graph graph(nodes);

        // Create a list of pointers for each node to represent their children, add their children in their list.
        vector<Node*> childrenIn;
        childrenIn.push_back(ptrEQ1); childrenIn.push_back(ptrEQ2);  
        vector<Node*> childrenEQ1;
        childrenEQ1.push_back(ptrOut);
        vector<Node*> childrenEQ2;
        childrenEQ2.push_back(ptrOut);
        vector<Node*> childrenOut(0);

        // Set the children lists to the Node objects attribute "children".
        In.setChildren(childrenIn);
        EQ1.setChildren(childrenEQ1);
        EQ2.setChildren(childrenEQ2);
        Out.setChildren(childrenOut);

        // Calculate the buffer, display the text in the console and display the final buffer results.
        graph.setBuffer(0, true);
        cout << "----" << endl;
        cout << "The input starts in buffer 0" << endl;
        graph.calculate_buffers(ptrIn);
        cout << "----" << endl;
        cout << "The final result is then available in buffer 0" << endl;
        cout << "----" << endl;
        cout << "----" << endl;
        graph.displayFinalBuffers();
        cout << "----" << endl;
    }
    
    /* Test case with effects in parallel twice.

                        IN 
                        |  
            ----------------------------
            |                          |
           EQ0                        EQ1
            |                          |
            |                          |
        ----------             ------------------
        |        |             |       |        |
       BP2      BP3           HP4     HP5      HP6
        |        |             |       |        |
        ----------             ------------------
            |                          |
            ----------------------------
                        |
                       OUT

    */
    else if (test_case == 5) 
    {
        // Create the nodes.
        Node In("In", -1, 0); 
        Node EQ0("EQ0"); 
        Node EQ1("EQ1"); 
        Node BP2("BP2");
        Node BP3("BP3");
        Node HP4("HP4");
        Node HP5("HP5");
        Node HP6("HP6");
        Node Out("Out", 0, -1);

        // Create their pointers.
        Node* ptrIn(0);
        Node* ptrEQ0(0);
        Node* ptrEQ1(0);
        Node* ptrBP2(0);
        Node* ptrBP3(0);
        Node* ptrHP4(0);
        Node* ptrHP5(0);
        Node* ptrHP6(0);
        Node* ptrOut(0);

        // Point the pointer to their respective node.
        ptrIn = &In;
        ptrEQ0 = &EQ0;
        ptrEQ1 = &EQ1;
        ptrBP2 = &BP2;
        ptrBP3 = &BP3;
        ptrHP4 = &HP4;
        ptrHP5 = &HP5;
        ptrHP6 = &HP6;
        ptrOut = &Out;

        // Create a vector of the nodes pointers for the graph object. Used later to get buffer results.
        vector<Node*> nodes;
        nodes.push_back(ptrIn); nodes.push_back(ptrEQ0); nodes.push_back(ptrEQ1); nodes.push_back(ptrBP2);
        nodes.push_back(ptrBP3); nodes.push_back(ptrHP4); nodes.push_back(ptrHP5); nodes.push_back(ptrHP6);
        nodes.push_back(ptrOut);
        Graph graph(nodes);

        // Create a list of pointers for each node to represent their children, add their children in their list.
        vector<Node*> childrenIn;
        childrenIn.push_back(ptrEQ0); childrenIn.push_back(ptrEQ1);  
        vector<Node*> childrenEQ0;
        childrenEQ0.push_back(ptrBP2); childrenEQ0.push_back(ptrBP3);
        vector<Node*> childrenEQ1;
        childrenEQ1.push_back(ptrHP4); childrenEQ1.push_back(ptrHP5); childrenEQ1.push_back(ptrHP6);
        vector<Node*> childrenBP2;
        childrenBP2.push_back(ptrOut);
        vector<Node*> childrenBP3;
        childrenBP3.push_back(ptrOut);
        vector<Node*> childrenHP4;
        childrenHP4.push_back(ptrOut);
        vector<Node*> childrenHP5;
        childrenHP5.push_back(ptrOut);
        vector<Node*> childrenHP6;
        childrenHP6.push_back(ptrOut);
        vector<Node*> childrenOut(0);

        // Set the children lists to the Node objects attribute "children".
        In.setChildren(childrenIn);
        EQ0.setChildren(childrenEQ0);
        EQ1.setChildren(childrenEQ1);
        BP2.setChildren(childrenBP2);
        BP3.setChildren(childrenBP3);
        HP4.setChildren(childrenHP4);
        HP5.setChildren(childrenHP5);
        HP6.setChildren(childrenHP6);
        Out.setChildren(childrenOut);

        // Calculate the buffers, display the text in the console and display the final buffer results.
        graph.setBuffer(0, true);
        cout << "----" << endl;
        cout << "The input starts in buffer 0" << endl;
        graph.calculate_buffers(ptrIn);
        cout << "----" << endl;
        cout << "The final result is then available in buffer 0" << endl;
        cout << "----" << endl;
        cout << "----" << endl;
        graph.displayFinalBuffers();
        cout << "----" << endl;
    }
    

    return 0;

}