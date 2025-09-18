#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <string>
#include <vector>

TEST_CASE("Splitting a string by a separator string", "[Split]"){
    REQUIRE( Split("one,two,three", ",") == std::vector<std::string>{"one", "two", "three"} );
    REQUIRE( Split(",start,middle,end", ",") == std::vector<std::string>{"","start","middle","end"} );
    REQUIRE( Split("end1,end2,", ",") == std::vector<std::string>{"end1","end2",""} );
    REQUIRE( Split("apple--banana--cherry", "--") == std::vector<std::string>{"apple","banana","cherry"} );
    REQUIRE( Split("nosplit", ",") == std::vector<std::string>{"nosplit"} );
    REQUIRE( Split("a,,b,c", ",") == std::vector<std::string>{"a","","b","c"} );
}


TEST_CASE("removing all occurences of s2 from s1", "[RemoveAllSubstrings]"){
    REQUIRE(RemoveAllSubstrings("hello world", "world") == "hello ");
    REQUIRE(RemoveAllSubstrings("ababab", "ab") == "");
    REQUIRE(RemoveAllSubstrings("abcdef", "xyz") == "abcdef");
    REQUIRE(RemoveAllSubstrings("banana", "a") == "bnn");
    REQUIRE(RemoveAllSubstrings("test", "test") == "");
    REQUIRE(RemoveAllSubstrings("hello", "") == "hello");
}


TEST_CASE("Removing first substring", "[RemoveFirstSubstring]"){
    REQUIRE(RemoveFirstSubstring("Hello, world!", "world") == "Hello, !");
    REQUIRE(RemoveFirstSubstring("abc123abc123", "abc") == "123abc123");
    REQUIRE(RemoveFirstSubstring("abcdef", "xyz") == "abcdef");
    REQUIRE(RemoveFirstSubstring("foobar", "foo") == "bar");
    REQUIRE(RemoveFirstSubstring("testing123", "123") == "testing");
    REQUIRE(RemoveFirstSubstring("repeat", "repeat") == "");
}


TEST_CASE("Joins all strings in a vector together, using the glue string in between them", "[Join]"){
    REQUIRE(Join({}, ",") == "");
    REQUIRE(Join({"hello"}, ",") == "hello");
    REQUIRE(Join({"a", "b", "c"}, ",") == "a,b,c");
    REQUIRE(Join({"red", "green", "blue"}, " - ") == "red - green - blue");
    REQUIRE(Join({"foo", "", "bar"}, "|") == "foo||bar");
    REQUIRE(Join({"1", "2", "3"}, "") == "123");
}

TEST_CASE("Remove shared elements between vectors a and b from a.", "[MatchVectors]"){
    REQUIRE(MatchVectors(std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6}) == std::vector<int>{1, 2, 3});
    REQUIRE(MatchVectors(std::vector<int>{1, 2, 3}, std::vector<int>{1, 2, 3}) == std::vector<int>{});
    REQUIRE(MatchVectors(std::vector<int>{1, 2, 3, 4}, std::vector<int>{2, 4}) == std::vector<int>{1, 3});
    REQUIRE(MatchVectors(std::vector<int>{1, 2, 3}, std::vector<int>{4, 5}) == std::vector<int>{1, 2, 3});
    REQUIRE(MatchVectors(std::vector<int>{1, 2, 2, 3, 4}, std::vector<int>{2}) == std::vector<int>{1, 3, 4});
    REQUIRE(MatchVectors(std::vector<int>{}, std::vector<int>{1, 2, 3}) == std::vector<int>{});
}


TEST_CASE("divides an input integer by 2 until it is impossible to do so, then returns the final number.", "[RemoveTwos]"){
    REQUIRE(RemoveTwos(7) == 7);
    REQUIRE(RemoveTwos(16) == 1);  
    REQUIRE(RemoveTwos(12) == 3); 
    REQUIRE(RemoveTwos(1) == 1);
    REQUIRE(RemoveTwos(0) == 0); 
    REQUIRE(RemoveTwos(1024 * 15) == 15);  
}

TEST_CASE("takes a vector of integers and removes all elements evenly divisible by the passed in int", "[MultiplesFilter]"){
    REQUIRE(MultiplesFilter({1,2,3,4,5,6}, 2) == std::vector<int>{1,3,5});
    REQUIRE(MultiplesFilter({3,6,9,10,11}, 3) == std::vector<int>{10,11});
    REQUIRE(MultiplesFilter({1,5,7}, 2) == std::vector<int>{1,5,7});
    REQUIRE(MultiplesFilter({4,8,12}, 4) == std::vector<int>{});
    REQUIRE(MultiplesFilter({0,1,2,3}, 2) == std::vector<int>{1,3}); // 0 is divisible by anything
    REQUIRE(MultiplesFilter({-4,-3,-2,0,1,2}, -2) == std::vector<int>{-3,1});
}
