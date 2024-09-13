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

        result.value = a.value ^ b.value;
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

    node range_queries(int range_l, int range_r, int l, int r, int parent){
        // lies outside range
        if(l >= range_r || range_l >= r){
            node garbage;
            return garbage;
        }

        // lies inside range
        if(l >= range_l && r <= range_r){
            return tree[parent];
        }
        int mid = (l + r)/2;

        node left_half = range_queries(range_l, range_r, l, mid, (2 * parent) + 1);
        node right_half = range_queries(range_l, range_r, mid , r, (2 * parent) + 2);

        node result = merge(left_half, right_half);

        return result;
    }

    int range_result(int range_l, int range_r){
        node res = range_queries(range_l, range_r, 0, size, 0);

        // use the value returned by range_queries.
        // print it.
        // cout<<res.value<<endl;
        return res.value;
    }
};

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        segtree * tree = new segtree();

        int n = arr.size();

        tree->init(n);

        for(int i = 0; i < n; i++){
            tree->set(i, arr[i]);
        }

        // for(auto x : tree->tree){
        //     cout<<x.value<<" ";
        // }

        int m = queries.size();
        vector<int> ans(m);

        for(int i =0; i < m; i++){
            int l = queries[i][0], r = queries[i][1];

            int res = tree->range_result(l, r + 1);
            ans[i] = res;
        }

        return ans;
    }
};