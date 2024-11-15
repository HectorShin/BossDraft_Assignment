# BossDraft Assignment
Author: Hector Shin Emura

Understanding the problem:
- For this problem, I considered 
    Case 1: When there is a unexpected character outside of the XML structure.
            Example: "a<test></test>>" ; "<test></test>a"
            Note that the caracter 'a' in both examples are unexpected, because they are outside of every instance of XML structure
            But "<test1>a<test2></test2><test1>" is valid, because the character 'a' is inside of '<test1>'
    Case 2: If the input string does not have any XML structure
            Example: "test"
    Case 2: When the opening tag and the closing are different
            Example: "<test1></test2>"
    Case 3: When the tags are incorrectly nested
            Example: "<test1><test2></test1><test2>"
            Note that we should close '<test2>' before closing '<test1>'

Resolving the problem
- To resolve this problem, I used iteraators to manipulate the string. I used iterators instead of indexes because it´s flexibility. The iterators      can be used with any data structure. So then it would be really easy to adapt the code to other data structure if necessary. Moreover, the string library in C++ has a lot of members that are useful for using iterators, which saves storage and processing.
- I usedd recursion for this problem, because of it´s simplificty for understanding the code for everyone who reads it

The code
- I used 4 iterators for this problem:
    1) The character '<' that opens the opening tag
    2) The character '>' that closes the opening tag
    3) The character '<' that opens the closing tag
    4) The character '>' that closes the closing tag
- First of all, I treated the Case 1, by checking if the first character of the input string is '<> and checking if the last character of the input tring is '>'. In the first call, these characters need to be in these positions. For the rest of the recursive calls, this checking is not necessary anymore. This verification also resolves the Case 2, because if there isn´t any '<' or '>', then the mandatory positions are not correct.
- For the rest of the calls, firstly I find the positions of the opening and closing tags that are positioned at the ends of the string. Then, I check if they are identical. If they are, I remove then of the input string and call the DetermineXml function again. The next calls will treat the others tags that are positions at the ends.
- If there aren´t any tags anymore (Consider, in this case, simple strings), then the XML structure is correct and returns true.
