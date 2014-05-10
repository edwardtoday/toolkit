#include "stdafx.h"
#include "logging.h"

void Bar() {
  boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level>& lg
    =
      my_logger::get();
  // Mark the scope of the function foo
  BOOST_LOG_FUNCTION();
  int x = 0;
  BOOST_LOG_SEV(lg, boost::log::trivial::info) << "Bar(): x=" << x;
}

void Error() {
  BOOST_LOG_FUNCTION();
  // Attach a copy of the current scope stack to the exception
  throw boost::enable_error_info(std::range_error("test exception")) <<
      boost::log::current_scope();
}


void Foo(int n) {
  boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level>& lg
    =
      my_logger::get();
  // Mark the scope of the function foo
  BOOST_LOG_FUNCTION();

  switch (n) {
  case 0: {
    // Mark the current scope
    BOOST_LOG_NAMED_SCOPE("case 0");
    BOOST_LOG_SEV(lg, boost::log::trivial::trace) << "Some log record";

    try {
      Error();
    } catch (std::range_error& e) {
      // Acquire the scope stack from the exception object
      BOOST_LOG_SEV(lg, boost::log::trivial::trace) << "Error call failed: " <<
          e.what()
          << ", scopes stack:\n"
          << *boost::get_error_info<boost::log::current_scope_info>(e);
    }
  }
  break;

  case 1: {
    // Mark the current scope
    BOOST_LOG_NAMED_SCOPE("case 1");
    BOOST_LOG_SEV(lg, boost::log::trivial::trace) << "Some log record";
    Bar(); // call some function
  }
  break;

  default: {
    // Mark the current scope
    BOOST_LOG_NAMED_SCOPE("default");
    BOOST_LOG(lg) << "Some log record";
    Bar(); // call some function
  }
  break;
  }
}

int main(int, char* []) {
  InitLog();
  BOOST_LOG_FUNCTION();
  boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level>& lg
    = my_logger::get();
  BOOST_LOG_SEV(lg, boost::log::trivial::trace) << "A trace severity message";
  BOOST_LOG_SEV(lg, boost::log::trivial::debug) << "A debug severity message";
  BOOST_LOG_SEV(lg, boost::log::trivial::info) <<
      "An informational severity message";
  BOOST_LOG_SEV(lg, boost::log::trivial::warning) << "A warning severity message";
  BOOST_LOG_SEV(lg, boost::log::trivial::error) << "An error severity message";
  BOOST_LOG_SEV(lg, boost::log::trivial::fatal) << "A fatal severity message";

  for (int i = 0; i < 10000; ++i) {
    Foo(1);
    Foo(0);
  }

  DeInitLog();
  return 0;
}