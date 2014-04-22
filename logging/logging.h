#define _CRT_SECURE_NO_WARNINGS

#ifndef QINGPEI_TOOLKIT_LOGGING_H_
#define QINGPEI_TOOLKIT_LOGGING_H_
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp>

#include <boost/log/core.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/exception.hpp>
#include <boost/exception/all.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <fstream>

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

void InitLog();
void DeInitLog();

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger,
                                       src::severity_logger_mt<logging::trivial::severity_level>)
#endif  // QINGPEI_TOOLKIT_LOGGING_H_