#include <string>
#include <iostream>

//feel free to add other classes/methods if you want
bool DetermineXml(const std::string &input, bool firstCall = true)
{
    size_t openStartTagPosition = input.find('<');
    size_t closeStartTagPosition = input.find('>');
    size_t openEndTagPosition = input.rfind('<');
    size_t closeEndTagPosition = input.rfind('>');

    if (firstCall && (openStartTagPosition != 0 || closeEndTagPosition != input.length() - 1))
    {
        return false;
    }
    else if (openStartTagPosition == std::string::npos || closeStartTagPosition == std::string::npos || openEndTagPosition == std::string::npos || closeEndTagPosition == std::string::npos)
    {
        return true;
    }
    else
    {
        size_t length = closeStartTagPosition - openStartTagPosition + 1;
        std::string startTag = input.substr(openStartTagPosition, length);

        length = closeEndTagPosition - openEndTagPosition + 1;
        std::string endTag = input.substr(openEndTagPosition, length);

        startTag.insert(1, "/");
        
        if (startTag == endTag)
        {
            length = openEndTagPosition - closeStartTagPosition;
            std::string newInput = input.substr(closeStartTagPosition + 1, length - 1);
            return DetermineXml(newInput, false);
        }
        else return false;
    }
}
