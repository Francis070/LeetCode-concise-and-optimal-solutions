struct node{
    int value;
    node(){
        this->value = 0;
    }
    node(int val){
        this->value = val;
    };  
};

struct segtree{
    int size;
    vector<node> tree;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;

        tree.resize((2 * size));
    }

    node merge(node a, node b){  // this can be made according the requirement
        node result;

        result.value = a.value + b.value;
        return result;
    }

    void build(int pos, int value, int l, int r, int parent){
        if(r - l == 1){
            node curnode(value);
            tree[parent] = curnode;
            return;
        }

        int mid = (l + r)/2;

        if(pos < mid){
            build(pos, value, l, mid, (2 * parent) + 1);
        }
        else{
            build(pos, value, mid, r, (2 * parent) + 2);
        }

        tree[parent] = merge(tree[(2 * parent) + 1], tree[(2 * parent) + 2]);
    }

    void set(int pos, int val){
        build(pos, val, 0, size, 0);
    }

    node range_queries(int range_l, int range_r, int start, int end, int parent){
        // lies outside range
        if(start >= range_r || range_l >= end){
            node garbage;
            return garbage;
        }

        // lies inside range
        if(start >= range_l && end <= range_r){
            return tree[parent];
        }
        int mid = (start + end)/2;

        node left_half = range_queries(range_l, range_r, start, mid, (2 * parent) + 1);
        node right_half = range_queries(range_l, range_r, mid , end, (2 * parent) + 2);

        node result = merge(left_half, right_half);

        return result;
    }

    int range_result(int range_l, int range_r){
        node res = range_queries(range_l, range_r, 0, size, 0);

        // use the value returned by range_queries.
        // print it.
        return res.value;
    }
};

class NumArray {
public:
    segtree * tr = new segtree();

    NumArray(vector<int>& nums) {
        tr->init(nums.size());
        int i = 0;
        for(int x : nums){
            tr->set(i, x);
            i++;
        }    
    }
    
    void update(int index, int val) {
        tr->set(index, val);
    }
    
    int sumRange(int left, int right) {
        int result = tr->range_result(left, right + 1);
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */