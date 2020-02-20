#include <vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {

  //O(N^2), O(1)
	// for(int i=0; i<array.size() -1 ; i++){
	// 	for(int j=i+1; j<array.size(); j++){
	// 		if(array[i] + array[j] == targetSum)
	// 			return vector<int>{array[i], array[j]};
	// 	}
	// }
	// return {};

  // O(N), O(N)
	// unordered_set<int> nums;
	// for(int num: array){
	// 	int potentialMatch = targetSum - num;
	// 	if(nums.find(potentialMatch) != nums.end()){
	// 		return vector<int>{potentialMatch, num};
	// 	}
	// 	else{
	// 		nums.insert(num);
	// 	}
	// }
	// return {};

  // O(NlogN), O(1)

	int left = 0, right = array.size() - 1;
	sort(array.begin(), array.end());
	while(left<right){
		int currentSum = array[left]+array[right];
		if(currentSum == targetSum)
			return vector<int>{array[left], array[right]};
		else if(currentSum > targetSum)
			right--;
		else if(currentSum < targetSum)
			left++;
	}
	return {};
}
