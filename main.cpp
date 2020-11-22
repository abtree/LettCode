#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <stack>
#include <array>
#include <bitset>
#include <set>

using namespace std;

#include "TwoNumAdd.h"				//1 两数之和
#include "TwoListAdd.h"				//2 两数相加
#include "SubString.h"				//3 无重复字符的最长子串
#include "ArrayMiddle.h"			//4 寻找两个正序数组的中位数
#include "Palindrome.h"				//5 最长回文子串
#include "Convert.h"				//6 Z 字形变换
#include "IntReverse.h"				//7 整数反转
#include "Atoi.h"					//8 字符串转换整数 (atoi)
#include "IsPalindrome.h"			//9 回文数
#include "Regex.h"					//10 正则表达式匹配
#include "MaxArea.h"				//11 盛最多水的容器
#include "IntToRoman.h"				//12 整数转罗马数字
#include "RomanToInt.h"				//13 罗马数字转整数
#include "LongestComPrefix.h"		//14 最长公共前缀
#include "ThreeSums.h"				//15 三数之和
#include "ThreeSumClosest.h"		//16 最接近的三数之和
#include "LetterCombinations.h"		//17 电话号码的字母组合
#include "FourSum.h"				//18 四数之和
#include "RemoveNthFromEnd.h"		//19 删除链表的倒数第N个节点
#include "IsValid.h"				//20 有效的括号
#include "MergeTwoLists.h"			//21 合并两个有序链表
#include "GenerateParenthesis.h"	//22 括号生成
#include "MergeKLists.h"			//23 合并K个升序链表
#include "SwapPairs.h"				//24 两两交换链表中的节点
#include "ReverseKGroup.h"			//25. K 个一组翻转链表
#include "RemoveDuplicates.h"		//26. 删除排序数组中的重复项
#include "RemoveElement.h"			//27. 移除元素
#include "StrStr.h"					//28. 实现 strStr()
#include "Divide.h"					//29. 两数相除
#include "FindSubString.h"			//30. 串联所有单词的子串
#include "NextPermutation.h"		//31. 下一个排列
#include "LongestValidParentheses.h"	//32. 最长有效括号
#include "SearchInRotatedSortedArray.h" //33 搜索旋转排序数组
#include "SearchRange.h"			//34 在排序数组中查找元素的第一个和最后一个位置
#include "SearchInsert.h"			//35 搜索插入位置
#include "ValidSudoku.h"			//36 有效的数独
#include "SolveSudoku.h"			//37. 解数独
#include "SolveSudoku2.h"			//37. 解数独
#include "CountAndSay.h"			//38. 外观数列
#include "CombinationSum.h"			//39. 组合总和

void group1(int typ) {
	switch (typ)
	{
	case 1:
		CTwoNumAdd::Test();
		break;
	case 2:
		CTwoListAdd::Test();
		break;
	case 3:
		CSubString::Test();
		break;
	case 4:
		CArrayMiddle::Test();
		break;
	case 5:
		CPalindrome::Test();
		break;
	case 6:
		Convert::Test();
		break;
	case 7:
		IntReverse::Test();
		break;
	case 8:
		Atoi::Test();
		break;
	case 9:
		IsPalindrome::Test();
		break;
	case 10:
		CRegexSimple::Test();
		break;
	default:
		break;
	}
}

void group2(int typ) {
	switch (typ)
	{
	case 1:
		CMaxArea::Test();
		break;
	case 2:
		CIntToRoman::Test();
		break;
	case 3:
		CRomanToInt::Test();
		break;
	case 4:
		CLongestComPrefix::Test();
		break;
	case 5:
		CThreeSums::Test();
		break;
	case 6:
		CThreeSumClosest::Test();
		break;
	case 7:
		CLetterCombinations::Test();
		break;
	case 8:
		CFourSum::Test();
		break;
	case 9:
		CRemoveNthFromEnd::Test();
		break;
	case 10:
		CIsValid::Test();
		break;
	default:
		break;
	}
}

void group3(int val){
	switch (val)
	{
	case 1:
		CMergeTwoLists::Test();
		break;
	case 2:
		CGenerateParenthesis::Test();
		break;
	 case 3:
	 	CMergeKLists::Test();
	 	break;
	case 4:
		CSwapPairs::Test();
		break;
	case 5:
		CReverseKGroup::Test();
		break;
	case 6:
		CRemoveDuplicates::Test();
		break;
	case 7:
		CRemoveElement::Test();
		break;
	case 8:
		CStrStr::Test();
		break;
	case 9:
		CDivide::Test();
		break;
	case 10:
		CFindSubString::Test();
		break;
	default:
		break;
	};
}

void group4(int val) {
	switch (val)
	{
	case 0:
		CNextPermutation::Test();
		break;
	case 1:
		CLongestValidParentheses::Test();
		break;
	case 2:
		CSearchRotatedSortedArray::Test();
		break;
	case 3:
		CSearchRange::Test();
		break;
	case 4:
		CSearchInsert::Test();
		break;
	case 5:
		ValidSudoku::Test();
		break;
	case 6:
		SolveSudoku::Test();
		break;
	case 7:
		SolveSudoku2::Test();
		break;
	case 8:
		CountAndSay::Test();
		break;
	case 9:
		CombinationSum::Test();
		break;
	default:
		break;
	}
}

int main() {
	//group1(0);
	//group2(0);
	//group3(0);
	group4(9);

	return 0;
}