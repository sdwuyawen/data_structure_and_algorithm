class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        if (strs.size() == 0)
          return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
//            if (prefix.length() == 0 || strs[i].length() == 0)
//               return "";

            int len = prefix.length() < strs[i].length() ? prefix.length() : strs[i].length();

            int j;

            for (j = 0; j < len; ++j)
            {
                if (prefix[j] != strs[i][j])
                    break;
            }

            prefix = prefix.substr(0,j);

        }

        return prefix;
    }
};
