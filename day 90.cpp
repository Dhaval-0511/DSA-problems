class StockSpanner {
    // Stack stores pairs: {price, span}
    stack<pair<int, int>> st;

public:
    // Constructor: Initialize an empty stack
    StockSpanner() { }

    // Returns the stock span for today's price
    int next(int price) {
        int span = 1; // Span for current price at least covers today

        // While stack is not empty and price at stack's top <= current price
        while (!st.empty() && st.top().first <= price) {
            // Add the span of that day to today's span
            span += st.top().second;
            // Pop the previous day info as it is not useful anymore
            st.pop();
        }
        // Push current price and its calculated span
        st.push({price, span});
        return span;
    }
};


// prblm:https://leetcode.com/problems/online-stock-span