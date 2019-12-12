//https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    void siftDown (size_t i, vector <int>& heap){
        while (2*i+1<heap.size()){
            int left = 2*i+1;
            int right = 2*i+2;
            int j = left;
        if (right < heap.size() && heap[right] > heap[j]){
            j = right;
        }
        if (heap[i] >= heap[j]){
            break;
        }
            swap (heap[i],heap[j]);
            i=j;
        }
    }
    
    int extractMax (vector <int>& heap){
        int max = heap[0];
        swap (heap[0], heap[heap.size()-1]);
        heap.erase(heap.begin()+heap.size()-1);
        siftDown (0,heap);
        return max;
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        for (size_t i = nums.size()/2+1; i>0; --i){
            siftDown(i-1, nums);
        }
        int res =0;
        for (int i = 0; i<k; i++){
            res = extractMax(nums);
        }
        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().findKthLargest(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
