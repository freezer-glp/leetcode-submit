/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

 

Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
 

Note:

Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
There will be at most 10000 calls to StockSpanner.next per test case.
There will be at most 150000 calls to StockSpanner.next across all test cases.
The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.
*/

/*
最后一个case总是超时，分析发现存在大量连续重复的输入，比如： ...[280],[280],[280],[280],[281],[281],[281]...
这分明就是在考察Cache思想呀！！！
使用一个cache记录上一次输入
如果和上次相同，不用计算，直接利用上一次结果+1即可。
如果没有命中，利用跳表思想，跳过连续小值，快速计算当前结果。
*/
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
      if (p.empty() || last_ > price) {
        p.push_back(price);
        v.push_back(1);
        last_ = price; // cache last price
        return 1;
      }
      
      // cache hint!
      if (last_ == price) {  
        p.push_back(price);
        v.push_back(v.back() + 1);
        last_ = price; // cache last price
        return v.back();
      }
      
      // cache not hint!
      int i = p.size() - 1;
      while(i>=0 && p[i] <= price) {
        if (v[i] == 1) {
          i -= 1;
        } else {
          i -= (v[i] -1);
        }
      }
      v.push_back(1 + p.size()-1-i);
      p.push_back(price);
      last_ = price; // cache last price
      return v.back();
    }
    int last_;  // cache last price
    vector<int> v;
    vector<int> p;
};

// 补充一个单调栈的写法，真漂亮
class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() {    
    }
    int next(int price) {
        int num = 1;
        while (!s.empty() && s.top().first <= price) {
            num += s.top().second;
            s.pop();
        }
        s.push({price, num});
        return num;
    }
};