class MinStack {
    private:
        stack<int> minStk;
        stack<int> stk;
        int min;
            
    public:
        MinStack() {
            min = INT_MAX;      
        }
        
        void push(int val) {
            stk.push(val);
            if (val <= min) {
                minStk.push(val);
                min = val;
            }
        }
        
        void pop() {
            if (stk.top() == min) {
                minStk.pop();
    
                min = (minStk.empty()) ? INT_MAX : minStk.top();
            }
            stk.pop();
        }
        
        int top() {
            int tp = stk.top();
            return tp;
        }
        
        int getMin() {
            return min;
        }
    };    