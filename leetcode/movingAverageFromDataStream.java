class MovingAverage {
    
    double sum;
    int size;
    Deque<Integer> windowList;

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        this.size = size;
        sum = 0;
        windowList = new LinkedList<>();
    }
    
    public double next(int val) {
        if(windowList.size()==size){
            sum-=windowList.removeFirst();
        }
        sum+=val;
        windowList.addLast(val); 
        return sum/windowList.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
