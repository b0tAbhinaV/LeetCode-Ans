class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() || num < leftMaxHeap.top()) leftMaxHeap.push(num);

        else rightMinHeap.push(num);
        //always maintain leftminheap size one greater or equal than rightmaxheap.
        if(abs((int)leftMaxHeap.size() - (int)rightMinHeap.size()) > 1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop(); 
        }
        else if(rightMinHeap.size() > leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();        
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()){
            double mean =  (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
            return mean;
        }
        else return leftMaxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */