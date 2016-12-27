#include "utils.hpp"

#include <amy/connector.hpp>

#include <boost/format.hpp>

#include <asio/io_service.hpp>
#include <iostream>
#include <system_error>

global_options opts;

int main(int argc, char* argv[]) try {
    parse_command_line_options(argc, argv);

    asio::io_service io_service;
    amy::connector connector(io_service);

    connector.connect(opts.tcp_endpoint(),
                      opts.auth_info(),
                      opts.schema,
                      amy::default_flags);

    std::cout << "Connected." << std::endl;

    return 0;
} catch (std::system_error const& e) {
    std::cerr
        << boost::format("System error: %1%: %2%")
           % e.code().value() % e.what()
        << std::endl;
} catch (std::exception const& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
}

// vim:ft=cpp sw=4 ts=4 tw=80 et
