#include <functional>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace {
    auto print(const boost::system::error_code&, boost::asio::steady_timer& t, int& count) -> void {
        if (count >= 5) {
            return;
        }

        std::cout << count << std::endl;
        ++count;

        // Delay expiry by 1 second
        t.expires_at(t.expiry() + boost::asio::chrono::seconds{1});

        // Start new async wait on the timer
        t.async_wait(boost::bind(
            print,
            boost::asio::placeholders::error,
            std::ref(t),
            std::ref(count)));
    }
}

auto main() -> int {
    boost::asio::io_context io{};
    boost::asio::steady_timer t{io, boost::asio::chrono::seconds{1}};
    int count{0};

    t.async_wait(boost::bind(
        print,
        boost::asio::placeholders::error,
        std::ref(t),
        std::ref(count)));

    io.run();

    std::cout << "Final count is " << count << std::endl;

    return 0;
}
