/*
Use cases of DFS:

    Letter Combination of Phone Numbers

            1       2       3
                   abc     def

            4       5       6
            ghi    jkl     mno

            7       8       9
            pqrs   tuv     wxyz


        We are given a phone number that is represented as a String, containing the digits 2 till 9

        Each of these digits is associated with a set of letters

        Our job is to take the entire phone number, and to write out all the different possible letter
            combinations that it could represent

            e.g. "23"  --> 2 could be a, b, c
                           3 could be d, e, f

            since 2 is followed by 3 therefore we can form the combinations like

                ad  ae  af
                bd  be  bf
                cd  ce  cf

-------

Dfs on this problem:

    start out with the first digit and write out all the possible letter combinations it could represent
        then for all of those digits write out all the possible letters the next digit could represent

                       '''
                    /   |   \
        2:      a       b       c
               /|\     /|\     /|\
        3:     def     def     def

        each one of these paths is a possible combinations that we want in out solution set

-------

Implementation of DFS could be done recursively and iteratively

    Recursive implementation is preferred as we don't need to define an explicit stack or a data structure
        instead we can just use the recursion call stack

*/

class Solution {
    public List letterCombinations(String digits) {
        ArrayList<String> result = new ArrayList<>();

        // check input and call DFS
        if (digits != null && digit.length() > 0) {
            String arr [] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            dfs(digits, arr, result, new StringBuilder(), 0);
        }

        return result;
    }

    private void dfs(String digits, String [] arr, ArrayList<String> result, StringBuilder sb, int index) {

        // first step of standard recursion rule
        // when to stop searching

        if (index == digits.length()) {
            result.add(sb.toString());
            return;
        }

        int digit = Character.getNumericValue(digits.charAt(index));
        String letters = arr[digit];

        // second step, which paths you will explore from here
        for (int i = 0; i < letters.length(); i++) {
            char ch = letters.charAt(i);
            sb.append(ch);
            dfs(digits, arr, result, sb, index + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
