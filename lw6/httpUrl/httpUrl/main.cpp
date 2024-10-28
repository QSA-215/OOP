#include <iostream>
#include "CHttpUrl.h"

std::string GetInfo(CHttpUrl url)
{
    std::string info;
    info = "URL: " + url.GetURL() + "\n";
    info += "Domain: " + url.GetDomain() + "\n";
    info += "Document: " + url.GetDocument() + "\n";
    info += "Protocol: ";
    if (url.GetProtocol() == Protocol::HTTP)
        info += "HTTP";
    else
        info += "HTTPS";
    info += "\n";
    info += "Port: " + std::to_string(url.GetPort()) + "\n";

    return info;
};

int main()
{
    std::string url;
    while (std::getline(std::cin, url))
    {
        try
        {
            CHttpUrl webUrl(url);
            std::cout << GetInfo(webUrl);
        }
        catch (const CUrlParsingError& error)
        {
            std::cout << "Error parsing URL: " << error.what() << std::endl;
        }
        catch (const std::invalid_argument& error)
        {
            std::cout << "Invalid argument error: " << error.what() << std::endl;
        }
    }
}