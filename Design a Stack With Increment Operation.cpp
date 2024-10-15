class CustomStack {
public:
    int size;
    int top;
    int *arr;
    
    CustomStack(int maxSize) {
       this->size=maxSize;
       this->arr=new int[maxSize];
       top=-1;
        
    }
    
    void push(int x) {
        if(size-top>1){
            top++;
            arr[top]=x;
        }
    }
    
    int pop() {
        if(top!=-1){
            return arr[top--]; 
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);i++){
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */