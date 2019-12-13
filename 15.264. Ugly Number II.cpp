
//https://leetcode.com/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> nums={1};
        unordered_set<long long> s;
        s.insert(1);
        vector<long long> primes = {2,3,5};
        
        long long min;
        while (n>0){
            min=extractMin(nums);
            for (int a: primes){
                if (s.find(min*a)==s.end()){
                    Insert(min*a,nums);
                    s.insert(min*a);
                }
            }
            n--;
        }
        return min;
    }
    
     void Insert(long long val, vector<long long>& heap){
        heap.push_back(val);
        siftUp(heap.size()-1, heap);
    }
    
     int extractMin(vector<long long>& heap){
        int min=heap[0];
        swap(heap[0],heap[heap.size()-1]);
        heap.erase(heap.begin()+heap.size()-1);
        siftDown(0,heap);
        return min;
    }
    
     void siftDown(size_t i, vector<long long>& heap){
        while (2*i+1 < heap.size()){
            int left=2*i+1;
            int right=2*i+2;
            int m=2*i+1;
            if (right < heap.size() && heap[right]<heap[m]){
                m=right;
            }
            if (heap[i]<heap[m]) break;
            swap(heap[i],heap[m]);
            i=m;
        }
    }
    
    void siftUp (size_t i, vector<long long>& heap){
        int par=(i-1)/2;
        while (i>0 && heap[i]<heap[par]){
            swap(heap[i],heap[par]);
            i=par;
            par=(i-1)/2;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().nthUglyNumber(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
