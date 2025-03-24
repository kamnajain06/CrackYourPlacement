class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() { 
    }
    
    bool book(int startTime, int endTime) {
        if(st.empty()){
            st.insert({startTime, endTime});
            return true;
        }
        for(auto &[start, end]:st){
            if(!(endTime <= start || startTime >= end)){
                return false;
            }
        }
        st.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */