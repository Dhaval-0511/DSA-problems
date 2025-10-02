class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        
        for (int ast : asteroids) {
            // Assume the current asteroid needs to be pushed
            bool alive = true;
            // Handle possible collisions when ast is moving left
            while (alive && ast < 0 && !stack.empty() && stack.back() > 0) {
                if (stack.back() < -ast) {
                    // Top of stack (right-moving) is smaller: it explodes
                    stack.pop_back();
                    // Continue checking next one in stack
                } else if (stack.back() == -ast) {
                    // Both are equal: both explode
                    stack.pop_back();
                    alive = false;
                } else {
                    // Right-moving is bigger: current left-moving explodes
                    alive = false;
                }
            }
            // If survived, push to stack
            if (alive)
                stack.push_back(ast);
        }
        return stack;
    }
};

// prblm:https://leetcode.com/problems/asteroid-collision