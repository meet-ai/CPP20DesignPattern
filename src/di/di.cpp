#include<spdlog/spdlog.h>
#include <CLI/CLI.hpp>
import strutil;
import config;

//namespace di = boost::di;

std::string filename = "conf/config.toml";


int main(int argc, char**argv) {
    CLI::App app{"cpp template"};
    argv = app.ensure_utf8(argv);
    app.add_option("-c,--conf", filename, "A help string");
    CLI11_PARSE(app, argc, argv);

    globalConfig = ParseConfig(filename);
    auto vectors = split("hello world", " ");
    spdlog::info("vectors:{}",(*vectors)[0]);
    auto jstr = join(*vectors, "++");
    spdlog::info("jstr:{}",jstr);
    auto newstr = replace(jstr,"++","--");
    spdlog::info("jstr:{}",newstr);
}
