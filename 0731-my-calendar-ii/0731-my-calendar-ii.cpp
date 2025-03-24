class MyCalendarTwo {
public:
    map<int,int> bookingMpp;
    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        cout<<"------"<<endl;
        if(bookingMpp.empty()){
            bookingMpp[startTime]++;
            bookingMpp[endTime]--;
            return true;
        }
        int prefixSum = 0;
        bookingMpp[startTime]++;
        bookingMpp[endTime]--;
        for(auto &[key, val]: bookingMpp){
            prefixSum += val;
            if(prefixSum == 3){
                bookingMpp[startTime]--;
                bookingMpp[endTime]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */