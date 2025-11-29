#include "./../src/logger.hpp"

void test_trace(dumb::Logger &logger)
{
    logger.trace("Trace log message\n");
}

int main()
{
    dumb::Logger logger;
    test_trace(logger);
    return 0;
}
