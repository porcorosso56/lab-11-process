#pragma once
#include <async++.h>
#include <boost/process.hpp>
#include <boost/process/extend.hpp>
#include <boost/program_options.hpp>
#include <vector>
#include <iostream>
#include <signal.h>
#include <string>
#include <thread>
#include <chrono>

using namespace boost::asio;
using namespace boost::process;
using namespace boost::process::extend;
using namespace boost::program_options;

void build(int argc, char* argv[]);

void create_child(const std::string& command, const time_t& period);

void create_child(const std::string& command, const time_t& period, int& res);

void check_time(child& process, const time_t& period);

time_t time_now();
