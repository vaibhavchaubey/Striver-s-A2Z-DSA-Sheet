/* Numbers are coming and we have to tell median after each input */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int, vector<int>> maxHeap;
void addNum(int x)
{
    if(maxHeap.empty() || maxHeap.top() > x){
        maxHeap.push(x);
    }
    else{
        minHeap.push(x);
    }

    if(maxHeap.size() > minHeap.size() + 1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size() > maxHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();    
    }
}

double findMedian(){
    if(minHeap.size() == maxHeap.size()){
        return (minHeap.top() + maxHeap.top())/2.0;
    }
    else if(maxHeap.size() > minHeap.size()){
        return maxHeap.top();
    }
    else{
        return minHeap.top();
    }
}
int main()
{
    addNum(10);
    cout<<findMedian()<<endl;

    addNum(15);
    cout<<findMedian()<<endl;

    addNum(21);
    cout<<findMedian()<<endl;

    addNum(30);
    cout<<findMedian()<<endl;

    addNum(18);
    cout<<findMedian()<<endl;

    addNum(19);
    cout<<findMedian()<<endl;

    return 0;
}




/* Leetcode Submission      (295. Find Median from Data Stream)   */


/* Intuition
As the data stream continuously come in, we have to consider the middle most element everytime for calculating the median.

TWO HEAP INTUITION : We have to consider middle element/s where all other elements are sorted as data stream come. 
Heaps come into picture with less time complexity to achieve this. So, we keep two heaps, one min heap and one max 
heap and keep a track of middle elements by balancing each heap.
The left heap is containing elements in decreasing order (Max to Min) and right heap is in increasing order (Min to Max) 
but all the elements are greater than the left heap elements. We start pushing the elements in left heap and try to balance 
it everytime by comparing with the new elements and with heap size and accordingly put it into the right heap. */

/* Solution: Using priority queue */
// Time complexity : O(logN) addNum,   O(1) findMedian   
// Space complexity : O(N)           


// class MedianFinder {
// public:
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     priority_queue<int, vector<int>> maxHeap;
    
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         if(maxHeap.empty() || maxHeap.top() > num){
//             maxHeap.push(num);
//         }
//         else{
//             minHeap.push(num);
//         }
        
//         if(maxHeap.size() > minHeap.size() + 1){
//             minHeap.push(maxHeap.top());
//             maxHeap.pop();
//         }
//         else if(minHeap.size() > maxHeap.size()){
//             maxHeap.push(minHeap.top());
//             minHeap.pop();
//         }
//     }
    
//     double findMedian() {
//         if(minHeap.size() == maxHeap.size()){
//             return (minHeap.top() + maxHeap.top())/2.0;
//         }
//         else if(maxHeap.size() > minHeap.size()){
//             return maxHeap.top();
//         }
//         else{
//             return minHeap.top();
//         }
//     }
// };
