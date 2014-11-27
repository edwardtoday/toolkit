#include "stdafx.h"
#include "logging.h"

#ifndef LOG_FILE_NAME
#define LOG_FILE_NAME "output"
#endif  // LOG_FILE_NAME

void InitLog(int shell_verbose, int log_verbose) {
  namespace expressions = boost::log::expressions;
  namespace sinks = boost::log::sinks;
  namespace keywords = boost::log::keywords;
  namespace trivial = boost::log::trivial;
  namespace attributes = boost::log::attributes;
  boost::shared_ptr<boost::log::core> log_core_ = boost::log::core::get();
#ifdef LOG_TO_FILE
  // init sink1
  typedef sinks::synchronous_sink<sinks::text_file_backend> TextSink;
  boost::shared_ptr<sinks::text_file_backend> backend1 =
    boost::make_shared<sinks::text_file_backend>(
      // log filename pattern
      keywords::file_name = std::string(LOG_FILE_NAME) +
                            "_%Y-%m-%d_%H-%M-%S.%N.log",
      // rotate log when reaching 16MiB
      keywords::rotation_size = 16 * 1024 * 1024,
      // or at midnight
      keywords::time_based_rotation =
        sinks::file::rotation_at_time_point(0, 0, 0),
      // keep at least 3GiB free space
      keywords::min_free_space = 3 * 1024 * 1024);
  backend1->auto_flush(true);
  boost::shared_ptr<TextSink> sink1(new TextSink(backend1));
  sink1->set_formatter(
    expressions::format("%1%\t%2%:\t%3%")
    % expressions::format_date_time<boost::posix_time::ptime>("TimeStamp",
        "%Y-%m-%d %H:%M:%S.%f")
    % expressions::attr<trivial::severity_level>("Severity")
    % expressions::smessage
    //expressions::format("%1%\t%2%\t%3%\t%4%:\n\t%5%")
    //% expressions::format_date_time<boost::posix_time::ptime>("TimeStamp",
    //    "%Y-%m-%d %H:%M:%S")
    //% expressions::attr<trivial::severity_level>("Severity")
    //% expressions::attr<attributes::current_thread_id::value_type>("ThreadID")
    //% expressions::format_named_scope("Scopes",
    //                                  boost::log::keywords::format = "%n (%f:%l)",
    //                                  boost::log::keywords::iteration = expressions::forward,
    //                                  boost::log::keywords::depth = 2)
    //% expressions::smessage
  );

  if (log_verbose > 0) {
    sink1->set_filter(trivial::severity >= log_verbose);
  }

  log_core_->add_sink(sink1);
#endif
  // init sink2
  typedef sinks::synchronous_sink<sinks::text_ostream_backend> StreamSink;
  boost::shared_ptr<StreamSink> sink2 = boost::make_shared<StreamSink>();
  sink2->set_formatter(
    expressions::format("%1%: %2%")
    % expressions::format_date_time<boost::posix_time::ptime>("TimeStamp",
        "%H:%M:%S")
    % expressions::smessage
  );
  boost::shared_ptr<std::ostream> stream(&std::clog, boost::empty_deleter());
  sink2->locked_backend()->add_stream(stream);

  if (shell_verbose > 0) {
    sink2->set_filter(trivial::severity >= shell_verbose);
  }

  log_core_->add_sink(sink2);
  boost::log::add_common_attributes();
  log_core_->add_global_attribute("Scopes", attributes::named_scope());
}

void DeInitLog() {
  boost::log::core::get()->remove_all_sinks();
}
