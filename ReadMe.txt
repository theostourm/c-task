1 - Class and functions
2 - Algorithm logic
3 - How to run the code and test different cases
4 - Comments


/////////////////////////////
1 - Class and functions
/////////////////////////////

--------
For this problem I chose to create a "Node" class. Its objects are represented by:
    - their name (m_name)
    - an integer representing its entry buffer (m_buffer_in)
    - an integer representing its exit buffer (m_buffer_out)
    - a list of node pointers, pointing to their children nodes (m_children)

Modeling this way, All the adjacency information is directly stored in the nodes attributes.
The Node class contains constructors, getters and setters.

For simplicity, I chose to set the entry buffer of "In" and the exit buffer of "Out" at -1.

--------
The second class is the "Graph" one. 

A graph is represented by:
    - a list of node pointers (m_nodes)
    - a map of (int, bool) to save the buffers used during the process in the graph (m_buffers)

The list of nodes is not really used, it is useful to display the final buffers for each node at the end of the program.

This class contains usual getters and setter but also the functions we are more interested about:
    - getFirstFreeBuffer() returns the first buffer not used, either already existing and free in the map m_buffers, or creating a new buffer in the map.
    - calculateBuffers(Node* start) : This functions calculates the buffers and the mixing stages for the graph, and displays the steps in the console.


/////////////////////////////
2 - Algorithm logic
/////////////////////////////

The "calculateBuffers" function takes an Node pointer as a start parameter.

Here is the main logic:

( * )- If the start node has a single child (in serie) -> its child gets the same entry and exit buffer, equal to the start exit buffer.
       The program stops when we encounter a child with an exit buffer equals to -1 (meaning the Out node).

     - If the start node has multiple children, the program will loop on the list of children.

         -> if the child is not the last child, it will get as exit buffer the first buffer available.
            if not, it will get the same buffer as entry and exit.

            Then we compute buffers for its children -> back to the ( * ), with the start node the current child.

            Once we did the job for its children, we mix its exit buffer with his older brother mixing result (or older brother's children mixing result).
            We liberate a buffer available for a next brother.



/////////////////////////////
3 - How to run the code and test different cases
/////////////////////////////

The main file contains a lot of code lines to create the objects, with 6 different test cases.

There are 4 ones from the pdf file given by Spitfire Audio and 2 other ones. 
I draw the graph for the new ones in the case description right before the "else if".

To change the test case which will run, change the "test_case" int value at the start of the main function!


/////////////////////////////
4 - Comments
/////////////////////////////

--------
For the test_case 3, the program will display the buffers attribution for the DLY3 node twice.
This is because the algorithm I wrote goes to the bottom of the graph before switching to the next child.
Thus DLY3 buffers values are written twice.
I could maybe have "hidden" it by storing all the strings produced by the algorithm in a sequence, and then keep only the last string where DLY3 appears, and delete all other string describing actions with DLY3.

--------
The algorithm never deletes anything, it might have some memory leak.
I think especially when we get the program goes into a sub "calculateBuffers" function, and then goes out of it. The objects created in the sub function are not manually destroyed by the program.

--------
I did not test more complex graph, I cannot assure that the program works for any of them.
The class I have defined can simulate any of them though.

--------
The algorithm complexity should be O(number of nodes) as we should only go through each node once.
I am not sure of this, because of the stuff happening in test_case 3.