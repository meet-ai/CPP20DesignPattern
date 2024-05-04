#include "config/config.h"
#include<spdlog/spdlog.h>
import strutil;

//namespace di = boost::di;

int main() {
    ParseConfig("/Users/nolan/etc/config.toml");
    auto vectors = split("hello world", " ");
    spdlog::info("vectors:{}",(*vectors)[0]);
    auto jstr = join(*vectors, "++");
    spdlog::info("jstr:{}",jstr);

    auto newstr = replace(jstr,"++","--");
    spdlog::info("jstr:{}",newstr);
}