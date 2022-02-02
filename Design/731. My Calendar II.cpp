Question Link: https://leetcode.com/problems/trapping-rain-water/

class MyCalendarTwo {
public:
    
    map<int,int> mp;
    
    MyCalendarTwo() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]++, mp[end]--;
        
        int count=0;
        for(auto it : mp){
            count += (it.second);
            if(count>2){
                mp[start]--, mp[end]++;
                return false;
            }
        }
        return true;
    }
};
