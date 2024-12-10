#ifndef CORE_HPP_
#define CORE_HPP_

#include "ADBManager.hpp"

#include <string>
#include <vector>

namespace core {
    class Core {
        public:
            Core();
            ~Core();

            std::vector<std::string> getDevices();

        protected:
        private:
        std::vector<std::string> _devices;
    };
};

#endif /* !CORE_HPP_ */