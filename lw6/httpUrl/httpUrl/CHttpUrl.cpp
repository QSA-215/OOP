#include "CHttpUrl.h"
#include <regex>

CHttpUrl::CHttpUrl(const std::string& url)
{
    std::regex urlPattern(R"(^((https?)://)?([\w-\.^_]+\.[\w^_]{2,})(:(\d+))?(/.*)?$)");
    std::smatch urlFinds;

    if (!std::regex_match(url, urlFinds, urlPattern))
        throw CUrlParsingError("Invalid URL");

    if (urlFinds[2] == "http")
    {
        m_protocol = Protocol::HTTP;
        m_port = 80;
    }
    else if (urlFinds[2] == "https")
    {
        m_protocol = Protocol::HTTPS;
        m_port = 443;
    }
    else
        throw CUrlParsingError("Unknown protocol");

    m_domain = urlFinds[3];

    if (urlFinds[5].matched)
    {
        if (std::stoi(urlFinds[5].str()) < 0 || std::stoi(urlFinds[5].str()) > 65536)
            throw CUrlParsingError("Invalid port");

        m_port = static_cast<unsigned short>(std::stoi(urlFinds[5].str()));
    }

    if (urlFinds[6].matched)
        m_document = urlFinds[6].str();
    else
        m_document = "/";
}

CHttpUrl::CHttpUrl(
    const std::string& domain,
    const std::string& document,
    Protocol protocol)
{
    if (domain == "")
    {
        throw std::invalid_argument("Invalid domain");
    }
    if (document == "")
    {
        throw std::invalid_argument("Invalid document");
    }
    if (document[0] != '/')
    {
        m_document = '/' + document;
    }

    m_domain = domain;
    m_document = document;
    m_protocol = protocol;
    if (protocol == Protocol::HTTP)
        m_port = 80;
    else
        m_port = 443;
}

CHttpUrl::CHttpUrl(
    const std::string& domain,
    const std::string& document,
    Protocol protocol,
    unsigned short port)
{
    if (domain == "")
        throw std::invalid_argument("Invalid domain");

    if (document == "")
        throw std::invalid_argument("Invalid document");

    if (port <= 0 || port > 65535)
        throw std::invalid_argument("Invalid port");

    if (document[0] != '/')
        m_document = '/' + document;


    m_domain = domain;
    m_document = document;
    m_protocol = protocol;
    m_port = port;
}

std::string CHttpUrl::GetURL() const
{
    std::string url;
    if (m_protocol == Protocol::HTTP)
        url = "http://" + m_domain;
    else
        url = "https://" + m_domain;

    if (m_port == 80 || m_port == 443)
        return url + m_document;
    else
        return url + ":" + std::to_string(m_port) + m_document;
}

std::string CHttpUrl::GetDomain() const
{
    return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
    return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
    return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
    return m_port;
}