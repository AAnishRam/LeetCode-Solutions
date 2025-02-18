class MinStack {

private:
    MinStack *head = nullptr;

public:

    int val;
    int mini;
    MinStack *next;

    MinStack()
    {
        
    }

    MinStack(int val, int mini, MinStack *next) {
        this->val = val;
        this->mini = mini;
        this->next = next;
    }
    
    void push(int val) {
        if(head == nullptr)
        {
            head = new MinStack(val, val, nullptr);
        }
        else
        {
            MinStack *temp = head;
            head = new MinStack(val, min(val, temp->mini), temp);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */