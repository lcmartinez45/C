#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

//I am not yet able to test my code with test cases because I am on a MAC
TEST_CASE("Verify get_gc_content function") {
    REQUIRE(get_gc_content("AGCTATAG") == .375);
    REQUIRE(get_gc_content("CGCTATAG") == .50);
}

TEST_CASE("Verify get_reverse_string function") {
    REQUIRE(get_reverse_string("AGCTATAG") == ("GATATCGA"));
    REQUIRE(get_reverse_string("CGCTATAG") == ("GATATCGC"));
}

TEST_CASE("Verify get_dna_complement function") {
    REQUIRE(get_dna_complement("AAAACCCGGT") == ("ACCGGGTTTT"));
    REQUIRE(get_dna_complement("CCCGGAAAAT") == ("ATTTTCCGGG"));
}