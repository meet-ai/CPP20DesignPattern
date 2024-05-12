add_rules("mode.debug", "mode.release")
add_cxxflags("-std=c++20")
--set_languages("c++20")
set_policy("build.c++.modules", true) -- 全局，可以改成只有target

add_repositories("local-repo build")
add_requires("reflect-cpp")

-- 添加链接选项

--add_ldflags("-isysroot /opt/homebrew/opt/llvm/lib")
--add_cxxflags("-I/opt/homebrew/opt/llvm/include")

set_policy("build.c++.modules", true)
add_rules("mode.debug", "mode.release")
add_requires("conan::poco/1.13.3",{alias = "poco",configs = {settings = "compiler.cppstd=20"}})


add_requires("fmt")
add_requires("spdlog")
add_requires("toml++")




target("strutil")
    set_kind("moduleonly")
    add_packages("poco")
    add_files("modules/strutil.ixx")

--target("crtp")
--    add_packages("spdlog")
--    set_kind("binary")
--    add_files("src/crtp/*.cpp")
--
--target("mixin")
--    add_packages("spdlog")
--    set_kind("binary")
--    add_files("src/mixin/*.cpp")
--
--target("concept")
--    add_packages("spdlog")
--    set_kind("binary")
--    add_files("src/concept/*.cpp")

target("di")
    add_deps("strutil")
    add_packages("spdlog")
    add_packages("poco")
    add_packages("boost_di")
    add_packages("toml++")
    add_packages("cista")
    add_packages("reflect-cpp")
    set_kind("binary")
    add_includedirs("src")
    add_files("src/config/*.cpp")
    add_files("src/di/*.cpp")


--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

