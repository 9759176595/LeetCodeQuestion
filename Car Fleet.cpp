class Solution {
public:
     int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
		// create map of position:arrival_time
        map<int, double> m;
        for(int i = 0; i < position.size(); i++){
            m[position[i]] = (double)(target - position[i]) / speed[i];
        }
       
        int num_fleets = 0;
        double latest_arrival_time = 0;
		   
		// for every element starting at the back of the map, if the arrival time is 
		// greater than the latest_arrival_time, we should create a new fleet
        for(auto i = m.rbegin(); i != m.rend(); i++){
            if(i->second > latest_arrival_time){
                num_fleets++;
                latest_arrival_time = i->second;
            }
        }
        
        return num_fleets;
    }
};
