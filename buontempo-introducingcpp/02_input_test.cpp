#include <tuple>
#include <gtest/gtest.h>
#include <cstdio>
#include <memory>
#include <string>
#include <array>

// Helper remains the same - it executes the command in the shell
std::string capture_subprocess_output(const std::string &cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    auto deleter = [](FILE *f)
    { pclose(f); };
    std::unique_ptr<FILE, decltype(deleter)> pipe(popen(cmd.c_str(), "r"), deleter);

    if (!pipe)
        throw std::runtime_error("popen() failed.");
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    return result;
}

// Updated tuple: <shell_command, friendly_name, expected_output>
using InputTestSuite = ::testing::TestWithParam<std::tuple<const char *, const char *, const char *>>;

TEST_P(InputTestSuite, ValidatesInputOutput)
{
    const auto &[cmd, friendly_name, expected] = GetParam();
    std::string output = capture_subprocess_output(cmd);

    // Check if the expected string exists in the captured output
    EXPECT_NE(output.find(expected), std::string::npos)
        << "Test '" << friendly_name << "' failed. Output: " << output;
}

INSTANTIATE_TEST_SUITE_P(
    InputTests,
    InputTestSuite,
    ::testing::Values(
        // We use 'echo' to pipe input into your binary
        std::make_tuple("echo 42 | ./02_input", "Valid_Input_42", "You entered: 42"),
        std::make_tuple("echo -5 | ./02_input", "Valid_Input_Negative", "You entered: -5")),
    [](const ::testing::TestParamInfo<InputTestSuite::ParamType> &test_info)
    {
        return std::get<1>(test_info.param);
    });