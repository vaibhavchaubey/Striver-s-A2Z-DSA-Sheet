/* Leetcode Submission          (1472. Design Browser History)    */

/* Problem Statement: You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

    BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
    void visit(string url) Visits url from the current page. It clears up all the forward history.
    string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
    string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps. */



/* Solution: (Using Doubly LinkedList)
// Time Complexity: BrowserHistory => O(1), visit => O(1), back => O(N), forward => O(N)
// Space Complexity: O(1)


// class DLLNode {
// public:
//     string data;
//     DLLNode *prev, *next;

//     DLLNode(string url) {
//         data = url;
//         prev = NULL;
//         next = NULL;
//     }
// };

// class BrowserHistory {
// public:
//     DLLNode* linkedListHead;
//     DLLNode* current;

//     BrowserHistory(string homepage) {                   // O(1)
//         // 'homepage' is the first visited URL.
//         linkedListHead = new DLLNode(homepage);
//         current = linkedListHead;
//     }
    
//     void visit(string url) {                            // O(1)
//         // Insert new node 'url' in the right of current node.
//         DLLNode* newNode = new DLLNode(url);
//         current->next = newNode;
//         newNode->prev = current;
//         // Make this new node as current node now.
//         current = newNode;
//     }
    
//     string back(int steps) {                            // O(steps)
//         // Move 'current' pointer in left direction.
//         while (steps > 0 && current->prev != NULL) {
//             current = current->prev;
//             steps--;
//         }
//         return current->data;
//     }
    
//     string forward(int steps) {                         // O(steps)
//         // Move 'current' pointer in right direction.
//         while (steps > 0 && current->next != NULL) {
//             current = current->next;
//             steps--;
//         }
//         return current->data;
//     }
// };

/* Solution: (Using Doubly LinkedList)
// Time Complexity: BrowserHistory => O(1), visit => O(1), back => O(N), forward => O(N)
// Space Complexity: O(1)

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */