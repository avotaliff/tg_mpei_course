//https://leetcode.com/problems/last-stone-weight/
class Solution {
public:
    int left(int i){
         return 2*i + 1;
    }
    
    int right(int i){
        return 2*i + 2;
    }
    
    void build_heap(vector<int>& arr, int n){
        int start_index;
        start_index = n/2 - 1;
        for(int i=start_index;i>=0;i--){
            max_heapify(arr,i,n);
        }
    }
    
    void max_heapify(vector<int>& arr, int i, int n){
        int l, r, largest, temp;
        l = left(i);
        r = right(i);
        if(l<n && arr[l] > arr[i])
            largest = l;
        else
            largest = i;
        if(r<n && arr[r] > arr[largest])
            largest = r;
        if(largest != i){
            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            max_heapify(arr,largest,n);
        }
    }
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        build_heap(stones,n);
        int max1, max2;
        for(int i=0;i<n;i++){
            max1 = stones[0];
            stones[0] = 0;
            max_heapify(stones,0,n);
            max2 = stones[0];
            if(max1 == max2)
                stones[0] = 0;
            else
                stones[0] = max1 - max2;
            max_heapify(stones,0,n);
        }
        return stones[0];
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> stones = stringToIntegerVector(line);
        
        int ret = Solution().lastStoneWeight(stones);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
