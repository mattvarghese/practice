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

TEST(HelloWorldTestSuite, ValidatesConsoleOutput)
{
    // Execute your compiled main program binary from the build workspace
    // './' tells the terminal engine to look inside the active execution directory
    std::string output = capture_subprocess_output("./01_hello_world");

    // std::println automatically appends a trailing newline '\n' to its output
    std::string expected = "Hello, world!\n";

    EXPECT_EQ(output, expected)
        << "The application's stdout payload stream did not match expectations.";
}