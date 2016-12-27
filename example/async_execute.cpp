#include "utils.hpp"

#include <amy/connector.hpp>
#include <amy/execute.hpp>
#include <amy/placeholders.hpp>

#include <boost/bind.hpp>
#include <boost/format.hpp>

#include <asio/io_service.hpp>
#include <iostream>
#include <system_error>

global_options opts;

void handle_execute(std::error_code const& ec,
                    uint64_t affected_rows,
                    amy::connector& connector)
{
    check_error(ec);
    std::cout << "Affected rows: " << affected_rows << std::endl;
    return;
}

void handle_connect(std::error_code const& ec, amy::connector& connector) {
    check_error(ec);

    // Executes an arbitrary SQL statement read from stdin.
    amy::async_execute(connector,
                       read_from_stdin(),
                       boost::bind(handle_execute,
                                   amy::placeholders::error,
                                   amy::placeholders::affected_rows,
                                   boost::ref(connector)));
}

int main(int argc, char* argv[]) {
    parse_command_line_options(argc, argv);

    asio::io_service io_service;
    amy::connector connector(io_service);

    connector.async_connect(opts.tcp_endpoint(),
                            opts.auth_info(),
                            opts.schema,
                            amy::default_flags,
                            boost::bind(handle_connect,
                                        amy::placeholders::error,
                                        boost::ref(connector)));

    io_service.run();

    return 0;
}

// vim:ft=cpp sw=4 ts=4 tw=80 et
