#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vectors.h"
#include <vector>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test get_max_from_vector function") {
	vector<int> numbers{ 3, 8, 1, 99, 1000 };
   REQUIRE(get_max_from_vector(numbers) == 1000);
   numbers = { 15,12,11,99,88 };
    REQUIRE(get_max_from_vector(numbers) == 99);
	numbers={ 150,120,11,990,88888 };
    REQUIRE(get_max_from_vector(numbers) == 88888);
}

TEST_CASE("Test is prime function") {
    REQUIRE(is_prime(2) == true);
    REQUIRE(is_prime(4) == false);
    REQUIRE(is_prime(43) == true);
    REQUIRE(is_prime(44) == false);
}

TEST_CASE("Test vector of primes function") {
    REQUIRE(vector_of_primes(50) == vector<int> {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47} );

    REQUIRE(vector_of_primes(10) == vector<int> {2, 3, 5, 7} );
}

