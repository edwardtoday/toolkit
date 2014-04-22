#include "logging.h"

void Bar() {
  int x = 0;
}

void Error() {
  BOOST_LOG_FUNCTION();
  // Attach a copy of the current scope stack to the exception
  throw boost::enable_error_info(std::range_error("test exception")) <<
      logging::current_scope();
}


void Foo(int n) {
  src::severity_logger_mt<logging::trivial::severity_level>& lg =
    my_logger::get();
  // Mark the scope of the function foo
  BOOST_LOG_FUNCTION();

  switch (n) {
  case 0: {
    // Mark the current scope
    BOOST_LOG_NAMED_SCOPE("case 0");
    BOOST_LOG_SEV(lg, logging::trivial::trace) << "Some log record";

    try {
      Error();
    } catch (std::range_error& e) {
      // Acquire the scope stack from the exception object
      BOOST_LOG_SEV(lg, logging::trivial::trace) << "Error call failed: " << e.what()
          << ", scopes stack:\n"
          << *boost::get_error_info<logging::current_scope_info>(e);
    }
  }
  break;

  case 1: {
    // Mark the current scope
    BOOST_LOG_NAMED_SCOPE("case 1");
    BOOST_LOG_SEV(lg, logging::trivial::trace) << "Some log record";
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
  src::severity_logger_mt<logging::trivial::severity_level>& lg =
    my_logger::get();
  BOOST_LOG_SEV(lg, logging::trivial::trace) << "A trace severity message";
  BOOST_LOG_SEV(lg, logging::trivial::debug) << "A debug severity message";
  BOOST_LOG_SEV(lg, logging::trivial::info) <<
      "An informational severity message";
  BOOST_LOG_SEV(lg, logging::trivial::warning) << "A warning severity message";
  BOOST_LOG_SEV(lg, logging::trivial::error) << "An error severity message";
  BOOST_LOG_SEV(lg, logging::trivial::fatal) << "A fatal severity message";

  for (int i = 0; i < 10000; ++i) {
    Foo(1);
    Foo(0);
  }

  logging::core::get()->remove_all_sinks();
  return 0;
}