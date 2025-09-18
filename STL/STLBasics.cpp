#include <vector>
#include <iostream>
#include <list>
#include <stack>

using namespace std;

void explainVector()
{
    // It's size can be dynamically increased

    vector<int> marks; // empty container

    vector<int> v3(5, 100); // Size 5, all values initialized to 100
    vector<string> v4 = {"a", "b", "c"};

    marks.push_back(1);    // puts 1 in vector marks || moves the copy of the value passed
    marks.emplace_back(2); // dynamically increases the size and puts 2 at the end

    // Similar to push_back(), but constructs the element in-place (no copy).
    // Faster for complex objects (like classes, pairs, structs).

    // emplace back is faster than push back (why???)

    // 🧠 Why emplace_back is Faster
    // push_back({1,2}) first creates a temporary pair<int,int> {1,2} and then copies/moves it into the vector.
    // emplace_back(1,2) directly constructs the pair<int,int> inside the vector memory — no temporary object, no copy.
    // For simple types like int, this difference is negligible.
    // But for heavy objects (like string, class, struct), emplace_back avoids a costly copy/move.

    // cout << v[0];      // Access element at index 0 (no bounds check)
    // cout << v.at(0);   // Access with bounds check (throws error if invalid)

    // cout << v.front(); // First element
    // cout << v.back();  // Last element

    // v.pop_back();           // Removes last element
    // v.erase(v.begin() + 1); // Removes element at index 1 [Big O(n)]
    // v.erase(v.begin()+1, v.begin()+3); //Deletes from index 1 till 2
    // v.clear();              // Removes all elements

    // cout << v.size();  // Number of elements
    // cout << v.empty(); // 1 if vector is empty
    // v.resize(10);      // Resizes vector to size 10 (new elements = 0)
    // v.reserve(100);    // Reserve capacity for 100 elements (optimizes performance)

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    for (int i = 0; i < marks.size(); i++)
        cout << marks[i] << " ";

    for (vector<int>::iterator hv = marks.begin(); hv != marks.end(); hv++) // clever desgin choice
    {
        cout << *(hv) << " ";
    }

    for (auto it = marks.begin(); it != marks.end(); it++)
        cout << *it << " ";

    for (auto x : marks) // for each loop (modified for loop)
        cout << x << " ";

    vector<int> mark = {10, 20, 30, 40};

    // 1️⃣ insert(position, value)
    // Inserts a single element at 'position'
    mark.insert(mark.begin() + 2, 25); // Insert 25 at index 2
    // Result: {10, 20, 25, 30, 40}

    // 2️⃣ insert(position, count, value)
    // Inserts 'count' copies of value before 'position'
    mark.insert(mark.begin() + 3, 2, 99); // Insert two 99s before index 3
    // Result: {10, 20, 25, 99, 99, 30, 40}

    // 3️⃣ insert(position, first, last)
    // Inserts elements from another range [first, last) before 'position'
    vector<int> extra = {111, 222};
    mark.insert(mark.begin() + 1, extra.begin(), extra.end());
    // Result: {10, 111, 222, 20, 25, 99, 99, 30, 40}

    // 4️⃣ insert(position, initializer_list)
    // Inserts elements from an initializer list before 'position'
    mark.insert(mark.end(), {500, 600, 700});
    // Result: {10, 111, 222, 20, 25, 99, 99, 30, 40, 500, 600, 700}   
}

/*
===============================
        VECTOR vs LIST
===============================

🔹 std::list → Doubly Linked List
🔹 std::vector → Dynamic Array

------------------------------------------------
| Feature              | vector       | list     |
------------------------------------------------
| Memory Layout        | Contiguous   | Nodes w/ next & prev pointers  |
| Random Access        | ✅ O(1)      | ❌ Not supported              |
| Insertion @ End      | ✅ O(1)*     | ✅ O(1)                       |
| Insertion @ Middle   | ❌ O(n)      | ✅ O(1) (if iterator given)   |
| Deletion @ Middle    | ❌ O(n)      | ✅ O(1) (if iterator given)   |
| Cache Friendliness   | ✅ High      | ❌ Poor                       |
| Memory Overhead      | Low          | High (extra pointers)          |
------------------------------------------------
*vector push_back() is amortized O(1)

------------------------------------------------
Syntax Quick Reference (list):
------------------------------------------------
#include <list>
using namespace std;

list<int> l = {10, 20, 30};

l.push_back(40);    // Add at end
l.push_front(5);    // Add at front
l.pop_back();       // Remove last
l.pop_front();      // Remove first

auto it = l.begin();
++it;               // Move iterator to 2nd element
l.insert(it, 15);   // Insert before 2nd element
l.erase(it);        // Remove 2nd element

for (int x : l) cout << x << " "; // Range-based for loop

------------------------------------------------
When to Use:
------------------------------------------------
✅ Use vector:
    - Need random access (v[i])
    - Mostly insert/remove at end
    - Need compact memory and cache efficiency

✅ Use list:
    - Frequent insertions/deletions in middle
    - Random access NOT needed
    - O(1) insertion/deletion is priority

RULE OF THUMB:
"If you often insert/erase in middle → list.
If you just push/pop at end or need fast indexing → vector."

=========================================
        VECTOR vs LIST (Quick Guide)
=========================================

std::vector:
------------
- Dynamic array, contiguous memory.
- ✅ Random access allowed (O(1)): v[i] works.
- ✅ Cache friendly (fast).
- ❌ Inserting/removing in middle = O(n) (shifts elements).
- Best when you:
    - Need fast access by index.
    - Mostly push/pop at end.

std::list:
----------
- Doubly Linked List (nodes with prev & next pointers).
- ❌ Random access NOT allowed (O(n) traversal).
- ✅ Insertion/removal at known position = O(1).
- Best when you:
    - Frequently insert/erase in middle.
    - Do not need indexing.

=========================================
      WHY LIST DOES NOT SUPPORT RANDOM ACCESS
=========================================

Vector:
-------
- Contiguous memory, so address of v[i] is:
  
    base_address + i * sizeof(element)
  
- ✅ O(1) direct access.

List:
-----
- Elements scattered in memory.
- Each node = [prev pointer] [data] [next pointer].
- To reach 5th node, must traverse next → next → next.
- ❌ No formula to "jump" to i-th element.
- Access time = O(n).

ASCII Visualization:
--------------------

Vector (Contiguous):
[ 10 ][ 20 ][ 30 ][ 40 ][ 50 ]
 ^base ----------------> direct jump possible

List (Doubly Linked):
HEAD -> [10|next] <-> [20|next] <-> [30|next] <-> [40|next] -> NULL
 ^must walk step by step

=========================================
     SINGLY vs DOUBLY LINKED LIST
=========================================

Singly Linked List:
-------------------
[Data | Next] -> [Data | Next] -> [Data | Next] -> NULL
- Each node points only to next node.
- Can only traverse FORWARD.
- Less memory overhead (1 pointer per node).

Doubly Linked List:
-------------------
NULL <- [Prev | Data | Next] <-> [Prev | Data | Next] -> NULL
- Each node points to BOTH next & previous nodes.
- Can traverse FORWARD and BACKWARD.
- More memory overhead (2 pointers per node).
- Faster insertions/deletions in middle (no need to search for previous node).

=========================================
RULE OF THUMB:
--------------
- "If you need fast indexing → use vector.
- If you need frequent insert/erase in middle → use list."
*/

void explainList(){
    //easier to insert elements at front than vector, other than that, its similar to vector
    list<int> ls; 

    ls.push_back(2); 
    ls.emplace_back(4); 

    ls.push_front(5); 
    ls.emplace_front(); 
}

/*
=========================================
                STACK (Quick Guide)
=========================================

Definition:
-----------
- Stack = Container with LIFO (Last-In-First-Out) order.
- Think of a stack of plates:
    Last plate placed = first plate removed.

Key Operations (All O(1)):
-------------------------
- push(x):    Add element on top.
- pop():      Remove top element.
- top():      Get the top element (does NOT remove).
- empty():    Returns true if stack is empty.
- size():     Returns number of elements.

int main() {
    stack<int> st;

    st.push(10);  // stack: 10
    st.push(20);  // stack: 10, 20
    st.push(30);  // stack: 10, 20, 30

    cout << "Top element: " << st.top() << endl; // 30

    st.pop();     // removes 30
    cout << "New top: " << st.top() << endl; // 20

    cout << "Size: " << st.size() << endl;  // 2
    cout << "Empty? " << (st.empty() ? "Yes" : "No") << endl; // No
}

Properties:
-----------
- No random access (can't get st[i]).
- Only access top element.
- Internally uses deque by default (but can use vector/list).

Use Cases:
----------
✅ Undo/Redo functionality (text editors)
✅ Function call stack (recursion)
✅ Balancing parentheses, syntax parsing
✅ Backtracking algorithms (DFS, maze solving)
✅ Evaluating postfix/prefix expressions

ASCII Visualization:
--------------------
Push 10 → Push 20 → Push 30
       [30] <- TOP
       [20]
       [10]

Pop() removes 30, now 20 is top.

RULE OF THUMB:
--------------
"Use stack when you need to remember things in reverse order of arrival."
*/



/*
=========================================
                QUEUE (Quick Guide)
=========================================

Definition:
-----------
- Queue = Container with FIFO (First-In-First-Out) order.
- Think of people standing in a line:
    First person to enter = first person to leave.

Key Operations (All O(1)):
-------------------------
- push(x):    Add element at back.
- pop():      Remove element from front.
- front():    Get the front element (does NOT remove).
- back():     Get the last element.
- empty():    Returns true if queue is empty.
- size():     Returns number of elements.

int main() {
    queue<int> q;

    q.push(10);  // queue: 10
    q.push(20);  // queue: 10, 20
    q.push(30);  // queue: 10, 20, 30

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Back element: " << q.back() << endl;   // 30

    q.pop();     // removes 10
    cout << "New front: " << q.front() << endl; // 20

    cout << "Size: " << q.size() << endl;  // 2
    cout << "Empty? " << (q.empty() ? "Yes" : "No") << endl; // No
}

Properties:
-----------
- No random access (can't do q[i]).
- Access only from FRONT (read/remove) and BACK (insert).
- Internally uses deque by default.

Use Cases:
----------
✅ Task scheduling (CPU job queue)
✅ Breadth-First Search (BFS) in graphs
✅ Printer queue
✅ Message passing between threads
✅ Handling real-life waiting lines

ASCII Visualization:
--------------------
Push 10 → Push 20 → Push 30
Front -> [10] [20] [30] <- Back

Pop() removes 10, now 20 is front.

RULE OF THUMB:
--------------
"Use queue when you need to process elements in the order they arrived."
*/
