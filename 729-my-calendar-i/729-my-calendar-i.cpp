class MyCalendar {
    unordered_map<int, int> hashMap;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto& interval : hashMap) {
            if (!(interval.first >= end || interval.second <= start)) {
                return false;
            }
        }
        hashMap[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */