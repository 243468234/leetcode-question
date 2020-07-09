class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()){
            return {{}};
        }
		// 排序是为了去重
        sort(nums.begin(), nums.end());
		
        vector<vector<int>> rst;
        vector<bool> used(nums.size(), false);
        vector<int> tmp;

        dfs(rst, tmp, nums, used);
        return rst;        
    }

    void dfs(vector<vector<int>> &rst, vector<int> tmp, vector<int>& nums, vector<bool> &used){
        rst.push_back(tmp);

        // tmp的长度不应该超过nums
        if (tmp.size() >= nums.size()){
            return ;
        }

        for (int i = 0; i < nums.size(); ++i){
            // 去已用的
            if (used[i]){
                continue;
            }

            // 去重
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]){
                continue;
            }

            // 从小到大的顺序
            if (tmp.size() > 0 && tmp.at(tmp.size() - 1) > nums[i]){
                continue;
            }

            tmp.push_back(nums.at(i));
            used[i] = true;
            dfs(rst, tmp, nums, used);
            used[i] = false;
            tmp.pop_back();
        }
    }
};