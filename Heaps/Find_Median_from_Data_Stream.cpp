/* Leetcode  Submission    (Connect n ropes with minimum cost) */

/* Problem Statement: The median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value, and the median is the mean of the two middle values.

    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

    MedianFinder() initializes the MedianFinder object.
    void addNum(int num) adds the integer num from the data stream to the data structure.
    double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted. 
*/



/* Solution: Using priority queue */
// Time complexity : O(logN) addNum,   O(1) findMedian   
// Space complexity : O(N)           


/* Intuition
As the data stream continuously come in, we have to consider the middle most element everytime for calculating the median.

TWO HEAP INTUITION : We have to consider middle element/s where all other elements are sorted as data stream come. 
Heaps come into picture with less time complexity to achieve this. So, we keep two heaps, one min heap and one max 
heap and keep a track of middle elements by balancing each heap.
The left heap is containing elements in decreasing order (Max to Min) and right heap is in increasing order (Min to Max) 
but all the elements are greater than the left heap elements. We start pushing the elements in left heap and try to balance 
it everytime by comparing with the new elements and with heap size and accordingly put it into the right heap. */


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
