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
    test("25115003883", 0);
    test("72082968248", 1);
    test("29687208248", 0);
    test("", 0);
    test("85051033249", 1);
    test("10338505248", 0);
    test("95062887786", 1);
    test("28879506786", 0);
    test("49072852861", 1);
    test("28524907861", 0);
    test("66010262636", 1);
    test("02626601636", 0);
    test("50041526463", 1);
    test("15265004463", 0);
    test("78081951876", 1);
    test("19517808876", 0);
    test("04283145461", 1);
    test("31450428461", 0);
    test("83081899446", 1);
    test("18998308446", 0);
    test("0021474836", 0);
    test("214748364714", 0);
    test("imagination", 0);
    
    std::cout << "------------\n";
    std::cout << failed << "/" << total << " failed\n";
    std::cout << total - failed << "/" << total << " passed\n";

    if (failed == 0) {
        return 0;
    }
    return -1;
}