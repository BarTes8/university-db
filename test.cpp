#include <iostream>
#include <string>

int validatePersonalIdentityNumber(std::string personalIdentityNumber);

static int failed = 0;
static int total = 0;

void test(std::string input, bool expected) {
    auto result = validatePersonalIdentityNumber(input);
    if (result != expected) {
        failed++;
        std::cerr << "FAILED: \"" << input << "\" -> expected: " << expected << ", got " << result << '\n';
    }
    total++;
}

int main() {
    test("50032511883", 1);
    test("72082968248", 1);
    test("", 0);
    test("85051033249", 1);
    test("95062887786", 1);
    test("49072852861", 1);
    test("66010262636", 1);
    test("50041526463", 1);
    test("78081951876", 1);
    test("04283145461", 1);
    test("83081899446", 1);
    test("002147483647", 2'147'483'647);
    test("0021474836471", 2'147'483'647);
    test("2147483647123", 2'147'483'647);
    test("2147483647000", 2'147'483'647);
    test("2147483648", 214'748'364);
    test("2147483640234525", 2'147'483'640);
    test("9876543210", 987'654'321);
    test("098765432109", 987'654'321);
    test("00000000000000000000000", 0);
    test("000000000000000000000001", 1);
    test("00000000000000000000000000000000000000098765432109", 987'654'321);
    test(" 123", 0);

    std::cout << "------------\n";
    std::cout << failed << "/" << total << " failed\n";
    std::cout << total - failed << "/" << total << " passed\n";

    if (failed == 0) {
        return 0;
    }
    return -1;
}