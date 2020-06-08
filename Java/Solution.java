package CodePracticeJava;
import java.util.*;
/*
*	Solution class used for CodePractice methods.
*/
class Solution{
	/**
	*	Find the longest substring with no repeated characters
	* 	s String object transvered through to accomplish this method.
	*/
	public int lengthOfLongestSubstring(String s){
		List<String> nonRepeatingCharacters = new ArrayList<String>();
		boolean repeating;
		String currSubString = "";
		for(int stringIndex = 0; stringIndex < s.length(); stringIndex++){
			repeating = false;
			if (currSubString.indexOf(s.charAt(stringIndex)) != -1)
					repeating = true;
			if (repeating){
				nonRepeatingCharacters.add(currSubString);
				currSubString = s.substring(stringIndex,stringIndex+1);
			}
			else
				currSubString += s.substring(stringIndex,stringIndex+1);
		}
		
		String longest = "";
		for(int i = 0; i < nonRepeatingCharacters.size(); i++){
			//
			if (nonRepeatingCharacters.get(i).length() > longest.length()){
				longest = nonRepeatingCharacters.get(i);
			}
		}
		System.out.println(longest);
		return longest.length();
	}
}