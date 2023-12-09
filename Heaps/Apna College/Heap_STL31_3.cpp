/* Heap in C++ STL | make_heap(), push_heap(), pop_heap(), sort_heap(), is_heap, is_heap_until() */

/* 
1. make_heap() :- This function is used to convert a range in a container to a heap.
2. front() :- This function displays the first element of heap which is the maximum number 
3. push_heap() :- This function is used to insert elements into heap. 
The size of the heap is increased by 1. New element is placed appropriately in the heap.
4. pop_heap() :- This function is used to delete the maximum element of the heap. 
The size of heap is decreased by 1. The heap elements are reorganised accordingly after this operation.
5. sort_heap() :- This function is used to sort the heap. After this operation, the container is no longer a heap.
*/


// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int> v = {20, 30, 40, 25, 15};

//     make_heap(v.begin(),v.end());
//     for(auto i : v){
//         cout<<i<<" ";       //40 30 20 25 15 
//     }cout<<endl;

//     cout<<"The maximum element of heap is: ";
//     cout<<v.front()<<endl;             //40

//     v.push_back(50);
//     push_heap(v.begin(),v.end());

//     cout <<"The maximum element of heap after push is: ";
//     cout <<v.front()<<endl;      //50


//     pop_heap(v.begin(),v.end());
//     v.pop_back();

//     cout <<"The maximum element of heap after pop is: ";
//     cout <<v.front()<<endl;     //40


//     sort_heap(v.begin(),v.end());
//     cout <<"The heap elements after sorting are: ";
//     for(auto i : v){
//         cout<<i<<" ";       //15 20 25 30 40
//     }cout<<endl;


//     return 0;
// }



/* 
6. is_heap() :- This function is used to check whether the container is heap or not. 
Generally, in most implementations, the reverse sorted container is considered as heap. 
Returns true if container is heap else returns false.
7. is_heap_until() :- This function returns the iterator to the position till the container is the heap. 
Generally, in most implementations, the reverse sorted container is considered as heap.
*/


// is_heap() and is_heap_until()

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main()
// {

// 	vector<int> v = {40, 30, 25, 35, 15};
	
// 	// Declaring heap iterator
// 	vector<int>::iterator it1;
	
// 	// Checking if container is heap
// 	// using is_heap()
// 	is_heap(v.begin(),v.end())?
// 	cout << "The container is heap ":
// 	cout << "The container is not heap";
// 	cout << endl;
	
// 	// using is_heap_until() to check position
// 	// till which container is heap
// 	auto it = is_heap_until(v.begin(),v.end());
	
// 	// Displaying heap range elements
// 	cout << "The heap elements in container are : ";
// 	for (it1 = v.begin(); it1!=it; it1++)
// 	cout << *it1 << " ";
	
// 	return 0;
// }





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Priority Queue in C++ Standard Template Library (STL)

/* Priority Queue
Priority queues are a type of container adapters, specifically designed such that the first element 
of the queue is the greatest of all elements in the queue and elements are in non increasing order 
(hence we can see that each element of the queue has a priority {fixed order}). 


Priority Queue is an extension of queue with following properties.

Every item has a priority associated with it.
An element with high priority is dequeued before an element with low priority.
If two elements have the same priority, they are served according to their order in the queue.
*/

/* 
1) empty() function returns whether the queue is empty.
2) size() function returns the size of the queue.
3) Returns a reference to the top most element of the queue
4) push(g) function adds the element ‘g’ at the end of the queue.
5) pop() function deletes the first element of the queue.
6) swap() This function is used to swap the contents of one priority queue with another priority queue of same type and size.
Note: In priority_queue container, the elements are printed in reverse order because the top is printed first then moving on to other elements.
7) emplace() his function is used to insert a new element into the priority queue container.
8) Represents the type of object stored as an element in a priority_queue. It acts as a synonym for the template parameter.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void showpq(priority_queue<int,vector<int>> pq){
    priority_queue<int,vector<int>> q = pq;
    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

void showpqm(priority_queue<int,vector<int>,greater<int>> pqm){
    priority_queue<int,vector<int>,greater<int>> q = pqm;
    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main()
{
	priority_queue<int,vector<int>> pq;            //maxHeap               OR   priority_queue<int> pq;
/* 
.           3
.          / \      
.         2   1
*/
	pq.push(2);
	pq.push(3);
	pq.push(1);                        

    showpq(pq);        //3 2 1                 this is not STL function
	cout<<endl;

	cout<<pq.top()<<endl;     //3
	pq.pop();
	cout<<pq.top()<<endl;    //2

	cout<<endl;


	priority_queue<int,vector<int>,greater<int>> pqm;        //minHeap
/* 
.           1
.          / \
.         2   3
*/
	pqm.push(2);
	pqm.push(1);
	pqm.push(3);

    showpqm(pqm);                 //1 2 3         this is not STL function
	cout<<endl;


	cout<<pqm.top()<<endl;    //1
	pqm.pop();
	cout<<pqm.top()<<endl;   //2




	return 0;
}