#include "catch2/catch.hpp"
#include "fmt/format.h"
#include "soci/soci.h"
#include "soci/odbc/soci-odbc.h"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

namespace soci_odbc_test
{

TEST_CASE("should successfully connect with odbc backend")
{
  const auto &connectString{"db=soci_test"}; //// TODO use a valid connection string
  const auto &table{"table1"};
  const soci::backend_factory &backEnd = *soci::factory_odbc();
  soci::session sql(backEnd, connectString);
  CHECK( sql.is_connected() );
  fmt::print("soci database connected successfully with odbc backend\n");
}

} // soci_odbc
