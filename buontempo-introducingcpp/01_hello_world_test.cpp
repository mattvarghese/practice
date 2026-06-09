#include <gtest/gtest.h>
#include <cstdio>
#include <memory>
#include <string>
#include <array>

// Helper function to execute a system command and capture its stdout stream
std::string capture_subprocess_output(const std::string &cmd)
{
    std::array<char, 128> buffer;
    std::string result;

    // Open a readable pipe to the executed binary command
    auto deleter = [](FILE *f)
    { pclose(f); };
    std::unique_ptr<FILE, decltype(deleter)> pipe(popen(cmd.c_str(), "r"), deleter);

    if (!pipe)
    {
        throw std::runtime_error("popen() failed to execute target binary.");
    }

    // Read the stream block-by-block until EOF is reached
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }

    return result;
}

// 1. Declare the type alias using a std::tuple holding: <executable_path, friendly_name>
using HelloWorldTestSuite = ::testing::TestWithParam<std::tuple<const char *, const char *>>;

// 2. The Parameterized Test Template
TEST_P(HelloWorldTestSuite, ValidatesConsoleOutput)
{
    // Use C++20 structured binding to unpack the tuple elements cleanly
    const auto &[binary_path, friendly_name] = GetParam();

    std::string output = capture_subprocess_output(binary_path);
    std::string expected = "Hello, world!\n";

    EXPECT_EQ(output, expected)
        << "The payload stream from " << friendly_name << " (" << binary_path << ") did not match expectations.";
}

// 3. Define the Iterable Tuple Collection and register it
INSTANTIATE_TEST_SUITE_P(
    AllImplementations,
    HelloWorldTestSuite,
    ::testing::Values(
        std::make_tuple("./01_hello_world", "Modern_Cpp23_Println"),
        std::make_tuple("./01_hello_world_cout", "Classic_Cpp20_Cout")),
    [](const ::testing::TestParamInfo<HelloWorldTestSuite::ParamType> &info)
    {
        // Extract the second element of the tuple (friendly_name) to label the VSCode sidebar entry
        return std::get<1>(info.param);
    });
