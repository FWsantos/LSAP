#include <string>

class Tests
{
private:
    inline static const std::string file_path = "..\\..\\file_inputs\\example_2.txt";

public:
    static void test_basic_preprocessing();
    static void test_read_file();
    static void set_test();
    static void hungarian();
};