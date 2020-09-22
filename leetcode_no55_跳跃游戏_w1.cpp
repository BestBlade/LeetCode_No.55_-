/*----------------------------------------------------------------------|
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-----------------------------------------------------------------------*/

/*	贪心算法
*
*	执行用时：16 ms, 在所有 C++ 提交中击败了98.49%的用户
*	内存消耗：12.5 MB, 在所有 C++ 提交中击败了65.13%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool canJump(vector<int>& nums)
{
	int max_pos = 0;
	
	for (int i = 0; i < nums.size(); i++)
	{
		if (i <= max_pos)
		{
			max_pos = max(max_pos, i + nums[i]);
		}
		else
		{
			return false;
		}

		if (max_pos >= nums.size() - 1)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	vector<int> nums = {2,5,0,0};
	
	cout << canJump(nums) << endl;
}