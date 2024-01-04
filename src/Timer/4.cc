#include <functional>
#include <iostream>

#include <boost/asio.hpp>

namespace {
    class Printer {
    public:
        explicit Printer(boost::asio::io_context& io) : timer{io, boost::asio::chrono::seconds{1}} {
            this->timer.async_wait(std::bind(&Printer::print, this));
        }

        ~Printer() {
            std::cout << "Final count is " << this->count << std::endl;
        }

        auto print() -> void {
            if (this->count >= 5) {
                return;
            }

            std::cout << this->count << std::endl;

            ++this->count;

            this->timer.expires_at(this->timer.expiry() + boost::asio::chrono::seconds{1});

            this->timer.async_wait(std::bind(&Printer::print, this));
        }

    private:
        boost::asio::steady_timer timer;
        int count{0};
    };
}

auto main() -> int {
    boost::asio::io_context io{};
    Printer p{io};

    io.run();

    return 0;
}
