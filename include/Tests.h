#include <string>

class Tests
{
private:
    inline static const std::string file_path = ".\\file_inputs\\example_1.txt";

public:
    static void test_basic_preprocessing();
    static void test_generate_phi();
    static void test_read_file();
    static void set_test();
    static void hungarian();
    static void hungarian_v2();
};