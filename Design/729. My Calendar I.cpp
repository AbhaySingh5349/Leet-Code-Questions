Question Link: https://leetcode.com/problems/my-calendar-i/

class MyCalendar {
public:
    
    map<int,int> mp;
    
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(start);
        
        if(it!=mp.end() && it->first < end) return false;
        
        if(it!=mp.begin()){
            it--;
            if(it->second > start) return false;
        }
        
        mp[start]=end;
        return true;
    }
};
