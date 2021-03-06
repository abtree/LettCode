#include <iostream>
#include <vector>

using namespace std;

//4 寻找两个正序数组的中位数
class CArrayMiddle {
	/*
	给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
	请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
	你可以假设 nums1 和 nums2 不会同时为空。

	示例 1:
	nums1 = [1, 3]
	nums2 = [2]
	则中位数是 2.0

	示例 2:
	nums1 = [1, 2]
	nums2 = [3, 4]
	则中位数是 (2 + 3)/2 = 2.5
	*/
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		/*
		二分排除法 相当于二叉树
		简单来说
		假如第一个数组是[1,2,3,4] size = 4;
		假如第一个数组是[5,6,7,8,9] size = 5;
		总长度是9，由于两个数组都是有序的（这很重要）
		所以我们只需要排除两个数组中最小的4个数 剩下的5个数中最小的数就是中位数了
		注：具体实现时要注意边界问题

		第一步 totalSize = 9, exclude = 4;		//总共9个 需要排除4个
		eachArrayWantExclude = 2, A1_Min = [1, 2] A2_Min = [5, 6] //假设每个数组排除2个
		Because A1_Min[1] <= A2_Min[2]	//由于第一个数组取出的前两个元素比第二个小
		A1 = A1 - A1_Min = [3, 4]	//所以排除第一个数组的两个元素
		exclude = exclude - size(A1_Min) = 4 - 2 = 2	//剩余需要排除的元素为两个

		第二步
		由于我们还需要排除最小的两个数，我们可以从两个数组中各取最小的1个数，排除小的一个
		这样我们就只需要在排除一个数
		A1 = [4]
		exclude = 1

		第三步
		由于我们还需要排除一个数 我们可以再比较两个数组中最小的一个数，排除小的一个
		A1 = []
		exclude = 0;

		由于我们需要排除0个数，所以我们取出两个数组中最小的一个数就可以了

		注：如果两个数组总长度 totalSize为偶数
		我们需要先将totalSize + 1，这样会多排除一个，即最后排除的一个也要保留
		(于是我们可以将基数多排除一次 这样就统一了)
		*/
		int i = 0, j = 0, k = 0, c1 = 0, c2 = 0;
		double ret = 0;
		auto q = std::div(nums1.size() + nums2.size(), 2);
		if (q.rem > 0) {
			++q.quot;	//这里表示要排除的数的个数
		}

		//特殊情况(其中一个为空)
		if (nums1.empty()) {
			ret = nums2[q.quot - 1];
			if (q.rem == 0) {
				ret += nums2[q.quot];
				ret /= 2.0;
			}
			return ret;
		}
		if (nums2.empty()) {
			ret = nums1[q.quot - 1];
			if (q.rem == 0) {
				ret += nums1[q.quot];
				ret /= 2.0;
			}
			return ret;
		}

		//正常情况
		while (q.quot > 1) {
			k = q.quot / 2 - 1;
			c1 = k + i;
			c2 = k + j;
			//异常处理
			if (c1 >= nums1.size()) {
				c1 = nums1.size() - 1;
			}
			if (c2 >= nums2.size())
				c2 = nums2.size() - 1;

			if (nums1[c1] < nums2[c2]) {
				//排除nums1中前k+i个数
				q.quot -= c1 - i + 1;
				i = c1 + 1;
				if (i >= nums1.size()) {
					//说明nums1已经是空数组了
					ret = nums2[j + q.quot - 1];
					if (q.rem == 0) {
						ret += nums2[j + q.quot];
						ret /= 2.0;
					}
					return ret;
				}
			}
			else {
				//排除nums2中前k+j个数
				q.quot -= c2 - j + 1;
				j = c2 + 1;

				if (j >= nums2.size()) {
					//说明nums1已经是空数组了
					ret = nums1[i + q.quot - 1];
					if (q.rem == 0) {
						ret += nums1[i + q.quot];
						ret /= 2.0;
					}
					return ret;
				}
			}
			//q.quot -= k + 1;
		}
		//取出最后一个排除的数 就是需要的数
		if (nums1[i] > nums2[j]) {
			ret = nums2[j];
			++j;
			if (q.rem == 0 && j >= nums2.size()) {
				ret += nums1[i];
				ret /= 2.0;
				return ret;
			}
		}
		else {
			ret = nums1[i];
			++i;
			if (q.rem == 0 && i >= nums1.size()) {
				ret += nums2[j];
				ret /= 2.0;
				return ret;
			}
		}
		//处理总个数为偶数的问题
		if (q.rem == 0) {
			ret += nums1[i] > nums2[j] ? nums2[j] : nums1[i];
			ret /= 2.0;
		}
		return ret;
	}

	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		/*
			双指针遍历法 要比二分法逻辑简单得多
			两个指针分别指向两个数组的头
			然后比较两个指针指向的当前值
			哪个小，哪个就移动到下一位
			直到移动到需要的位置 
			比如两个数组总长度为3 总共需要移动的k值为1 取接下来1个值
			如果两个数组总长度为3 总共需要移动的k值为1 取接下来2个值
		*/
		int i = 0, j = 0;
		double ret = 0;
		auto q = std::div(nums1.size() + nums2.size(), 2);
		if (q.rem > 0)
			++q.quot;

		for (int k = q.quot - 1; k > 0; --k) {
			if (i >= nums1.size()) {
				++j;
				continue;
			}
			if (j >= nums2.size()) {
				++i;
				continue;
			}
			if (nums1[i] > nums2[j]) {
				++j;
			}
			else {
				++i;
			}
		}
		//取第一个数
		if (i >= nums1.size()) {
			ret = nums2[j];
			++j;
		}else if (j >= nums2.size()) {
			ret = nums1[i];
			++i;
		}else if (nums1[i] > nums2[j]) {
			ret = nums2[j];
			++j;
		}
		else {
			ret = nums1[i];
			++i;
		}
		if (q.rem > 0)
			return ret;
		//取第二个数
		if (i >= nums1.size()) {
			ret += nums2[j];
		}else if (j >= nums2.size()) {
			ret += nums1[i];
		}else if (nums1[i] > nums2[j]) {
			ret += nums2[j];
		}
		else {
			ret += nums1[i];
		}
		ret /= 2.0;
		return ret;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v1{};
	vector<int> v2{1,2,3};
	vector<int> v3{ 1,2,3,4 };
	vector<int> v4{ 2,3,4,5 };
	vector<int> v5{ 4,5,6,7,8,9,10,11 };
	vector<int> v6{ 1,2 };
	vector<int> v7{ 3,4 };
	vector<int> v8{ -1, 3 };
	CArrayMiddle am;
	double ret = am.findMedianSortedArrays2(v1, v2);
	cout << ret << " -> 2" << endl;
	ret = am.findMedianSortedArrays2(v3, v4);
	cout << ret << " -> 3" << endl;
	ret = am.findMedianSortedArrays2(v2, v5);
	cout << ret << " -> 6" << endl;
	ret = am.findMedianSortedArrays2(v3, v5);
	cout << ret << " -> 5.5" << endl;
	ret = am.findMedianSortedArrays2(v6, v7);
	cout << ret << " -> 2.5" << endl;
	ret = am.findMedianSortedArrays2(v6, v8);
	cout << ret << " -> 1.5" << endl;
	return 0;
}