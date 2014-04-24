#include "stdafx.h"
#include "logging.h"

#ifndef LOG_FILE_NAME
#define LOG_FILE_NAME "output"
#endif  // LOG_FILE_NAME

void InitLog() {
  boost::shared_ptr<logging::core> core = logging::core::get();
  // init sink1
  typedef sinks::synchronous_sink<sinks::text_file_backend> TextSink;
  boost::shared_ptr<sinks::text_file_backend> backend1 =
    boost::make_shared<sinks::text_file_backend>(
      // log filename pattern
      keywords::file_name = std::string(LOG_FILE_NAME) + "_%Y-%m-%d_%H-%M-%S.%N.log",
      // rotate log when reaching 4MiB
      keywords::rotation_size = 4 * 1024 * 1024,
      // or at midnight
      keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
      // keep at least 3GiB free space
      keywords::min_free_space = 3 * 1024 * 1024);
  backend1->auto_flush(true);
  boost::shared_ptr<TextSink> sink1(new TextSink(backend1));
  sink1->set_formatter(
    expr::format("(%1%)(%2%)(%3%)(%4%)<%5%>:\n\t> %6%")
    % expr::attr<unsigned int>("LineID")
    % expr::format_date_time< boost::posix_time::ptime >("TimeStamp",
        "%Y-%m-%d %H:%M:%S")
    % expr::attr<logging::trivial::severity_level>("Severity")
    % expr::attr<attrs::current_thread_id::value_type>("ThreadID")
    % expr::format_named_scope("Scopes",
                               boost::log::keywords::format = "%n (%f:%l)",
                               boost::log::keywords::iteration = expr::forward,
                               boost::log::keywords::depth = 2)
    % expr::smessage
  );
  sink1->set_filter(logging::trivial::severity >= logging::trivial::trace);
  core->add_sink(sink1);
  // init sink2
  typedef sinks::synchronous_sink< sinks::text_ostream_backend > StreamSink;
  boost::shared_ptr< StreamSink > sink2 = boost::make_shared< StreamSink >();
  sink2->set_formatter(
    expr::format("(%1%): %2%")
    % expr::format_date_time< boost::posix_time::ptime >("TimeStamp",
        "%Y-%m-%d %H:%M:%S")
    % expr::smessage
  );
  boost::shared_ptr< std::ostream > stream(&std::clog, boost::empty_deleter());
  sink2->locked_backend()->add_stream(stream);
  sink2->set_filter(logging::trivial::severity >= logging::trivial::info);
  core->add_sink(sink2);
  logging::add_common_attributes();
  core->add_global_attribute("Scopes", attrs::named_scope());
}

void DeInitLog() {
  boost::log::core::get()->remove_all_sinks();
}