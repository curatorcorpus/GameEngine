#include <hrs_timer.hpp>

HRSTimer::HRSTimer()
{

}

HRSTimer::HRSTimer(int max_ct)
{
    this->d_avg = 0;
    this->i_avg = 0;
    this->counter = 0;
}

HRSTimer::~HRSTimer()
{

}

void HRSTimer::init()
{
    this->start = std::chrono::high_resolution_clock::now();
}

void HRSTimer::end()
{
    this->finish = std::chrono::high_resolution_clock::now();
}

void HRSTimer::print_nano()
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
    std::cerr << time << " nanoseconds" << std::endl;
}

void HRSTimer::print_nano(std::string prefix_msg)
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
    std::cerr << prefix_msg << " " << time << " nanoseconds" << std::endl;
}

void HRSTimer::print_micro()
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
    std::cerr << time << " microseconds" << std::endl;
}

void HRSTimer::print_micro(std::string prefix_msg)
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
    std::cerr << prefix_msg << " " << time << " microseconds" << std::endl;
}

void HRSTimer::print_milli()
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
    std::cerr << time << " milliseconds" << std::endl;
}

void HRSTimer::print_milli(std::string prefix_msg)
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
    std::cerr << prefix_msg << " " << time << " milliseconds" << std::endl;
}

void HRSTimer::print_secs()
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
    std::cerr << time << " seconds" << std::endl;
}

void HRSTimer::print_secs(std::string prefix_msg)
{
    auto diff = this->finish - this->start;
    auto time = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
    std::cerr << prefix_msg << " " << time << " seconds" << std::endl;
}