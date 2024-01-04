#include <iostream>

#include <boost/asio.hpp>

auto main() -> int {
    boost::asio::io_context io{};
    boost::asio::steady_timer t{io, boost::asio::chrono::seconds{5}};

    t.async_wait([](const boost::system::error_code&) {
        std::cout << "Hello, world!" << std::endl;
    });

    io.run();

    return 0;
}
