class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            std::map<int, int, std::greater<int>> sorted_cars;
            int num_cars = position.size();
            for (int i = 0; i < num_cars; i++) {
                sorted_cars.insert({position[i], speed[i]});
            }
            std::stack<std::pair<int, int>> car_stack;
            for (auto car = sorted_cars.begin(); car != sorted_cars.end(); car++) {
                if (car == sorted_cars.begin()) car_stack.push({car->first, car->second});
                auto next_car = std::next(car);
                if (next_car == sorted_cars.end()) break;
                std::pair<int,int> top_pair = car_stack.top();
                int top_car_pos = top_pair.first;
                int top_car_speed = top_pair.second;
    
                if (next_car->second <= top_car_speed) {
                    car_stack.push({next_car->first, next_car->second});
                }
                else {
                    float time_to_catch_up = float(target - top_car_pos) / top_car_speed;
                    float next_car_time_to_end = float(target - next_car->first) / next_car->second;
                    if (next_car_time_to_end > time_to_catch_up) {
                        car_stack.push({next_car->first, next_car->second});
                    }
                }
            }
            return car_stack.size();
        }
    };    