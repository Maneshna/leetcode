class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> maxHeap;
        int n = score.size();
        vector<string> result(n);

        for(int i= 0; i<n;i++){
            maxHeap.push({score[i],i});

        }

        int rank  =1;
        while(!maxHeap.empty()){
            auto topElement = maxHeap.top();
            maxHeap.pop();

            int originalIndex = topElement.second;
            
            if(rank == 1){
                result[originalIndex] = "Gold Medal";

            }
            else if(rank == 2){
                result[originalIndex] = "Silver Medal";

            }
            else if(rank == 3){
                result[originalIndex] = "Bronze Medal";
            }
            else{
                result[originalIndex]=to_string(rank);
            }
            rank++;


        }
        return result;

        
    }
};