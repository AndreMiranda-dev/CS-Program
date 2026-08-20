// Encryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <filesystem>

/// <summary>
/// encrypt or decrypt a source string using the provided key
/// </summary>
std::string encrypt_decrypt(const std::string& source, const std::string& key)
{
    const auto key_length = key.length();
    const auto source_length = source.length();

    assert(key_length > 0);
    assert(source_length > 0);

    std::string output = source;

    for (size_t i = 0; i < source_length; ++i)
    {
        const char key_char = key[i % key_length];
        output[i] = source[i] ^ key_char;
    }

    assert(output.length() == source_length);
    return output;
}

/// <summary>
/// read the entire contents of a text file into a single string
/// </summary>
std::string read_file(const std::string& filename)
{
    std::ifstream in_file(filename);
    if (!in_file)
    {
        std::cerr << "Error: Unable to open input file: " << filename << std::endl;
        return "";
    }

    std::ostringstream buffer;
    buffer << in_file.rdbuf();
    return buffer.str();
}

/// <summary>
/// extract the student name from the first line of the data string
/// </summary>
std::string get_student_name(const std::string& string_data)
{
    size_t pos = string_data.find('\n');
    if (pos != std::string::npos)
        return string_data.substr(0, pos);

    return string_data;
}

/// <summary>
/// save data to a file in the specified format
/// </summary>
void save_data_file(const std::string& filename,
    const std::string& student_name,
    const std::string& key,
    const std::string& data)
{
    std::ofstream out_file(filename);
    if (!out_file)
    {
        std::cerr << "Error: Unable to open output file: " << filename << std::endl;
        return;
    }

    std::time_t t = std::time(nullptr);
    std::tm local_tm{};
#ifdef _WIN32
    localtime_s(&local_tm, &t);
#else
    local_tm = *std::localtime(&t);
#endif

    std::ostringstream date_stream;
    date_stream << std::put_time(&local_tm, "%Y-%m-%d");
    const std::string timestamp = date_stream.str();

    out_file << student_name << '\n';
    out_file << timestamp << '\n';
    out_file << key << '\n';
    out_file << data;
    out_file.flush();
}

int main()
{
    std::cout << "Encryption Decryption Test!" << std::endl;

    // Print the actual working directory
    std::cout << "Working directory: "
        << std::filesystem::current_path()
        << std::endl << std::endl;

    const std::string file_name = "inputdatafile.txt";
    const std::string encrypted_file_name = "encrypteddatafile.txt";
    const std::string decrypted_file_name = "decrypteddatafile.txt";
    const std::string key = "password";

    const std::string source_string = read_file(file_name);

    if (source_string.empty())
    {
        std::cerr << "No data read from input file. Exiting." << std::endl;
        return 1;
    }

    const std::string student_name = get_student_name(source_string);
    const std::string encrypted_string = encrypt_decrypt(source_string, key);
    save_data_file(encrypted_file_name, student_name, key, encrypted_string);

    const std::string decrypted_string = encrypt_decrypt(encrypted_string, key);
    save_data_file(decrypted_file_name, student_name, key, decrypted_string);

    std::cout << "Read File: " << file_name
        << " - Encrypted To: " << encrypted_file_name
        << " - Decrypted To: " << decrypted_file_name << std::endl;

    return 0;
}
