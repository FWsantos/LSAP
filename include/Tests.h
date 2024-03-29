#include <string>

class Tests
{
private:
    // Windows
    // inline static const std::string file_path = "..\\file_inputs\\example_1.txt";

    // Linux
    inline static const std::string file_path = "../file_inputs/example_2.txt";

public:
    static void test_basic_preprocessing();
    static void test_generate_phi();
    static void test_read_file();
    static void test_alternate_k();
    static void set_test();
    static void hungarian_n4();
    static void hungarian_n3();

    // Test suite
    static void assign_files();
};