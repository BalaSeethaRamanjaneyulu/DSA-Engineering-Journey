# 🤝 Contributing to Algorithmic Thinking Lab

Thank you for considering contributing! Here's how you can help.

---

## 📋 How to Contribute

### 1. Add a New Solution
- Navigate to the appropriate topic folder.
- Follow the **file naming convention**:
  ```
  <PlatformTag>_<ProblemNumber>_<ProblemName>.<ext>
  ```
- Include a header comment with:
  - Problem link
  - Approach used
  - Time & Space complexity

### 2. Improve Existing Solutions
- Optimize for better time/space complexity.
- Add clearer comments and explanations.
- Fix bugs or edge cases.

### 3. Add Notes
- Add or improve `README.md` files in topic folders.
- Share insights, patterns, or tricks you've discovered.

### 4. Add New Topics
- If a topic is missing, create a new folder following the existing structure.
- Include a `README.md` with the concept explanation.

---

## 📝 Code Style Guidelines

### C++
```cpp
// Problem: Two Sum
// Platform: LeetCode #1
// Approach: Hash Map
// Time: O(n) | Space: O(n)
// Link: https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.count(complement)) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
```

### Python
```python
# Problem: Two Sum
# Platform: LeetCode #1
# Approach: Hash Map
# Time: O(n) | Space: O(n)
# Link: https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
        return []
```

---

## 🔄 Pull Request Process

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`
3. Make your changes and commit: `git commit -m "Add: LC_001_Two_Sum solution"`
4. Push to your fork: `git push origin feature/your-feature-name`
5. Open a Pull Request with a clear description.

---

## 🐛 Reporting Issues

- Use GitHub Issues for bug reports or suggestions.
- Include the problem link, expected output, and actual output.

---

## 💡 Suggestions Welcome!

Have an idea for improving the repository structure, adding new sections, or better organization? Open an issue and let's discuss!

---

> *Every contribution, no matter how small, makes this resource better for everyone.* 🙌
