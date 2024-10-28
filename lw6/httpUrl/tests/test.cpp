#include "pch.h"
#include <gtest/gtest.h>
#include "../../httpUrl/httpUrl/CHttpUrl.h"

TEST(URLTest, stringURLConstructor)
{
	CHttpUrl url("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetURL(), "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetDomain(), "www.youtube.com");
    EXPECT_EQ(url.GetDocument(), "/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(url.GetPort(), 443);
}

TEST(URLTest, stringWithPortURLConstructor)
{
    CHttpUrl url("https://www.youtube.com:3000/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetURL(), "https://www.youtube.com:3000/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetDomain(), "www.youtube.com");
    EXPECT_EQ(url.GetDocument(), "/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(url.GetPort(), 3000);
}

TEST(URLTest, argumentsURLConstructor)
{
    CHttpUrl url("www.youtube.com", "/watch?v=dQw4w9WgXcQ", Protocol::HTTPS, 443);
    EXPECT_EQ(url.GetURL(), "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetDomain(), "www.youtube.com");
    EXPECT_EQ(url.GetDocument(), "/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(url.GetPort(), 443);
}

TEST(URLTest, argumentsWithoutPortURLConstructor)
{
    CHttpUrl url("www.youtube.com", "/watch?v=dQw4w9WgXcQ", Protocol::HTTPS);
    EXPECT_EQ(url.GetURL(), "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetDomain(), "www.youtube.com");
    EXPECT_EQ(url.GetDocument(), "/watch?v=dQw4w9WgXcQ");
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(url.GetPort(), 443);
}

TEST(URLTest, invalidURLConstructor) {
    EXPECT_THROW({
        CHttpUrl url("htps://www.youtube.com/watch?v=dQw4w9WgXcQ");
        }, CUrlParsingError);

    EXPECT_THROW({
        CHttpUrl url("https//www.youtube.com/watch?v=dQw4w9WgXcQ");
        }, CUrlParsingError);

    EXPECT_THROW({
        CHttpUrl url("https://wwwyoutubecom/watch?v=dQw4w9WgXcQ");
        }, CUrlParsingError);

    EXPECT_THROW({
        CHttpUrl url("https:/www.youtube.com/watch?v=dQw4w9WgXcQ");
        }, CUrlParsingError);

    EXPECT_THROW({
        CHttpUrl url("https:///www.youtube.com/watch?v=dQw4w9WgXcQ");
        }, CUrlParsingError);

    EXPECT_THROW({
        CHttpUrl url("https://www.youtube.com:-5/watch?v=dQw4w9WgXcQ");
        }, CUrlParsingError);

    EXPECT_THROW({
        CHttpUrl url("https://www.youtube.com:65537/watch?v=dQw4w9WgXcQ");
        }, CUrlParsingError);
}