#include "stdafx.h"
#include "logging.h"

#ifndef LOG_FILE_NAME
#define LOG_FILE_NAME "output"
#endif  // LOG_FILE_NAME

void InitLog() {
  boost::shared_ptr<boost::log::core> core = boost::log::core::get();
  // init sink1
  typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_file_backend>
  TextSink;
  boost::shared_ptr<boost::log::sinks::text_file_backend> backend1 =
    boost::make_shared<boost::log::sinks::text_file_backend>(
      // log filename pattern
      boost::log::keywords::file_name = std::string(LOG_FILE_NAME) +
                                        "_%Y-%m-%d_%H-%M-%S.%N.log",
      // rotate log when reaching 4MiB
      boost::log::keywords::rotation_size = 4 * 1024 * 1024,
      // or at midnight
      boost::log::keywords::time_based_rotation =
        boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
      // keep at least 3GiB free space
      boost::log::keywords::min_free_space = 3 * 1024 * 1024);
  backend1->auto_flush(true);
  boost::shared_ptr<TextSink> sink1(new TextSink(backend1));
  sink1->set_formatter(
    boost::log::expressions::format("(%1%)(%2%)(%3%)(%4%)<%5%>:\n\t> %6%")
    % boost::log::expressions::attr<unsigned int>("LineID")
    % boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp",
        "%Y-%m-%d %H:%M:%S")
    % boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity")
    % boost::log::expressions::attr<boost::log::attributes::current_thread_id::value_type>("ThreadID")
    % boost::log::expressions::format_named_scope("Scopes",
        boost::log::keywords::format = "%n (%f:%l)",
        boost::log::keywords::iteration = boost::log::expressions::forward,
        boost::log::keywords::depth = 2)
    % boost::log::expressions::smessage
  );
  sink1->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);
  core->add_sink(sink1);
  // init sink2
  typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_ostream_backend>
  StreamSink;
  boost::shared_ptr<StreamSink> sink2 = boost::make_shared<StreamSink>();
  sink2->set_formatter(
    boost::log::expressions::format("(%1%): %2%")
    % boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp",
        "%Y-%m-%d %H:%M:%S")
    % boost::log::expressions::smessage
  );
  boost::shared_ptr<std::ostream> stream(&std::clog, boost::empty_deleter());
  sink2->locked_backend()->add_stream(stream);
  sink2->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
  core->add_sink(sink2);
  boost::log::add_common_attributes();
  core->add_global_attribute("Scopes", boost::log::attributes::named_scope());
}

void DeInitLog() {
  boost::log::core::get()->remove_all_sinks();
}
