#include "toml++/toml.hpp"
#include <string>
#include <rfl.hpp>
#include <rfl/toml.hpp>
#include <Poco/File.h>
#include <Poco/FileStream.h>

using namespace std;
struct ServerBlock {
    string httpEndpoint;
};
struct TomlConfig {
    ServerBlock sb;
};
void ParseConfig(string path) {
    Poco::FileInputStream fis(path); // 替换为实际文件路径
    std::string content((std::istreambuf_iterator<char>(fis)), std::istreambuf_iterator<char>());
    cout << content << std::endl;
    auto tConfig = rfl::toml::read<TomlConfig>(content).value();
    cout << tConfig.sb.httpEndpoint << endl;
}