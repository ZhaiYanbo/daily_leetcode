//扁平化嵌套列表迭代器

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * @brief dfs，直接线性化，本质上不是迭代器
 * 
 */
class NestedIterator {
    vector<int>v;
    int index;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        dfs(nestedList);
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index != v.size();
    }

    void dfs(vector<NestedInteger> &nestedList) {
        for(int i = 0; i < nestedList.size(); i++) {
            if(nestedList[i].isInteger())   v.push_back(nestedList[i].getInteger());
            else                            dfs(nestedList[i].getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * @brief 栈
 * 
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<pair<vector<NestedInteger>::iterator,vector<NestedInteger>::iterator>>stk;
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(),nestedList.end());
    }
    
    int next() {
        return stk.top().first++->getInteger();
    }
    
    bool hasNext() {
        while(!stk.empty()) {
            auto &p = stk.top();
            // 遍历到当前列表末尾，出栈
            if(p.first == p.second) {
                stk.pop();
                continue;
            }
            //只有一个整数元素
            if(p.first->isInteger()) {
                return true;
            }
            //是一个整数列表,则将其入栈，且迭代器指向下一个元素
            auto &lst = p.first++->getList();
            stk.emplace(lst.begin(),lst.end());
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */